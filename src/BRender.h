#pragma once

#include <time.h>
#include <GL/glew.h>
#include <SDL2/SDL.h>
#include <vector>

namespace brd{

	/* Forward declarations */
	class Model;
	class Renderer;
	class KeyboardController;
	
	class BRender
	{
	private:
		SDL_Window* _window		                     = nullptr;
		SDL_GLContext _glContext                     = nullptr;
		Renderer*   _renderer                        =  nullptr;
		float       _deltaTime                       = 0.0f;
		Uint32     _lastTick;                                    /* used to determine _deltaTime each frame */

		std::vector<Model*>    models;

	public:
		BRender();
		~BRender();

		/* call this member function after BRend3r instantiation */
		bool initialize();	    

		/* call this member function before returning main program (main()) */
		void shutdown();

		/* call this member function to update the application */
		bool update();   

		/* call this to draw the OpenGL Window */
		void draw();
	};
}


