#version 100
precision highp float;

uniform mat4 _ROOKIES_MVPMtx;
uniform mat4 _ROOKIES_WorldMtx;

attribute vec3 inPos;
attribute vec2 inUV;
attribute vec3 inNormal;

varying vec3 wNormal;
varying vec2 outUV;

void main()
{
	gl_Position = _ROOKIES_MVPMtx * vec4(inPos, 1.0);
	wNormal = normalize( (_ROOKIES_WorldMtx * vec4(inNormal, 0.0)).xyz );
	outUV = inUV;
}
