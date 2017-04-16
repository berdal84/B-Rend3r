#pragma once

#include <stdlib.h>
#include <math.h>

typedef struct vec3 vec3;

struct vec3{
    vec3():x(0.f),y(0.f),z(0.f){};
    vec3(float _x, float _y, float _z):x(_x),y(_y),z(_z){};
    float x;
    float y;
    float z;

    vec3 operator+=(vec3 _right)
    {
        x += _right.x;
        y += _right.y;
        z += _right.z;
        return *this;
    }
};



class Transform
{
    public:
        /** Default constructor */
        Transform();
        /** Default destructor */
        virtual ~Transform();
        void translate(vec3 _offset);
        void setPosition(vec3 position){_position = position; }
        vec3 getPosition(){return _position;}
        float getPositionX(){return _position.x;}
        float getPositionY(){return _position.y;}
    protected:
        float _transform[4*4];
        vec3 _position;
        vec3 _rotation;
        vec3 _scale;

    private:
};
