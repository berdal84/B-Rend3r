#pragma once

#include "Transform.h"
#include "Shape.h"
#include <iostream>

class Camera
{
    public:

        enum Projection_{
            Projection_Orthographic,
            Projection_Perspective // not yet implemented
        };

        Camera();  
        ~Camera();

        void            translate          (vec3 _offset);
        void            setPosition        (vec3 position);
        void            setScale           (vec3 _scale);
        Transform*      getTransform       ()                 { return _world; }
        void            setTransform       (Transform* t)   { _world = t; }
        Transform*      getViewTransform   ();
        unsigned int    getId              ()                     { return _id; }
        void            setId              (unsigned int val)     { _id = val; }
        void            setName            (char* name)         { _name = name;}
        char*           getName            ()                   { return _name;}
        void            setOrthographicSize(vec2 _size){ _orthographicSize = _size;}

        static Camera*  Create();
    private:
        char*           _name             = nullptr;
        Transform*      _world            = nullptr;
        Transform*      _view             = nullptr;
        unsigned int    _id               = 0;
        Projection_     _projection       = Projection_Orthographic;
        vec2            _orthographicSize = vec2(100.0f, 100.0f);

    friend std::ostream& operator<<(std::ostream& stream, Camera* camera){ stream << camera->getName(); return stream;}
};
