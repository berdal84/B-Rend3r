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

    Model* model[20];


    // Create a default shape with a default shader and compile it.
    Shape* myShape = new Shape();
    Shader* shader = Shader::createShader("./shaders/default");
    cout << shader;

    myShape->setShader(shader);


    model[0]    = new Model(myShape);

    model[0]->setPosition(-1.0f, 0.0f);

    return true;
}

void Renderer::drawModel(Model* model){
    Shape* shape    = model->getShape();
    Matrix* matrix  = model->getMatrix();
    if (shape && matrix){
        drawShape(shape, matrix);
    }

}

void Renderer::drawShape(Shape* shape, Matrix* matrix){

    Shader* shader          = shape->getShader();
    cout << shader;
    GLuint shaderProgram    = shader->getProgram();

    glUseProgram(shaderProgram);

    glVertexAttrib2f(glGetAttribLocation(shaderProgram, "position"),  shape->getPositionX(), shape->getPositionY() );

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
    /* Clear the background as white */
    glClearColor(0.5, 0.5,0.5, 1.0);
    glClear(GL_COLOR_BUFFER_BIT);

    /* move and draw the first model */
    model[0]->translate(0.01f, 0);
    drawModel(model[0]);

    /* Display the result */
    SDL_GL_SwapWindow(window);
}

void Renderer::freeResources() {

    for(Model* m : model)
        delete m;
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

