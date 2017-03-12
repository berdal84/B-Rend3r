#include "Matrix.h"

Matrix::Matrix():
{
    _matrix = new float[3*3];
}

Matrix::~Matrix()
{
    delete _matrix;
}
