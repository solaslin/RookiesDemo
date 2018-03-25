#version 100
precision highp float;

uniform sampler2D colorMap;
uniform sampler2D normalMap;
uniform vec3 _ROOKIES_AmbientColor;
uniform vec3 _ROOKIES_MainLightColor;
uniform vec4 mtrColor;
uniform vec4 speculars;     // color, shine

varying vec3 tHalfVec;
varying vec3 tLightVec;			// direction to light
varying vec2 uvCoord;

void main()
{
    vec4 baseColor = texture2D(colorMap, uvCoord.st) * mtrColor;

    vec4 norSpec = texture2D(normalMap, uvCoord.st);
    vec3 normal = norSpec.xyz * 2.0 - 1.0;
    normal.xy *= 1.2;
    normal = normalize(normal);

    float diff = max( 0.0, dot( normalize(tLightVec), normal) );
    float spec = pow( max(0.0, dot( normal, normalize(tHalfVec) ) ), speculars.a);
    float diffSum = diff;
    vec3 finalColor = baseColor.rgb * _ROOKIES_MainLightColor * diff;
    finalColor += speculars.rgb * spec;

    finalColor += ((1.0 - diffSum) * 0.15 + 0.4) * _ROOKIES_AmbientColor;
	gl_FragData[0] = vec4(finalColor, baseColor.a);
}
