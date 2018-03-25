#version 100
precision highp float;

varying vec3 wToEyeVec;
varying vec3 wNormal;
varying vec2 uvCoord;

void main()
{
    float vDotN = dot( normalize(wToEyeVec), normalize(wNormal) );
    float scale = (vDotN > 0.5)? 1.0 : 0.0;
    
	gl_FragData[0] = vec4( scale,scale,scale, 1.0 );
}
