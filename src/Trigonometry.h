#pragma once
#define PI 3.1415926535897

static float radians(float _degrees)
{

    return _degrees / 180.0f * PI;
}

static float degrees(float _radians)
{
    return _radians / PI * 180.0f;
}

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
    ~mat4(){};

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

    float getDeterminant() // TODO
    {
        return 0.0f;
    }
    mat4 getInverted() // TODO
    {
        mat4 result;
        return result;
    }

private:
    float m[4][4];
};


class vec3{
public:
    vec3():x(0.f),y(0.f),z(0.f){};
    vec3(float _x, float _y, float _z):x(_x),y(_y),z(_z){};
    vec3(float _v):x(_v),y(_v),z(_v){};
    ~vec3(){};
    float x;
    float y;
    float z;

    vec3 operator+(vec3 _right)
    {
        return vec3(this->x + _right.x, this->y + _right.y, this->z + _right.z );
    };

    vec3 operator*(float factor)
    {
        return vec3(this->x*factor, this->y*factor, this->z*factor);
    };

private:

};

class vec2{
public:
    vec2():x(0.f),y(0.f){};
    vec2(float _x, float _y):x(_x),y(_y){};
    ~vec2(){};

    float x;
    float y;
    vec2 operator+(vec2 _right)
    {
        return vec2(this->x + _right.x, this->y + _right.y);
    };

    vec2 operator*(float factor)
    {
        return vec2(this->x*factor, this->y*factor);
    };

private:

};
