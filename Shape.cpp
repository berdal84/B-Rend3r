/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Shape.cpp
 * Author: dallecortb
 * 
 * Created on 27 juin 2016, 19:29
 */

#include "Shape.h"

Shape::Shape() {
    
    vertices[0] = 0.0;
    vertices[1] = 0.8;
    
    vertices[2] = 0.8;
    vertices[3] = 0.8;
    
    vertices[4] = 0.0;
    vertices[5] = 0.0;
    
    this->printVerticesCount();
 
}

Shape::Shape(const Shape& orig) {
}

GLfloat* Shape::getVertices(){
    return vertices;
}

void Shape::printVerticesCount(){
    std::cout << "This shape has " << sizeof(&vertices) << ".";
}

// note : for cleaning memory...
Shape::~Shape() {
}

