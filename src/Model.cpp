#include "Model.h"


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
    _transform->translate(_offset);
}

void Model::setPosition(vec3 _position)
{
    _transform->setPosition(_position);
}

Model::~Model()
{
    delete _transform;
    delete _shape;
}
