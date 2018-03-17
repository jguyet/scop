#version 410

uniform u_material {
	vec4 diffuse;
	bool has_diffuse_texture;
	bool has_texture_position;
};

uniform	sampler2D u_texture_diffuse;
uniform	float u_iterator;

in vec2 v_vt;
in vec3	v_color;
in vec2 v_vt_plane;

out vec4 o_color;

void main()
{
	vec3	diffuse_color;
	vec3	diffuse_texture_color;
	vec4	color;
	vec3	tmp;
	float	it = (1 - u_iterator);

	if (has_texture_position == false)
	{
		diffuse_texture_color = texture(u_texture_diffuse, v_vt_plane.st).rgb;
	}
	else
	{
		diffuse_texture_color = texture(u_texture_diffuse, v_vt.st).rgb;
	}
	diffuse_color = vec3(v_color.xyz);
	if (it < 1)
	{
		tmp = diffuse_color * u_iterator;
	}
	if (it > 0)
	{
		tmp += diffuse_texture_color * (1 - u_iterator);
	}
	color = vec4(tmp, 1);
	o_color = color;
}
