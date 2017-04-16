#include "Model.h"


Model::Model():_shape(NULL),_transform(NULL)
{
    _transform = new Transform();
}

Model::Model(Shape* shape):_shape(shape),_transform(NULL)
{
    _transform = new Transform();
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
