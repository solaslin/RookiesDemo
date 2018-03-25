#version 100
precision highp float;

uniform mat4 _ROOKIES_MVPMtx;
attribute vec3 inPos;
attribute vec2 inUV;
varying vec2 uvCoord;
varying vec2 screenPos;

void main()
{
	gl_Position = _ROOKIES_MVPMtx * vec4(inPos, 1.0);
	uvCoord = inUV;
	screenPos = gl_Position.xy / gl_Position.w;
	screenPos = (screenPos + 1.0) * 0.5;
	screenPos.y = 1.0 - screenPos.y;
}