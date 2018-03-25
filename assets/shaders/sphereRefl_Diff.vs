#version 100
precision highp float;

uniform mat4 _ROOKIES_MVPMtx;
uniform mat4 _ROOKIES_WorldViewMtx;
uniform mat4 _ROOKIES_WorldMtx;
uniform vec3 _ROOKIES_MainLightDir;		// direction: begin from light

attribute vec3 inPos;
attribute vec2 inUV;
attribute vec3 inNormal;

varying vec3 vEyeVec;
varying vec3 vNormalVec;
varying vec3 vLightVec;				// direction to light
varying vec3 vHalfVec;
varying vec2 uvCoord;

void main()
{	
	gl_Position = _ROOKIES_MVPMtx * vec4(inPos, 1.0);	
	uvCoord = inUV;

	vEyeVec = normalize( vec3( _ROOKIES_WorldViewMtx * vec4( inPos, 1.0 )) );
    vNormalVec = normalize( vec3(_ROOKIES_WorldViewMtx * vec4(inNormal, 0.0)) );

	// light vector & half vector:
	vLightVec = -normalize( vec3(_ROOKIES_WorldViewMtx * vec4(_ROOKIES_MainLightDir, 0.0)) );
	vHalfVec = normalize( vLightVec - vEyeVec );
}