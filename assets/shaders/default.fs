#version 100
precision highp float;
uniform vec4 outColor;

void main()
{
	gl_FragData[0] = outColor;
}
