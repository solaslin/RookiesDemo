#version 100
precision highp float;

uniform mat4 _ROOKIES_MVPMtx;
attribute vec3 inPos;
attribute vec4 inColor;
varying vec4 vertColor;

void main()
{
	gl_Position = _ROOKIES_MVPMtx * vec4(inPos, 1.0);
	vertColor = inColor;
}
