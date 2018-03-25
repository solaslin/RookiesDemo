#version 100
precision highp float;

uniform sampler2D oriBG;
varying vec2 screenPos;

void main()
{
	gl_FragData[0] = texture2D(oriBG, screenPos);
}
