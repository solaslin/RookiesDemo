#version 100
precision highp float;
uniform sampler2D colorMap;
varying vec2 uvCoord;

void main()
{
	gl_FragData[0] = texture2D(colorMap, uvCoord);
}
