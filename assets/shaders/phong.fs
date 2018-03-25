#version 100
precision highp float;

uniform vec4 mtrColor;
uniform vec3 _ROOKIES_AmbientColor;
uniform vec3 _ROOKIES_MainLightColor;
uniform vec4 speculars;          // color, shine
uniform vec2 diffSpecInstens;     // diffuse Intense, specular Intense

//const vec3 pToLightDir = vec3(1.0, 0.0, -1.5);
varying vec3 wLightVec;		// direction to light
varying vec3 wHalfVec;
varying vec3 wNor;

void main()
{		
    float diff = max( 0.0, dot( normalize(wLightVec), wNor) ) * diffSpecInstens.x;
    float spec = pow( max(0.0, dot( wNor, normalize(wHalfVec) ) ), speculars.a) * diffSpecInstens.y;

    vec3 finalColor = mtrColor.rgb * _ROOKIES_MainLightColor * diff;
    finalColor += speculars.rgb * spec;
    finalColor += ((1.0 - diff) * 0.15 + 0.4) * _ROOKIES_AmbientColor;

    gl_FragData[0] = vec4(finalColor, mtrColor.a);
    //gl_FragData[0] = mtrColor;
}
