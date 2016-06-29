/* Using standard C++ output libraries */
#include <cstdlib>
#include <iostream>

#include "Renderer.h"

/* Use glew.h instead of gl.h to get all the GL prototypes declared */
#include <GL/glew.h>
/* Using SDL2 for the base window and OpenGL context init */
#include <SDL2/SDL.h>

using namespace std;

int main(int argc, char* argv[]) {
    
	/* SDL-related initialising functions */
	SDL_Init(SDL_INIT_VIDEO);
	SDL_Window* window = SDL_CreateWindow("Turtl3D - v0.1",
		SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED,
		640, 480,
		SDL_WINDOW_RESIZABLE | SDL_WINDOW_OPENGL);
	SDL_GL_CreateContext(window);

	/* Extension wrangler initialising */
	GLenum glew_status = glewInit();
	if (glew_status != GLEW_OK) {
		cerr << "Error: glewInit: " << glewGetErrorString(glew_status) << endl;
		return EXIT_FAILURE;
	}

        /* Instanciate the renderer (OpenGL) */
        Renderer renderer;
        
	/* Try to initialise*/
	if (!renderer.initResources())
		return EXIT_FAILURE;

	/* We can display something if everything goes OK */
	renderer.mainLoop(window);

	/* If the program exits in the usual way,
	   free resources and exit with a success */
	renderer.freeResources();
        
	return EXIT_SUCCESS;
}
