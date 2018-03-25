#version 100
precision highp float;

uniform mat4 _ROOKIES_MVPMtx;
uniform mat4 _ROOKIES_WorldMtx;
uniform vec3 _ROOKIES_MainLightDir;		// direction: begin from light

attribute vec3 inPos;
attribute vec2 inUV;
attribute vec3 inNormal;
attribute vec4 inTangent;

varying vec3 tHalfVec;
varying vec3 tLightVec;			// direction to light
varying vec2 uvCoord;

void main()
{
	gl_Position = _ROOKIES_MVPMtx * vec4(inPos, 1.0);
	uvCoord = inUV;
	
	// normal in world space
	vec3 wNormal = normalize( (_ROOKIES_WorldMtx * vec4(inNormal, 0.0)).xyz );

	// tangent in world space
	vec3 wTangent = normalize( (_ROOKIES_WorldMtx * vec4(inTangent.xyz, 0.0)).xyz );

	// binormal in world space
	vec3 wBinormal = cross(wNormal, wTangent) * inTangent.w;
	mat3 wToTngMtx = mat3( wTangent, wBinormal, wNormal );

	// view vec:
	// world space v-position = eye-to-point vector in view space --> neg = point-to-eye vector
	vec3 tViewVec = -normalize( (_ROOKIES_WorldMtx * vec4(inPos, 1.0)).xyz );
	tViewVec =  tViewVec * wToTngMtx;

	// light vec:
	//tLightVec = -normalize( (_ROOKIES_WorldMtx * vec4(_ROOKIES_mainLightDir, 0.0)).xyz );
	tLightVec = -_ROOKIES_MainLightDir;
	tLightVec = tLightVec * wToTngMtx;
	tHalfVec = normalize( tLightVec + tViewVec );
}
