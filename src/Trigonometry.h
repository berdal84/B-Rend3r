#pragma once
#define PI 3.1415926535897
#include <iostream>       // for implementation of operator <<

namespace brd{
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

        mat4(float f)
        {
            for(short i=0; i<4 ; i++)
                for(short j=0 ; j<4; j++)
                    m[i][j] = f;
        };

        mat4(const mat4& m2)
        {
            for(short i=0; i<4 ; i++)
                for(short j=0 ; j<4; j++)
                    m[i][j] = m2[i][j];
        };

        ~mat4(){};

        float* operator[](size_t n){
            return m[n];
        };

        const float* operator[](size_t n)const{
            return m[n];
        };


        mat4 operator/(float f)const
        {
            mat4 result;

            for(short i=0; i<4 ; i++)
                for(short j=0 ; j<4; j++)
                    result[i][j] = m[i][j] / f;

            return result;
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

        mat4 getTranspose()
        {
            mat4 result;

            for(short i=0; i<4 ; i++)
                for(short j=0 ; j<4; j++)
                    result[i][j] = m[j][i];

            return result;
        }
        mat4 getInverse()
        {

            // Using this formula
            // invA = (1 / det(A)) * cofactorTransposed(A)

            mat4 cofactor;
            // compute first column of factors
            cofactor[0][0] =           m[1][1] * m[2][2] * m[3][3]
                                + m[2][1] * m[3][2] * m[1][3]
                                + m[3][1] * m[1][2] * m[2][3]

                                - m[1][3] * m[2][2] * m[3][1]
                                - m[2][3] * m[3][2] * m[1][1]
                                - m[3][3] * m[1][2] * m[2][1];

            cofactor[0][1] =       m[1][0] * m[2][2] * m[3][3]
                                + m[2][0] * m[3][2] * m[1][3]
                                + m[3][0] * m[1][2] * m[2][3]

                                - m[1][3] * m[2][2] * m[3][0]
                                - m[2][3] * m[3][2] * m[1][0]
                                - m[3][3] * m[1][2] * m[2][0];

            cofactor[0][2] =       m[1][0] * m[2][1] * m[3][3]
                                + m[2][0] * m[3][1] * m[1][3]
                                + m[3][0] * m[1][1] * m[2][3]

                                - m[1][3] * m[2][1] * m[3][0]
                                - m[2][3] * m[3][1] * m[1][0]
                                - m[3][3] * m[1][1] * m[2][0];

            cofactor[0][3] =       m[1][0] * m[2][1] * m[3][2]
                                + m[2][0] * m[3][1] * m[1][2]
                                + m[3][0] * m[1][1] * m[2][2]

                                - m[1][2] * m[2][1] * m[3][0]
                                - m[2][2] * m[3][1] * m[1][0]
                                - m[3][2] * m[1][1] * m[2][0];

            // compute second column of factors
            cofactor[1][0] =       m[0][1] * m[2][2] * m[3][3]
                                + m[2][1] * m[3][2] * m[0][3]
                                + m[3][1] * m[0][2] * m[2][3]

                                - m[0][3] * m[2][2] * m[3][1]
                                - m[2][3] * m[3][2] * m[0][1]
                                - m[3][3] * m[0][2] * m[2][1];

            cofactor[1][1] =       m[0][0] * m[2][2] * m[3][3]
                                + m[2][0] * m[3][2] * m[0][3]
                                + m[3][0] * m[0][2] * m[2][3]

                                - m[0][3] * m[2][2] * m[3][0]
                                - m[2][3] * m[3][2] * m[0][0]
                                - m[3][3] * m[0][2] * m[2][0];

            cofactor[1][2] =       m[0][0] * m[2][1] * m[3][3]
                                + m[2][0] * m[3][1] * m[0][3]
                                + m[3][0] * m[0][1] * m[2][3]

                                - m[0][3] * m[2][1] * m[3][0]
                                - m[2][3] * m[3][1] * m[0][0]
                                - m[3][3] * m[0][1] * m[2][0];

            cofactor[1][3] =       m[0][0] * m[2][1] * m[3][2]
                                + m[2][0] * m[3][1] * m[0][2]
                                + m[3][0] * m[0][1] * m[2][2]

                                - m[0][2] * m[2][1] * m[3][0]
                                - m[2][2] * m[3][1] * m[0][0]
                                - m[3][2] * m[0][1] * m[2][0];

            // compute thrid column of factors

            cofactor[2][0] =       m[0][1] * m[1][2] * m[3][3]
                                + m[1][1] * m[3][2] * m[0][3]
                                + m[3][1] * m[0][2] * m[1][3]

                                - m[0][3] * m[1][2] * m[3][1]
                                - m[1][3] * m[3][2] * m[0][1]
                                - m[3][3] * m[0][2] * m[1][1];

            cofactor[2][1] =       m[0][0] * m[1][2] * m[3][3]
                                + m[1][0] * m[3][2] * m[0][3]
                                + m[3][0] * m[0][2] * m[1][3]

                                - m[0][3] * m[1][2] * m[3][0]
                                - m[1][3] * m[3][2] * m[0][0]
                                - m[3][3] * m[0][2] * m[1][0];

            cofactor[2][2] =       m[0][0] * m[1][1] * m[3][3]
                                + m[1][0] * m[3][1] * m[0][3]
                                + m[3][0] * m[0][1] * m[1][3]

                                - m[0][3] * m[1][1] * m[3][0]
                                - m[1][3] * m[3][1] * m[0][0]
                                - m[3][3] * m[0][1] * m[1][0];

            cofactor[2][3] =       m[0][0] * m[1][1] * m[3][2]
                                + m[1][0] * m[3][1] * m[0][2]
                                + m[3][0] * m[0][1] * m[1][2]

                                - m[0][2] * m[1][1] * m[3][0]
                                - m[1][2] * m[3][1] * m[0][0]
                                - m[3][2] * m[0][1] * m[1][0];

            // compute fourth column of factors
                                
            cofactor[3][0] =       m[0][1] * m[1][2] * m[2][3]
                                + m[1][1] * m[2][2] * m[0][3]
                                + m[2][1] * m[0][2] * m[1][3]

                                - m[0][3] * m[1][2] * m[2][1]
                                - m[1][3] * m[2][2] * m[0][1]
                                - m[2][3] * m[0][2] * m[1][1];

            cofactor[3][1] =       m[0][0] * m[1][2] * m[2][3]
                                + m[1][0] * m[2][2] * m[0][3]
                                + m[2][0] * m[0][2] * m[1][3]

                                - m[0][3] * m[1][2] * m[2][0]
                                - m[1][3] * m[2][2] * m[0][0]
                                - m[2][3] * m[0][2] * m[1][0];

            cofactor[3][2] =       m[0][0] * m[1][1] * m[2][3]
                                + m[1][0] * m[2][1] * m[0][3]
                                + m[2][0] * m[0][1] * m[1][3]

                                - m[0][3] * m[1][1] * m[2][0]
                                - m[1][3] * m[2][1] * m[0][0]
                                - m[2][3] * m[0][1] * m[1][0];

            cofactor[3][3] =       m[0][0] * m[1][1] * m[2][2]
                                + m[1][0] * m[2][1] * m[0][2]
                                + m[2][0] * m[0][1] * m[1][2]

                                - m[0][2] * m[1][1] * m[2][0]
                                - m[1][2] * m[2][1] * m[0][0]
                                - m[2][2] * m[0][1] * m[1][0];

            // Add signs to the cofactors
            for(short i=0; i< 4; i++)
            {
                for(short j=0; j<4; j++)
                {
                    if (i!=j)
                    {
                        cofactor[i][j] = -cofactor[i][j];
                    }
                }
            }

            // Compute determinant (using the first column)
            float det = m[0][0] * cofactor[0][0] 
                        +m[0][1] * cofactor[0][1]
                        +m[0][2] * cofactor[0][2]
                        +m[0][3] * cofactor[0][3];
                      
            
            mat4 inverse = (1.0f/det) * cofactor.getTranspose();

            return inverse;
        };

        friend mat4 operator*(float f, mat4 m){
            mat4 result;
            for(short i=0; i< 4; i++)
            {
                for(short j=0; j<4; j++)
                {
                    result[i][j] = m[i][j] * f;
                }
            }
            return result;
        }

        friend std::ostream& operator<<(std::ostream& stream, mat4 m)
        {
            stream << "Matrix4x4" << std::endl;
            for (short j = 0; j < 4; j++)
                stream << "[" << m[0][j] << ", " << m[1][j] << ", " << m[2][j] << ", "<< m[3][j] << "]" << std::endl;
            return stream;
        };

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
}