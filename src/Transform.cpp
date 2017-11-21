#include "Transform.h"
#include <cmath>

Transform::Transform():
    position(0.f, 0.f, 0.f),
    rotation(0.f, 0.f, 0.f),
    scale(1.f, 1.f, 1.f),
    matrix()
{

}

Transform::~Transform(){

}

void Transform::translate(vec3 _offset){
    position += _offset;
}

void Transform::updateMatrix()
{
	this->matrix = Translate(position) * Rotate(rotation) * Scale(scale);
}

mat4 Transform::Translate (vec3 _position)
{
	mat4 m;
	m[3][0] = _position.x;
	m[3][1] = _position.y;
	m[3][2] = _position.z;
	return m;
}

mat4 Transform::Rotate    (vec3 _rotation)
{
	mat4 m;
	m[0][0] = std::cos(_rotation.z);
	m[1][0] = std::sin(_rotation.z);
	m[0][1] = -std::sin(_rotation.z);
	m[1][1] = std::cos(_rotation.z);
	return m;
}

mat4 Transform::Scale     (vec3 _scale)
{
	mat4 m;
	m[0][0] = _scale.x;
	m[1][1] = _scale.y;
	m[2][2] = _scale.z;
	return m;
}