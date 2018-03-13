#version 410

in vec3 a_v;
in vec2 a_vt;

uniform mat4 u_projMatrix;
uniform mat4 u_viewMatrix;
uniform mat4 u_modelMatrix;

out vec2 v_vt;

void main()
{
	vec4 mpos = (u_projMatrix * u_viewMatrix * u_modelMatrix) * vec4(a_v, 1.0);

	v_vt = a_vt;
	gl_Position = mpos;
}
