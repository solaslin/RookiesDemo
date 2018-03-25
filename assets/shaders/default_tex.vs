#version 100
precision highp float;

uniform mat4 _ROOKIES_MVPMtx;
attribute vec3 inPos;
attribute vec2 inUV;
varying vec2 uvCoord;
void main()
{
	gl_Position = _ROOKIES_MVPMtx * vec4(inPos, 1.0);
	uvCoord = inUV;
}
