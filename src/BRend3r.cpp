#include "BRend3r.h"

#include <cstdlib>
#include <iostream>
#include "Renderer.h"

using namespace std;

BRend3r::BRend3r(){

}

BRend3r::~BRend3r()
{	

}

void BRend3r::shutdown()
{
	SDL_DestroyWindow         (this->_window);
	SDL_GL_DeleteContext      (this->_glContext);
	_renderer->freeResources  ();
	delete _renderer;
}

bool BRend3r::initialize()
{
	/* Initialize deltaTime related variables */
	_deltaTime = 0.0f;
    _t0 = clock();
    _t1 = clock();

	/* SDL-related initialising functions */
	SDL_Init(SDL_INIT_VIDEO);
	this->_window = SDL_CreateWindow("B-Rend3r - v0.1", // Window title could be a parameter or a define
		SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 
		640, 480,										// the same window's size
		SDL_WINDOW_RESIZABLE | SDL_WINDOW_OPENGL);
	
	this->_glContext = SDL_GL_CreateContext(this->_window);

	/* Extension wrangler initialising */
	GLenum glew_status = glewInit();
	if (glew_status != GLEW_OK) {
		cerr << "Error: glewInit: " << glewGetErrorString(glew_status) << endl;
		return false;
	}

	/* Initialize the renderer */
    this->_renderer = new Renderer(vec2(640.0f, 480.0f));	

	if (!this->_renderer->initResources()){
		cerr << "Error: unable to initialize renderer resources." << endl;
		return false;
    }   

    cout << "B-Rend3r successfully initialized !" << endl;

    return true;
}
    
bool BRend3r::update()
{
	/* Evaluate deltaTime : TODO take N-2 values (ignoring higher and lower value then perform an average)*/
	this->_t0 = this->_t1;
    this->_t1 = clock();
    this->_deltaTime = (float)(this->_t1 - this->_t0)/CLOCKS_PER_SEC;	

    /* Update engine modules */

    /* 1 - the physics */
    	// TODO

    /* 2 - the character controllers */
    	// TODO

    /* 3 - the renderer */
	if (!_renderer->update(_window, _deltaTime))
    	return false;

    return true;
}
    
void BRend3r::draw()
{
	_renderer->render(_window);
}


