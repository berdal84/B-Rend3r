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
#include <iostream>
#include <cstdlib>

/* Use glew.h instead of gl.h to get all the GL prototypes declared */
#include <GL/glew.h>
/* Using SDL2 for the base window and OpenGL context init */
#include <SDL2/SDL.h>



#ifndef SHAPE_H
#define SHAPE_H

class Shape {
public:
    Shape();
    GLfloat* getVertices();
    int getVerticesCount();
    int getVerticesCoordCount();
    Shape(const Shape& orig);
    virtual ~Shape();
    void printVerticesCount();
private:
    GLfloat vertices[6];
};

#endif /* SHAPE_H */

