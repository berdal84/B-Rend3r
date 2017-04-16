#include "Transform.h"

Transform::Transform():
    _position(0.f, 0.f, 0.f),
    _rotation(0.f, 0.f, 0.f),
    _scale(1.f, 1.f, 1.f)
{

}

Transform::~Transform(){

}

void Transform::translate(vec3 _offset){
    _position += _offset;
}
