#pragma once

#include "Transform.h"
#include "Shape.h"
#include <iostream>
#include <string>

namespace brd{
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
            void            setName     (const char* name)         { _name = name;}
            const char*     getName     ()                   { return _name.c_str();}
        
            static Model*   Create(Shape *shape);

        private:
            std::string     _name;
            Shape*          _shape;
            Transform*      _transform;
            unsigned int    _id;

        friend std::ostream& operator<<(std::ostream& stream, Model* model){ stream << model->getName(); return stream;}
    };
}