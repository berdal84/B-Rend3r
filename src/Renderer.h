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
#pragma once

#include <iostream>
#include <cstdlib>
#include <vector>

#include <GL/glew.h>
#include <SDL2/SDL.h>
#include "Math.h"

namespace brd{

    /* Forward declaration */
    class Shader;
    class Shape;
    class Model;
    class Transform;
    class Camera;

    class Renderer {
    public:
        Renderer(vec2 _viewportSize);
        Renderer(const Renderer& orig);
        virtual ~Renderer();

        bool initResources();
        void freeResources();

        bool update     (SDL_Window*, float _dt);
        void render     (SDL_Window*);
        void addModel   (Model*);
        void setCurrentCamera(Camera* _camera);
        
    private:
        void drawModel  (Model* model);
        void drawShape  (Shape* shape, Transform* matrix);
        Camera* currentCamera = nullptr;
        GLuint program;
        GLint attribute_coord2d;
        std::vector<Model*> model;
        vec2 viewportSize;
    };
}
