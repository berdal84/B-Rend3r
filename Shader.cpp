/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Shader.cpp
 * Author: Bérenger Dalle-Cort <contact@dalle-cort.fr>
 * 
 * Created on 1 juillet 2016, 19:14
 */

#include "Shader.h"

using namespace std;

Shader::Shader() {
}

Shader::Shader(const Shader& orig) {
}

Shader::~Shader() {
}

bool Shader::compile(){
    
    compileVertexShader();
    compileFragmentShader();
    linkProgram();
    bindAttributes();
    
    cout << "Shader ready." << endl;

    return true;
}

GLint Shader::getAttributeCoord3D(){
    return attribute_coord3d;
}

bool Shader::compileVertexShader(){
    cout << "Compiling vertex shader..." << endl;
    
    GLint compile_ok = GL_FALSE, link_ok = GL_FALSE;

    vertexShader = glCreateShader(GL_VERTEX_SHADER);
    
    const char *vs_source =
        //"#version 100\n"  // OpenGL ES 2.0
        "#version 120\n"  // OpenGL 2.1
        "attribute vec2 coord2d;                  "
        "void main(void) {                        "
        "  gl_Position = vec4(coord2d, 0.0, 1.0); "
        "}";
    
    /*const char *vs_source =
        //"#version 100\n"  // OpenGL ES 2.0
        "#version 120\n"  // OpenGL 2.1
        "attribute vec3 coord3d;                  "
        "void main(void) {                        "
        "  gl_Position = vec4(coord3d, 1.0); "
        "}";*/
    
    
    
    
    glShaderSource(vertexShader, 1, &vs_source, NULL);
    glCompileShader(vertexShader);
    glGetShaderiv(vertexShader, GL_COMPILE_STATUS, &compile_ok);
    if (!compile_ok) {
        cerr << "Error in vertex shader compilation" << endl;
        return false;
    }
    
    return true;
}

bool Shader::compileFragmentShader(){
    GLint compile_ok = GL_FALSE, link_ok = GL_FALSE;
    cout << "Compiling fragment shader..." << endl;
    // TODO : externalize source
    fragmentShader = glCreateShader(GL_FRAGMENT_SHADER);
    const char *fs_source =
        //"#version 100\n"  // OpenGL ES 2.0
        "#version 120\n"  // OpenGL 2.1
        "void main(void) {        "
        "  gl_FragColor[0] = 1.0; "
        "  gl_FragColor[1] = 0.0; "
        "  gl_FragColor[2] = 0.0; "
        "}";
    glShaderSource(fragmentShader, 1, &fs_source, NULL);
    glCompileShader(fragmentShader);
    glGetShaderiv(fragmentShader, GL_COMPILE_STATUS, &compile_ok);
    if (!compile_ok) {
        cerr << "Error in fragment shader compilation" << endl;
        return false;
    }
    
    return true;
    
}

bool Shader::linkProgram(){
    GLint compile_ok = GL_FALSE, link_ok = GL_FALSE;
    cout << "Attaching shaders to program and linking it..." << endl;

    // Link the vertex and fragment shaders to the GLSL program

    program = glCreateProgram();
    glAttachShader(program, vertexShader);
    glAttachShader(program, fragmentShader);
    glLinkProgram(program);
    glGetProgramiv(program, GL_LINK_STATUS, &link_ok);
    if (!link_ok) {
        cerr << "Error in glLinkProgram" << endl;
        return false;
    }
    
    return true;
}

GLuint Shader::getProgram(){
    return program;
}

bool Shader::bindAttributes(){
            
    cout << "Binding attributes..." << endl;
    
    const char* attribute_name = "coord2d";
    attribute_coord3d = glGetAttribLocation(program, attribute_name);
    if (attribute_coord3d == -1) {
        cerr << "Could not bind attribute " << attribute_name << endl;
        return false;
    }
            
    return true;
}
