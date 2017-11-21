//#version 100  // OpenGL ES 2.0
#version 120  // OpenGL 2.1

attribute vec2 coord2d;
uniform   mat4 worldMatrix;
uniform   mat4 viewMatrix;
void main(void) {
  gl_Position = viewMatrix * worldMatrix * vec4(coord2d.x, coord2d.y,0.0,1.0); 
}
