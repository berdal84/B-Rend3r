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
#include <math.h>
#include "Trigonometry.h"

using namespace std;
using namespace brd;

Shape::Shape():shader(nullptr){
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
    return numberOfElements * sizeof(GLfloat);
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

Shape* Shape::CreateCircle(size_t segments)
{
    cout << "Shape::CreatePlane." << endl;
    Shape* shape = new Shape();

    shape->numberOfElementsPerVertex = 2;

    /* reserve memory for segment vertices */
    shape->reserveVertices(3 * segments);

    /* build triangle by triangle (segment by segment)*/
    for( size_t i=0; i < segments; i++)
    {
        shape->pushVertex(0.0f, 0.0f);
        float angle1 = radians((360.0f / segments) * i);
        float angle2 = radians((360.0f / segments ) * (i + 1));     
        shape->pushVertex(cos(angle1) ,sin(angle1)); 
        shape->pushVertex(cos(angle2) ,sin(angle2));
    }

    shape->printVerticesCount();

    return shape;
}
