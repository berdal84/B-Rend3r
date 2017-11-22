/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/*
 * File:   Renderer.cpp
 * Author: Bérenger Dalle-Cort <contact@dalle-cort.fr>
 *
 * Created on 28 juin 2016, 20:35
 */

#include "Renderer.h"
#include "Shader.h"
#include "Shape.h"
#include "Model.h"
#include "Transform.h"

using namespace std;

bool Renderer::initResources() {
    // Create a default shape with a default shader and compile it.
    Shape* myShape = Shape::CreatePlane();
    Shader* shader = Shader::CreateVsFs("./shaders/default");
    myShape->setShader(shader);

    Model* myModel = Model::Create(myShape);
    myModel->setName("Modele001");
    myModel->setPosition(vec3(0.0f, 0.0f, 0.0f));

    model.push_back(myModel);

    return true;
}

void Renderer::drawModel(Model* model){
    //cout << "Drawing model :" << model << endl;

    Shape* shape    = model->getShape();
    Transform* tr  = model->getTransform();

    bool hasShape   = shape!=nullptr;
    bool hasTransform  = tr!=nullptr;

    if ( !hasShape ){
        cerr << "The model " << model << " has no Shape attached." << endl;
    }else if (!hasTransform){
        cerr << "The model " << model << " has no Transform attached." << endl;
    }else{
        drawShape(shape, tr);
    }

}

void Renderer::drawShape(Shape* shape, Transform* tr){

    Shader* shader          = shape->getShader();
    GLuint shaderProgram    = shader->getProgram();

    glUseProgram(shaderProgram);

    /* bind world matrix */
    {
    GLint loc = glGetUniformLocation(shaderProgram, "worldMatrix");
        if (loc != -1){
        glUniformMatrix4fv(loc, 1, GL_FALSE, (GLfloat*)&tr->getMatrix()[0][0]);
        }
    }

    /* bind view matrix */
    {
    GLint loc = glGetUniformLocation(shaderProgram, "viewMatrix");
        if (loc != -1){
            mat4 viewMatrix = Transform::Scale(vec3(viewportSize.y / viewportSize.x, 1.0f, 1.0f));
            glUniformMatrix4fv(loc, 1, GL_FALSE, (GLfloat*)&viewMatrix);
        }
    }

    glEnableVertexAttribArray(shader->getAttributeCoord3D() );


    /* Describe our vertices array to OpenGL (it can't guess its format automatically) */
    glVertexAttribPointer(
        shader->getAttributeCoord3D(),      // attribute
        shape->getNumberOfElementsPerVertex(),                      // number of elements per vertex, here (x,y)
        GL_FLOAT,               // the type of each element
        GL_FALSE,               // take our values as-is
        0,                      // no extra data between each position
        shape->getVertices()        // pointer to the C array
    );



    /* Push each element in buffer_vertices to the vertex shader */
    glDrawArrays(GL_TRIANGLES, 0, shape->getVerticesCount() * shape->getNumberOfElementsPerVertex());

    glDisableVertexAttribArray(shader->getAttributeCoord3D());


}

void Renderer::render(SDL_Window* window) {
    cout << "Renderer::render" << endl;

    /* Clear the background as white */
    glClearColor(0.4f, 0.1f ,0.1f, 1.0f);
    glClear(GL_COLOR_BUFFER_BIT);

    drawModel(model[0]);

    /* Display the result */
    SDL_GL_SwapWindow(window);
}

void Renderer::freeResources() {
    for(auto m : model)
        delete m;
}

bool Renderer::update(SDL_Window* window, float _dt) {
    bool quit = false;

    /* Listen events */
	SDL_Event event;
	while (SDL_PollEvent(&event)) {
		switch(event.type){
        case SDL_QUIT:
			quit = true;
            break;
        case SDL_WINDOWEVENT:
            if ( event.window.event == SDL_WINDOWEVENT_RESIZED){
                auto width  = event.window.data1;
                auto height = event.window.data2;
                glViewport(0,0,width, height); 
                viewportSize.x = width;
                viewportSize.y = height;
            }                    
            break;
	   }
    }

    /* Update models */
    Transform* tr = model[0]->getTransform();
    bool isObjectOffscreen = tr->getPosition().x > 2.0f;
    if(isObjectOffscreen)
    {
        tr->setPosition(vec3(-2.0f, 0.f, 0.f));
    }
    
    tr->translate    (vec3( 0.25f * _dt, 0.f, 0.f));
    tr->rotate       (vec3(0.0f, 0.0f, 1.0f * _dt));
    tr->setScale     (vec3(0.5f,0.5f,0.5f));
    tr->updateMatrix ();

    return !quit;
}

Renderer::Renderer(vec2 _viewportSize){
    viewportSize = _viewportSize;
}

Renderer::Renderer(const Renderer& orig) {
}

Renderer::~Renderer() {
}

/*
void PrintEvent(const SDL_Event * event)
{
    if (event->type == SDL_WINDOWEVENT) {
        switch (event->window.event) {
        case SDL_WINDOWEVENT_SHOWN:
            SDL_Log("Window %d shown", event->window.windowID);
            break;
        case SDL_WINDOWEVENT_HIDDEN:
            SDL_Log("Window %d hidden", event->window.windowID);
            break;
        case SDL_WINDOWEVENT_EXPOSED:
            SDL_Log("Window %d exposed", event->window.windowID);
            break;
        case SDL_WINDOWEVENT_MOVED:
            SDL_Log("Window %d moved to %d,%d",
                    event->window.windowID, event->window.data1,
                    event->window.data2);
            break;
        case SDL_WINDOWEVENT_RESIZED:
            SDL_Log("Window %d resized to %dx%d",
                    event->window.windowID, event->window.data1,
                    event->window.data2);
            break;
        case SDL_WINDOWEVENT_SIZE_CHANGED:
            SDL_Log("Window %d size changed to %dx%d",
                    event->window.windowID, event->window.data1,
                    event->window.data2);
            break;
        case SDL_WINDOWEVENT_MINIMIZED:
            SDL_Log("Window %d minimized", event->window.windowID);
            break;
        case SDL_WINDOWEVENT_MAXIMIZED:
            SDL_Log("Window %d maximized", event->window.windowID);
            break;
        case SDL_WINDOWEVENT_RESTORED:
            SDL_Log("Window %d restored", event->window.windowID);
            break;
        case SDL_WINDOWEVENT_ENTER:
            SDL_Log("Mouse entered window %d",
                    event->window.windowID);
            break;
        case SDL_WINDOWEVENT_LEAVE:
            SDL_Log("Mouse left window %d", event->window.windowID);
            break;
        case SDL_WINDOWEVENT_FOCUS_GAINED:
            SDL_Log("Window %d gained keyboard focus",
                    event->window.windowID);
            break;
        case SDL_WINDOWEVENT_FOCUS_LOST:
            SDL_Log("Window %d lost keyboard focus",
                    event->window.windowID);
            break;
        case SDL_WINDOWEVENT_CLOSE:
            SDL_Log("Window %d closed", event->window.windowID);
            break;
#if SDL_VERSION_ATLEAST(2, 0, 5)
        case SDL_WINDOWEVENT_TAKE_FOCUS:
            SDL_Log("Window %d is offered a focus", event->window.windowID);
            break;
        case SDL_WINDOWEVENT_HIT_TEST:
            SDL_Log("Window %d has a special hit test", event->window.windowID);
            break;
#endif
        default:
            SDL_Log("Window %d got unknown event %d",
                    event->window.windowID, event->window.event);
            break;
        }
    }
}

*/