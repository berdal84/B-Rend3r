/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Shape.cpp
 * Author: Bérenger Dalle-Cort
 * 
 * Created on 27 juin 2016, 19:29
 */

#include "Shape.h"

using namespace std;

Shape::Shape() {
    
    vertices[0] = 0.0;
    vertices[1] = 0.8;
    
    vertices[2] = 0.8;
    vertices[3] = 0.8;
    
    vertices[4] = 0.8;
    vertices[5] = 0.0;
    
    vertices[6] = 0.0;
    vertices[7] = 0.0;
    
    this->printVerticesCount();
 
}

Shape::Shape(const Shape& orig) {
}

GLfloat* Shape::getVertices(){
    return vertices;
}

int Shape::getVerticesCount(){
    return sizeof(&vertices);
}

void Shape::printVerticesCount(){
    cout << "This shape has " << getVerticesCount() << ".";
}

// note : for cleaning memory...
Shape::~Shape() {
}

