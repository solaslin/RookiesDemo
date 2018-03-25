#version 100
precision highp float;

uniform vec4 mtrColor;
uniform sampler2D reflectMap;
uniform vec3 _ROOKIES_AmbientColor;
uniform vec3 _ROOKIES_MainLightColor;
uniform vec4 speculars;     // color, shine
uniform vec2 reflConst;     // min fresnel factor: larger value -> larger reflection range / reflection power
//uniform vec2 diffSpecInstens;     // diffuse Intense, specular Intense

varying vec3 vEyeVec;
varying vec3 vNormalVec;
varying vec3 vLightVec;				// direction to light
varying vec3 vHalfVec;

void main()
{		
    float diff = max( 0.0, dot( normalize(vLightVec), vNormalVec) );
    float spec = pow( max(0.0, dot( vNormalVec, normalize(vHalfVec) ) ), speculars.a);
    //float diff = max( 0.0, dot( normalize(wLightVec), wNor) ) * diffSpecInstens.x;
    //float spec = pow( max(0.0, dot( wNor, normalize(wHalfVec) ) ), speculars.a) * diffSpecInstens.y;

    vec3 litColor = mtrColor.rgb * _ROOKIES_MainLightColor * diff;
    litColor += speculars.rgb * spec;
    litColor += ((1.0 - diff) * 0.15 + 0.4) * _ROOKIES_AmbientColor;

    vec3 refl = reflect( vEyeVec, vNormalVec );
    //float m = 2.0 * sqrt( pow( refl.x, 2.0 ) + pow( refl.y, 2.0 ) + pow( -refl.z + 1.0, 2.0 ) );
    //vec2 reflUV = refl.xy / m + 0.5;
    vec2 reflUV = vec2( atan(refl.x, -refl.z) / (2.0 * 3.1415926), asin(refl.y) / 3.1415926);       // use atan(x,y) instead of atan(x/y)
    reflUV += 0.5;

    vec3 reflColor = texture2D( reflectMap, reflUV ).rgb;

    float factor = 1.0 - max( 0.0, dot(vNormalVec, -vEyeVec) );
    factor = ((1.0 - reflConst.x) * factor + reflConst.x) * reflConst.y;
    gl_FragData[0] = vec4( mix(litColor, reflColor, factor), mtrColor.a);
}
