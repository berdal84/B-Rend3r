#pragma once

#include "Transform.h"
#include "Shape.h"
#include <iostream>
#include <string>
#include "Component.h"
#include <vector>

namespace brd{
    /* Forward declarations */
    class Transform;
    class Physics;

    /*
        class Model :

        This class is a common 3d object composed by a set of Components.
        Each component manages special functions (read Component.h).

    */
    class Model
    {
        public:
            Model();
            

            virtual ~Model();            
        
            unsigned int    getId       ()                     { return id; }
            void            setId       (unsigned int _val)     { id = _val; }
            void            setName     (const char* _name)         { name = _name;}
            const char*     getName     ()                   { return name.c_str();}

            /* Add a new component to the Model */
            template<class T>
            void            addComponent(T* _component)
            {
                this->components[T::s_type] = _component;
            }
            
            /* Return true if the model has this component type */
            template<class T>
            bool            hasComponent(){ return getComponent<T>() != nullptr; }

            /* Return a pointer to the component.
               User is responsible for calling hasComponent<T>() before. */
            template<class T>
            T*              getComponent(){ return (T*)(this->components[T::s_type]);}

            /* Create a new model */
            static Model*   Create(const char *_name);

        private:
            std::vector<void*> components; // all components are store here
            std::string             name;
            unsigned int            id;

        friend std::ostream& operator<<(std::ostream& stream, Model* model){ stream << model->getName(); return stream;}
    };
}