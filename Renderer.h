/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Renderer.h
 * Author: Bérenger Dalle-Cort <contact@dalle-cort.fr>
 *
 * Created on 28 juin 2016, 20:35
 */

/* My headers */
#include "Shape.h"
#include "Shader.h"

#include <iostream>
#include <cstdlib>
#include <GL/glew.h>
#include <SDL2/SDL.h>



#ifndef RENDERER_H
#define RENDERER_H

class Renderer {
public:
    Renderer();
    Renderer(const Renderer& orig);
    virtual ~Renderer();
    
    bool initResources();
    void freeResources();
    void mainLoop(SDL_Window*); 
    void render(SDL_Window*);
    void drawShape(Shape* shape);
private:
    Shape* myShape;
    GLint attribute_coord2d;
};

#endif /* RENDERER_H */

