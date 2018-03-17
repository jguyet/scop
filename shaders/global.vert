#version 410

in vec3 a_v;
in vec2 a_vt;
in vec3 a_color;

uniform mat4 u_projMatrix;
uniform mat4 u_viewMatrix;
uniform mat4 u_modelMatrix;

out vec2 v_vt;
out vec3 v_color;
out vec2 v_vt_plane;

void main()
{
	vec4 mpos = (u_projMatrix * u_viewMatrix * u_modelMatrix) * vec4(a_v, 1.0);

	v_vt = a_vt;
	v_color = a_color;
	v_vt_plane = vec3(vec3(a_v.xyz) / 2).zy * 3;
	gl_Position = mpos;
}
