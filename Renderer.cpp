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
   
using namespace std;

bool Renderer::initResources() {

    // Create a default shape with a default shader and compile it.
    myShape = new Shape();    
    myShape->setShader(new Shader() );    
    if (!myShape->getShader()->compile())
        return false;
    
    return true;
}

void Renderer::drawShape(Shape* shape){
    
    Shader* shader = shape->getShader();
    
    glUseProgram(shader->getProgram());
   
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

    drawShape(myShape);

    /* Display the result */
    SDL_GL_SwapWindow(window);
}

void Renderer::freeResources() {
  glDeleteProgram(myShape->getShader()->getProgram());
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

Renderer::Renderer() {
  
}

Renderer::Renderer(const Renderer& orig) {
}

Renderer::~Renderer() {
}

