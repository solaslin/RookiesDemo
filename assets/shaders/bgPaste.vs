#version 100
precision highp float;

uniform mat4 _ROOKIES_MVPMtx;
attribute vec3 inPos;
varying vec2 screenPos;

void main()
{
	gl_Position = _ROOKIES_MVPMtx * vec4(inPos, 1.0);
	screenPos = gl_Position.xy / gl_Position.w;
	screenPos = (screenPos + 1.0) * 0.5;
	screenPos.y = 1.0 - screenPos.y;
}