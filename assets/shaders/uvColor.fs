#version 100
precision highp float;
uniform sampler2D colorMap;
varying vec2 uvCoord;

void main()
{
	vec4 color = texture2D(colorMap, uvCoord);
	color.rgb *= uvCoord.xxx;
	gl_FragData[0] = color;
}
