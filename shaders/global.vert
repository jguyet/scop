#version 410

in vec3 a_pos;
in vec3 a_norm;
in vec3 a_texCoord;

uniform mat4 u_projMatrix;
uniform mat4 u_viewMatrix;
uniform mat4 u_modelMatrix;

void main()
{
	vec4 mpos = (u_projMatrix * u_viewMatrix * u_modelMatrix) * vec4(a_pos, 1.0);

	gl_Position = mpos;
}
