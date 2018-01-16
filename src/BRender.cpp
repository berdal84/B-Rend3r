#include "BRender.h"

#include <cstdlib>
#include <iostream>
#include "Camera.h"
#include "Shader.h"
#include "Shape.h"
#include "Model.h"
#include "Renderer.h"
#include "CharacterController.h"
#include "PhysicsComponent.h"

using namespace std;
using namespace brd;

BRender::BRender(){

}

BRender::~BRender()
{	

}

void BRender::shutdown()
{
	SDL_DestroyWindow         (this->_window);
	SDL_GL_DeleteContext      (this->_glContext);
	_renderer->freeResources  ();
	delete _renderer;
}

bool BRender::initialize()
{
	/* Initialize deltaTime related variables */
	_deltaTime = 0.0f;
    _lastTick = SDL_GetTicks();

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

	/* Initialize 3d Scene */
	    // Create a default shape with a default shader and compile it.
    Shape* myShape = Shape::CreateCircle(64);
    Shader* shader = Shader::CreateVsFs("../../shaders/default");
    myShape->setShader(shader);

    Model* myModel = Model::Create(myShape);
    const char* name = "Modele001";
    myModel->setName("Modele001");
    myModel->setPosition(vec3(0.0f, 0.0f, 0.0f));
	myModel->setScale (vec3(100.0f));

    // Create a camera
    auto cam = Camera::Create();
    cam->setName("DefaultCamera");

	/* Initialize physics component */
	this->physicsComponent = new PhysicsComponent(myModel);

	/* Initialize controller */
	this->characterController = new CharacterController(this->physicsComponent);

	/* Initialize the renderer */
    this->_renderer = new Renderer(vec2(640.0f, 480.0f));	
    this->_renderer->addModel(myModel);
    this->_renderer->setCurrentCamera(cam);

    cout << "B-Rend3r successfully initialized !" << endl;

    return true;
}
    
bool BRender::update()
{
	/* Evaluate deltaTime : TODO take N-2 values (ignoring higher and lower value then perform an average)*/
	this->_deltaTime = ((float)(SDL_GetTicks() - _lastTick))/1000.0f;
    this->_lastTick = SDL_GetTicks();
    
    int fps = (int)(1/_deltaTime);

    cout << "BRender::update() - FPS: " << fps << ", delta time: " << _deltaTime << endl;

    /* Update engine modules */

    /* 1 - the character controllers */
    if ( this->characterController!= nullptr)
    	this->characterController->update(this->_deltaTime);

    /* 2 - the physics */
 	if ( this->physicsComponent!= nullptr)
    	this->physicsComponent->update(this->_deltaTime);

    /* 3 - the renderer */
	if (!_renderer->update(_window, _deltaTime))
    	return false;

    return true;
}
    
void BRender::draw()
{
	_renderer->render(_window);
}


