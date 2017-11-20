/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/*
 * File:   main.cpp
 * Author: Bérenger Dalle-Cort
 *
 * Created on 26 juin 2016
 */
#include <cstdlib>
#include <iostream>
#include <GL/glew.h>
#include <SDL2/SDL.h>
#include "src/Renderer.h"

int main(int argc, char* argv[]) {

	/* SDL-related initialising functions */
	SDL_Init(SDL_INIT_VIDEO);
	SDL_Window* window = SDL_CreateWindow("B-Rend3r - v0.1", 
		SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 
		640, 480,
		SDL_WINDOW_RESIZABLE | SDL_WINDOW_OPENGL);
	
	SDL_GL_CreateContext(window);

	/* Extension wrangler initialising */
	GLenum glew_status = glewInit();
	if (glew_status != GLEW_OK) {
		std::cerr << "Error: glewInit: " << glewGetErrorString(glew_status) << std::endl;
		return EXIT_FAILURE;
	}

    Renderer renderer;
	if (!renderer.initResources()){
		std::cerr << "Error: unable to initialize renderer resources.";
		return EXIT_FAILURE;
    }
    
    while( renderer.update(window))
    {
    	renderer.render(window);
    }
	renderer.freeResources();

	return EXIT_SUCCESS;
}
