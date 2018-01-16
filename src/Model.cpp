#include "Model.h"
#include <iostream>

using namespace brd;
using namespace std;

Model::Model():_shape(nullptr),_transform(nullptr)
{
    _transform = new Transform();
}

Model* Model::Create(Shape* shape)
{
	Model* model = new Model();
	model->_shape     = shape;
	return model;
}

void Model::translate(vec3 _offset)
{
    cout << "Model::translate(" << _offset.x << ", " << _offset.y << ", " << _offset.z << ")" << endl;
    _transform->translate(_offset);
}

void Model::setPosition(vec3 _position)
{
	_position.z = 1.0f;
    _transform->setPosition(_position);
}

void Model::setScale(vec3 _scale)
{
    _transform->setScale(_scale);
}

Model::~Model()
{
    delete _transform;
    delete _shape;
}
