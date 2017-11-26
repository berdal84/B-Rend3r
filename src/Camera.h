#pragma once

#include "Transform.h"
#include "Shape.h"
#include <iostream>
#include <string>

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
        void            setName            (const char* name)         { _name = name;}
        const char*     getName            ()                   { return _name.c_str();}
        void            setOrthographicSize(vec2 _size){ _orthographicSize = _size;}
        void            updateViewTransform();
        
        static Camera*  Create();
    private:
        std::string     _name;
        Transform*      _world            = nullptr;
        Transform*      _view             = nullptr;
        unsigned int    _id               = 0;
        Projection_     _projection       = Projection_Orthographic;
        vec2            _orthographicSize = vec2(100.0f, 100.0f);

    friend std::ostream& operator<<(std::ostream& stream, Camera* camera){ stream << camera->getName(); return stream;}
};
