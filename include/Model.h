#ifndef MODEL_H
#define MODEL_H

#include "Matrix.h"
#include "../Shape.h"
#include <iostream>

class Model
{
    public:
        Model();
        Model(Shape *shape);

        virtual ~Model();

        void            translate(      float x, float y);
        void            setPosition(    float x, float y);

        Shape*          getShape()                  { return _shape; }
        void            setShape(Shape* shape)      { _shape = shape; }
        Matrix*         getMatrix()                 { return _matrix; }
        void            setMatrix(Matrix* matrix)   { _matrix = matrix; }
        unsigned int    getId()                     { return _id; }
        void            setId(unsigned int val)     { _id = val; }
        void            setName(char* name)         { _name = name;}
        char*           getName()                   { return _name;}
    protected:

    private:
        char*           _name;
        Shape*          _shape;
        Matrix*         _matrix;
        unsigned int    _id;

    friend std::ostream& operator<<(std::ostream& stream, Model* model){ stream << model->getName(); return stream;}
};

#endif // MODEL_H
