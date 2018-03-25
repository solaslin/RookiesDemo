#version 100
precision highp float;

uniform mat4 _ROOKIES_MVPMtx;
uniform mat4 _ROOKIES_WorldMtx;
uniform vec3 _ROOKIES_MainLightDir;		// direction: begin from light
uniform vec3 _ROOKIES_SecLightDir;		// direction: begin from light

attribute vec3 inPos;
attribute vec2 inUV;
attribute vec3 inNormal;
attribute vec4 inTangent;

varying vec3 tHalfVec1;
varying vec3 tLightVec1;			// direction to light
varying vec3 tHalfVec2;
varying vec3 tLightVec2;			// direction to light
varying vec2 uvCoord;

//const vec3 Light1Dir = vec3(1.0, 0.0, -1.5); // test: directional light direction in VIEW-SPACE
//const vec3 Light2Dir = vec3(0.4, -0.2, -1.0); // test: directional light direction in VIEW-SPACE

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


	// light vec 1:
	//tLightVec1 = -normalize( (_ROOKIES_WorldMtx * vec4(_ROOKIES_mainLightDir, 0.0)).xyz );
	tLightVec1 = -_ROOKIES_MainLightDir;
	tLightVec1 = tLightVec1 * wToTngMtx;
	tHalfVec1 = normalize( tLightVec1 + tViewVec );

	// light vec 2:
	//tLightVec2 = -normalize( (_ROOKIES_WorldMtx * vec4(light2DirectionW, 0.0)).xyz );
	tLightVec2 = -_ROOKIES_SecLightDir;
	tLightVec2 = tLightVec2 * wToTngMtx;
	tHalfVec2 = normalize( tLightVec2 + tViewVec );	
}
