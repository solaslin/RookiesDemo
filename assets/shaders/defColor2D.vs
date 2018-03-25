#version 100
precision highp float;
attribute vec3 inPos;
//uniform mat4 VP;

void main()
{
	//gl_Position = VP * vec4(inPos, 1.0);
	gl_Position = vec4(inPos.xy, 0.9, 1.0);

	// useless in desktop...only for mobile
	gl_PointSize = 8.0;	
}
