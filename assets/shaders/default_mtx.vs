#version 100
precision highp float;
uniform mat4 MVPMtx;
attribute vec3 inPos;

void main()
{
	gl_Position = MVPMtx * vec4(inPos, 1.0);
}