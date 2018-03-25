#version 100
precision highp float;

uniform sampler2D alphaMap;
uniform sampler2D oriBG;
varying vec2 uvCoord;
varying vec2 screenPos;

void main()
{
    float alpha = texture2D(alphaMap, uvCoord).r;
	gl_FragData[0] = vec4( texture2D(oriBG, screenPos).rgb, alpha);
}
