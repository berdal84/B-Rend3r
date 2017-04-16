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
#include <iostream>

#include <string>
#include <fstream>


using namespace std;

Shader::Shader() {

}

Shader* Shader::createShader(const std::string& shaderFilePath){

    Shader* shader = new Shader();

    shader->compile(shaderFilePath);

    return shader;
}

std::string Shader::loadFile(const std::string& fileName){

    // Read the Vertex Shader code from the file
    string code;

    ifstream file;

    file.open((fileName).c_str());

    if(file.is_open()){
        std::string Line = "";
        while(getline(file, Line))
            code += "\n" + Line;
        file.close();
    }else{
        std::cerr << "Unable to load file: " << fileName << std::endl;

    }

    //cout << code << endl;

    return &code[0];
}

Shader::Shader(const Shader& orig) {
}

Shader::~Shader() {
}

bool Shader::compile(const std::string& shaderFilePath){

    this->compileVS(this->loadFile(shaderFilePath +".vs"));
    this->compileFS(this->loadFile(shaderFilePath +".fs"));

    this->linkProgram();
    this->bindAttributes();

    return true;
}

GLint Shader::getAttributeCoord3D(){
    return attribute_coord3d;
}

bool Shader::compileVS(const std::string& source){

    cout << "Compiling vertex shader..." << endl;

    GLint compile_ok = GL_FALSE;

    vertexShader = glCreateShader(GL_VERTEX_SHADER);

    const char *c_str = source.c_str();

    glShaderSource(vertexShader, 1, &c_str, NULL );

    glCompileShader(vertexShader);
    glGetShaderiv(vertexShader, GL_COMPILE_STATUS, &compile_ok);

    if (!compile_ok) {
        cerr << "Error in vertex shader compilation" << endl;
        cout << c_str;
        return false;
    }

    return true;
}

bool Shader::compileFS(const std::string& source){
    cout << "Compiling fragment shader..." << endl;

    GLint compile_ok = GL_FALSE;

    fragmentShader = glCreateShader(GL_FRAGMENT_SHADER);

    const char *c_str = source.c_str();

    glShaderSource(fragmentShader, 1, &c_str, NULL );

    glCompileShader(fragmentShader);
    glGetShaderiv(fragmentShader, GL_COMPILE_STATUS, &compile_ok);
    if (!compile_ok) {
        cerr << "Error in fragment shader compilation" << endl;
        cout << c_str;
        return false;
    }

    return true;

}

bool Shader::linkProgram(){
    GLint link_ok = GL_FALSE;
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
