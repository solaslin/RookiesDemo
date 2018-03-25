#version 100
precision highp float;

uniform sampler2D colorMap;
uniform sampler2D normalSpecSampler;
uniform vec3 _ROOKIES_AmbientColor;
uniform vec3 _ROOKIES_MainLightColor;
uniform vec3 _ROOKIES_SecLightColor;
uniform vec4 speculars;     // color, shine
uniform vec4 speculars2;     // color, shine
uniform vec2 diffSpecInstens;     // diffuse Intense, specular Intense

varying vec3 tHalfVec1;
varying vec3 tLightVec1;			// direction to light
varying vec3 tHalfVec2;
varying vec3 tLightVec2;			// direction to light
varying vec2 uvCoord;

void main()
{
    vec4 baseColor = texture2D(colorMap, uvCoord.st);

    vec4 norSpec = texture2D(normalSpecSampler, uvCoord.st);
    float gloss = norSpec.w;
    vec3 normal = norSpec.xyz * 2.0 - 1.0;
    normal.xy *= 1.2;
    normal = normalize(normal);


    float diff = max( 0.0, dot( normalize(tLightVec1), normal) ) * diffSpecInstens.x;
    float spec = pow( max(0.0, dot( normal, normalize(tHalfVec1) ) ), speculars.a) * diffSpecInstens.y;
    float diffSum = diff;
    vec3 finalColor = baseColor.rgb * _ROOKIES_MainLightColor * diff;
    finalColor += speculars.rgb * spec * gloss;

    diff = max( 0.0, dot( normalize(tLightVec2), normal) );
    spec = pow( max(0.0, dot( normal, normalize(tHalfVec2) ) ), speculars2.a) * diffSpecInstens.y;
    diffSum += diff;
    finalColor += baseColor.rgb * _ROOKIES_SecLightColor * diff;
    finalColor += speculars2.rgb * spec * gloss;

    finalColor += ((1.0 - diffSum) * 0.15 + 0.4) * _ROOKIES_AmbientColor;
    //finalColor = clamp(finalColor, 0.0, 1.0);

    // debug:
    //color.rgb = vec3(spec, spec, spec);
    //color.rgb = ( tLightVec + 1 ) * 0.5;
	gl_FragData[0] = vec4(finalColor, baseColor.a);
}
