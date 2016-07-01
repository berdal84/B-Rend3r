 /*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Shader.h
 * Author: Bérenger Dalle-Cort <contact@dalle-cort.fr>
 *
 * Created on 1 juillet 2016, 19:14
 */



#ifndef SHADER_H
#define SHADER_H

#include <iostream>
#include <cstdlib>
#include <GL/glew.h>

class Shader {
public:
    Shader();
    Shader(const Shader& orig);
    virtual ~Shader();
    GLuint getProgram();
    GLint getAttributeCoord3D();
    bool compile();

    
private:    
    GLuint vertexShader;
    GLuint fragmentShader;
    GLuint program;
    GLint attribute_coord3d;
    
    bool bindAttributes();
    bool compileVertexShader();
    bool compileFragmentShader();
    bool linkProgram();

};

#endif /* SHADER_H */

