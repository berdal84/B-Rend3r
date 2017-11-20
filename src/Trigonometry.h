#pragma once

/* mat4 are column major */
class mat4{
public:
    mat4(){
        m[0][0] = 1.0f;
        m[0][1] = 0.0f;
        m[0][2] = 0.0f;
        m[0][3] = 0.0f;

        m[1][0] = 0.0f;
        m[1][1] = 1.0f;
        m[1][2] = 0.0f;
        m[1][3] = 0.0f;

        m[2][0] = 0.0f;
        m[2][1] = 0.0f;
        m[2][2] = 1.0f;
        m[2][3] = 0.0f;

        m[3][0] = 0.0f;
        m[3][1] = 0.0f;
        m[3][2] = 0.0f;
        m[3][3] = 1.0f;
    };

    float* operator[](size_t n){
        return m[n];
    };

    mat4 operator*(mat4 m2)
    {
        mat4 result;
        for(short x = 0; x < 4; x++){
            for(short y = 0; y < 4; y++){
                result[x][y] =  m2[x][0] * m[0][y] + 
                                m2[x][1] * m[1][y] + 
                                m2[x][2] * m[2][y] + 
                                m2[x][3] * m[3][y];
            }
        }
        return result;
    };

private:
    float m[4][4];
};


class vec3{
public:
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
    };

    vec3 operator*(float f)
    {
        return vec3(x*f, y*f, z*f);
    };

private:

};

class vec2{
public:
    vec2():x(0.f),y(0.f){};
    vec2(float _x, float _y):x(_x),y(_y){};
    float x;
    float y;

    vec2 operator+=(vec2 _right)
    {
        x += _right.x;
        y += _right.y;
        return *this;
    };

    vec2 operator*(float f)
    {
        return vec2(x*f, y*f);
    };

private:

};
