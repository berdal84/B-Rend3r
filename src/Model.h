#pragma once

#include "Transform.h"
#include "Shape.h"
#include <iostream>

class Model
{
    public:
        Model();
        

        virtual ~Model();

        void            translate   (vec3 _offset);
        void            setPosition (vec3 position);
        void            setScale    (vec3 _scale);
        Shape*          getShape    ()                  { return _shape; }
        void            setShape    (Shape* shape)      { _shape = shape; }
        Transform*      getTransform()                 { return _transform; }
        void            setTransform(Transform* transform)   { _transform = transform; }
        unsigned int    getId       ()                     { return _id; }
        void            setId       (unsigned int val)     { _id = val; }
        void            setName     (char* name)         { _name = name;}
        char*           getName     ()                   { return _name;}
    
        static Model*   Create(Shape *shape);

    private:
        char*           _name;
        Shape*          _shape;
        Transform*      _transform;
        unsigned int    _id;

    friend std::ostream& operator<<(std::ostream& stream, Model* model){ stream << model->getName(); return stream;}
};
