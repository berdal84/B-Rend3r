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

Shape::Shape():shader(NULL),positionX(0.0f), positionY(0.0f){

    cout << "Creating a new Shape..." << endl;

    numberOfElementsPerVertex = 2;
    numberOfElements = 0;

    /* reserve memory for six  2D vertices */
    vertices = new GLfloat[6 * numberOfElementsPerVertex];

    /* First triangle */
    pushVertex(0.0, 0.0);
    pushVertex(0.8, 0.0);
    pushVertex(0.8, 0.8);

    /* second triangle */
    pushVertex(0.8, 0.8);
    pushVertex(0.0, 0.8);
    pushVertex(0.0, 0.0);

    printVerticesCount();
}


void Shape::setShader(Shader* _shader){
    this->shader = _shader;
    cout << "Setting shader to the shape..." << endl;
}

Shader* Shape::getShader(){

    return this->shader;
}


Shape::Shape(const Shape& orig) {
    cout << "blu!!!";
}

GLfloat* Shape::getVertices(){
    return vertices;
}

void Shape::pushVertex(GLfloat x, GLfloat y){
    vertices[numberOfElements++] = x;
    vertices[numberOfElements++] = y;
}


int Shape::getNumberOfElementsPerVertex(){
    return this->numberOfElementsPerVertex;
}

int Shape::getVerticesBufferSize(){
    return sizeof(vertices)/sizeof(GLfloat);
}

int Shape::getVerticesCount(){
    return numberOfElements/numberOfElementsPerVertex;
}

void Shape::printVerticesCount(){
    cout << "This shape has " << getVerticesCount() << " vertices." << endl;
}

// note : for cleaning memory...
Shape::~Shape() {

}

