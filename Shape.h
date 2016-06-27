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
#include <GL/glew.h>
#include <SDL2/SDL.h>

#include <iostream>
#include <cstdlib>

#ifndef SHAPE_H
#define SHAPE_H

class Shape {
public:
    Shape();
    GLfloat* getVertices();
    Shape(const Shape& orig);
    virtual ~Shape();
    void printVerticesCount();
    GLfloat vertices[6];
};

#endif /* SHAPE_H */

