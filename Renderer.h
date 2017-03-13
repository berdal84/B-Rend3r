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
#ifndef RENDERER_H
#define RENDERER_H

#include <iostream>
#include <cstdlib>

#include <GL/glew.h>
#include <SDL2/SDL.h>

#include "Shader.h"
#include "Shape.h"
#include "Model.h"

class Renderer {
public:
    Renderer();
    Renderer(const Renderer& orig);
    virtual ~Renderer();

    bool initResources();
    void freeResources();

    void mainLoop   (SDL_Window*);
    void render     (SDL_Window*);
    void drawModel  (Model* model);
    void drawShape  (Shape* shape, Matrix* matrix);
private:
    GLuint program;
    GLint attribute_coord2d;
    Model* model[256];
};

#endif /* RENDERER_H */

