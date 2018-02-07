#include "Transform.h"
#include <cmath>
#include "Component.h"
#include <iostream>

using namespace brd;
using namespace std;

ComponentType_ Transform::s_type = ComponentType_Transform;

Transform::Transform():
    position(0.f, 0.f, 0.f),
    rotation(0.f, 0.f, 0.f),
    scale(1.f, 1.f, 1.f),
    matrix()
{

}

Transform::Transform(const mat4& m2):
    position(0.f, 0.f, 0.f),
    rotation(0.f, 0.f, 0.f),
    scale(1.f, 1.f, 1.f),
    matrix(m2)
{
}


Transform::~Transform(){

}

void Transform::translate(vec3 _offset){
    position = position + _offset;
}

void Transform::rotate(vec3 _offset){
    rotation = rotation + _offset;
}

void Transform::updateMatrix()
{
	cout << "transform::updateMatrix() - Begin" << endl;
	this->matrix = Translate(position) * Rotate(rotation) * Scale(scale);
	cout << "transform::updateMatrix() - End" << endl;
}

void Transform::update(double _deltaTime)
{
	cout << "Transform::update() - Begin" << endl;
	updateMatrix();
	cout << "Transform::update() - End" << endl;
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
	m[0][0] = std::cos(radians(_rotation.z));
	m[1][0] = std::sin(radians(_rotation.z));
	m[0][1] = -std::sin(radians(_rotation.z));
	m[1][1] = std::cos(radians(_rotation.z));
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

