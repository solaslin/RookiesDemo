#version 100
precision highp float;

uniform vec3 tintColor;

varying vec3 wNormal;
varying vec2 outUV;

void main()
{
    vec3 outColor = tintColor * ( ( wNormal + 1.0 ) * 0.5 );    
	gl_FragData[0] = vec4( outColor, 1.0);
}
