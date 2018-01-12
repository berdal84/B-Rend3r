#pragma once

#include <stdlib.h>
#include <math.h>
#include "Trigonometry.h"

namespace brd{
    class Transform
    {
        public:
            Transform();
            Transform(const mat4&);
            ~Transform();
            
            /* Move the transform alongXYZ axis by an offset */
            void translate    (vec3 _offset);

            /* rotate the transform alongXYZ axis by an EulerXYZ angle */
            void rotate       (vec3 _offset);

            /* Set the scale (overwrite existing scale) of the transform */
            void setScale     (vec3 _scale){scale = _scale;};

            /* Set the XYZ position (overwrite) of the transform */
            void setPosition  (vec3 _position){position = _position; }

            /* Set the XYZ euler angles (overwrite) of the transform */
            void setRotation  (vec3 _rotation){rotation = _rotation; }

            /* Get the current position of the transform */
            vec3 getPosition  ()const{return position;}

            /* Update matrix accordinf to position, rotation and scale */
            void updateMatrix ();

            /* Return the matrix (you should call updateMatrix() before
               to be sure any modification has been trasnfered to the matrix */
            mat4 getMatrix()const {return matrix;}

            /* Return the inverted matrix   (inv(A) * A = A * inv(A) = Identity )*/
            mat4 getMatrixInverse(){ return matrix.getInverse(); }

            /* instantiate a new 4x4 matrix that perform a translation */
            static mat4 Translate (vec3 _position);

            /* instantiate a new 4x4 matrix taht perform an EulerXYZ rotation */
            static mat4 Rotate    (vec3 _rotation);

            /* instantiate a new 4x4 matrix that perform a scale */
            static mat4 Scale     (vec3 _scale);

        private:  

            vec3 position;
            vec3 rotation;
            vec3 scale; 
            mat4 matrix;   
    };
}