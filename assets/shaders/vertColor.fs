#version 100
precision highp float;

varying vec4 vertColor;

void main()
{
	gl_FragData[0] = vertColor;
}
