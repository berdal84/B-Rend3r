#include "Model.h"


Model::Model():_shape(NULL),_matrix(NULL)
{
    _matrix = new Matrix();
}

Model::Model(Shape* shape):_shape(shape),_matrix(NULL)
{
    _matrix = new Matrix();
}

void Model::translate(float x, float y)
{
    _shape->setPositionX(_shape->getPositionX() + x); /* TODO : use the matrix */
    _shape->setPositionY(_shape->getPositionY() + y);
}

void Model::setPosition(float x, float y)
{
    _shape->setPositionX(x);                            /*TODO : use the matrix */
    _shape->setPositionY(y);
}

Model::~Model()
{
    delete _matrix;
    delete _shape;
}
