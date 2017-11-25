#include "Camera.h"


Camera::Camera()
{
    
}

Camera* Camera::Create()
{
	Camera* camera     = new Camera();
	camera->_world     = new Transform();
	camera->_view      = new Transform();
	return camera;
}

Transform* Camera::getViewTransform()
{
	return _view;
}

void Camera::translate(vec3 _offset)
{
    _world->translate(_offset);
}

void Camera::setPosition(vec3 _position)
{
    _world->setPosition(_position);
}

void Camera::setScale(vec3 _scale)
{
    _world->setScale(_scale);
}

Camera::~Camera()
{
    delete _world;
    delete _view;
}
