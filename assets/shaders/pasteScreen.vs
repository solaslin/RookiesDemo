#version 100
precision highp float;

attribute vec3 inPos;
attribute vec2 inUV;
varying vec2 uvCoord;

void main()
{
    gl_Position = vec4(inPos.xy, 0.999, 1.0);
    uvCoord = inUV;
}
