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

    // Create a new default shader and get the program
    
    Shader myShader;
    myShape = new Shape(&myShader);    
    myShape->getShader()->compile();
    
    const char* attribute_name = "coord2d";
    attribute_coord2d = glGetAttribLocation(myShape->getShader()->getProgram(), attribute_name);
    if (attribute_coord2d == -1) {
            cerr << "Could not bind attribute " << attribute_name << endl;
            return false;
    }
    

    return true;
}

void Renderer::drawShape(Shape* shape){
    
    Shader* shader = shape->getShader();
    
    glUseProgram(shader->getProgram());
   
    glEnableVertexAttribArray(attribute_coord2d );
 
     
    /* Describe our vertices array to OpenGL (it can't guess its format automatically) */
    glVertexAttribPointer(
        attribute_coord2d,      // attribute
        shape->getNumberOfElementsPerVertex(),                      // number of elements per vertex, here (x,y)
        GL_FLOAT,               // the type of each element
        GL_FALSE,               // take our values as-is
        0,                      // no extra data between each position
        shape->getVertices()        // pointer to the C array
    );
   
    

    
    
    /* Push each element in buffer_vertices to the vertex shader */
    glDrawArrays(GL_TRIANGLES, 0, shape->getVerticesCount() * shape->getNumberOfElementsPerVertex());
    
    glDisableVertexAttribArray(attribute_coord2d);
    

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

