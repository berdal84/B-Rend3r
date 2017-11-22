#pragma once

#include <stdlib.h>
#include <math.h>
#include "Trigonometry.h"

class Transform
{
    public:
        Transform();
        ~Transform();
        void translate    (vec3 _offset);
        void rotate       (vec3 _offset);
        void setScale     (vec3 _scale){scale = _scale;};
        void setPosition  (vec3 _position){position = _position; }
        void setRotation  (vec3 _rotation){rotation = _rotation; }
        vec3 getPosition  ()const{return position;}
        void updateMatrix ();
        mat4 getMatrix()const {return matrix;}

        static mat4 Translate (vec3 _position);
        static mat4 Rotate    (vec3 _rotation);
        static mat4 Scale     (vec3 _scale);

    private:       
        vec3 position;
        vec3 rotation;
        vec3 scale; 
        mat4 matrix;   
};
