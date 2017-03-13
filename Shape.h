/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/*
 * File:   Shape.h
 * Author: dallecortb
 *
 * Created on 27 juin 2016, 19:28
 */


#ifndef SHAPE_H
#define SHAPE_H

#include <iostream>
#include <cstdlib>
#include <GL/glew.h>
#include <SDL2/SDL.h>

class Shader;

class Shape {

public:
    Shape();
    GLfloat* getVertices();
    int getVerticesBufferSize();
    int getVerticesCoordCount();
    Shape(const Shape& orig);
    virtual ~Shape();
    void printVerticesCount();
    int getNumberOfElementsPerVertex();
    int getVerticesCount();
    void pushVertex(GLfloat x, GLfloat y);
    void pushVertex(GLfloat x, GLfloat y, GLfloat z);
    Shader* getShader();
    void setShader(Shader* shader);

    float getPositionX(){return positionX;};
    float getPositionY(){return positionY;};
    void setPositionX(float _x){positionX = _x;};
    void setPositionY(float _y){positionY = _y;};

private:
    int numberOfElementsPerVertex;
    int numberOfElements;
    GLfloat *vertices;
    Shader* shader;

    float positionX;
    float positionY;

};

#endif /* SHAPE_H */

