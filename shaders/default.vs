//#version 100  // OpenGL ES 2.0
#version 120  // OpenGL 2.1

attribute vec2 coord2d;
attribute vec2 position;

void main(void) {
  gl_Position = vec4(coord2d.x + position.x, coord2d.y + position.y,0,1); 
  //gl_Position = vec4(coord2d,0, 1); 
}
