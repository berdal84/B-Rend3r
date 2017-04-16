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
#include "Shape.h"

using namespace std;

bool Renderer::initResources() {
    SDL_GL_SetSwapInterval(1/60);

    // Create a default shape with a default shader and compile it.
    Shape* myShape = new Shape();
    Shader* shader = Shader::createShader("./shaders/default");
    myShape->setShader(shader);

    Model* myModel = new Model(myShape);
    myModel->setName("Modele001");
    myModel->setPosition(vec3(-2.0f, 0.f, 0.f));

    model[0]=myModel;

    return true;
}

void Renderer::drawModel(Model* model){
    //cout << "Drawing model :" << model << endl;

    Shape* shape    = model->getShape();
    Transform* matrix  = model->getMatrix();

    bool hasShape   = shape!=nullptr;
    bool hasMatrix  = matrix!=nullptr;

    if ( !hasShape ){
        cerr << "The model " << model << " has no Shape attached." << endl;
    }else if (!hasMatrix){
        cerr << "The model " << model << " has no Matrix attached." << endl;
    }else{
        drawShape(shape, matrix);
    }

}

void Renderer::drawShape(Shape* shape, Transform* matrix){

    Shader* shader          = shape->getShader();
    GLuint shaderProgram    = shader->getProgram();

    glUseProgram(shaderProgram);

    glVertexAttrib2f(glGetAttribLocation(shaderProgram, "position"),  matrix->getPositionX(), matrix->getPositionY() );

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


    Transform* tr = model[0]->getMatrix();
    bool isObjectOffscreen = tr->getPosition().x > 2.0f;
    if(isObjectOffscreen)
    {
        tr->setPosition(vec3(-2.0f, 0.f, 0.f));
    }

    vec3 offset(0.01f, 0.f, 0.f);
    model[0]->translate(offset);

    drawModel(model[0]);

    /* Display the result */
    SDL_GL_SwapWindow(window);
}

void Renderer::freeResources() {
    for(Model* m : model)
        if (m)delete m;
}

void Renderer::mainLoop(SDL_Window* window) {
	while (true) {
		SDL_Event ev;
		while (SDL_PollEvent(&ev)) {
			if (ev.type == SDL_QUIT)
				return;
		}
		this->render(window);
	}
}

Renderer::Renderer(){

}

Renderer::Renderer(const Renderer& orig) {
}

Renderer::~Renderer() {
}

