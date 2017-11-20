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

Shape::Shape():shader(NULL){
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

void Shape::reserveVertices(size_t n)
{
    this->vertices = new GLfloat[n * numberOfElementsPerVertex];
}

Shape* Shape::CreatePlane()
{
    cout << "Shape::CreatePlane." << endl;
    Shape* plane = new Shape();

    plane->numberOfElementsPerVertex = 2;

    /* reserve memory for six  2D vertices */
    plane->reserveVertices(6);

    /* First triangle */
    plane->pushVertex(-0.5, -0.5);
    plane->pushVertex(0.5, -0.5);
    plane->pushVertex(0.5, 0.5);

    /* second triangle */
    plane->pushVertex(0.5, 0.5);
    plane->pushVertex(-0.5, 0.5);
    plane->pushVertex(-0.5, -0.5);

    plane->printVerticesCount();

    return plane;
}

