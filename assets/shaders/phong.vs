#version 100
precision highp float;

uniform mat4 _ROOKIES_MVPMtx;
uniform mat4 _ROOKIES_WorldMtx;
uniform vec3 _ROOKIES_MainLightDir;		// direction: begin from light

attribute vec3 inPos;
attribute vec2 inUV;
attribute vec3 inNormal;

varying vec3 wLightVec;				// direction to light
varying vec3 wHalfVec;
varying vec3 wNor;

void main()
{	
	gl_Position = _ROOKIES_MVPMtx * vec4(inPos, 1.0);	

	// normal in world Space
	wNor = normalize( (_ROOKIES_WorldMtx * vec4(inNormal, 0.0)).xyz );

	// view vec:
	// world space v-position = eye-to-point vector in view space --> neg = point-to-eye vector
	vec3 viewVec = -normalize( (_ROOKIES_WorldMtx * vec4(inPos, 1.0)).xyz );

	// light vector & half vector:
	wLightVec = -_ROOKIES_MainLightDir;
	wHalfVec = normalize( wLightVec + viewVec );
}