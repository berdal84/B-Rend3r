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
#include <ctime>

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

    Renderer renderer(vec2(640.0f, 480.0f));
    
	if (!renderer.initResources()){
		std::cerr << "Error: unable to initialize renderer resources.";
		return EXIT_FAILURE;
    }
    
    
    clock_t t0, t1;
    float dt = 0.0f;

    t0 = clock();
    t1 = clock();
    
    while( renderer.update(window, dt))
    {
    	renderer.render(window);    	
    	t0 = t1;
    	t1 = clock();
    	dt = (float)(t1 - t0)/CLOCKS_PER_SEC * 1000.0f;

    	std::cout << "dt = " << dt << std::endl;
    }
	renderer.freeResources();

	return EXIT_SUCCESS;
}
