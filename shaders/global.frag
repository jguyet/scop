#version 410

uniform u_material {
	vec4 diffuse;
	vec4 ambient;
	vec4 specular;
	vec4 emissive;
	float shininess;
	bool diffuse_texture;
	bool specular_texture;
	bool ambiante_texture;
};

uniform	sampler2D u_texture_diffuse;

in vec2 v_vt;
in vec3	v_color;

out vec4 o_color;

void main()
{
	vec4 color;

	if (diffuse_texture == true)
	{
		color = vec4(texture(u_texture_diffuse, v_vt.st).rgb, 1);
	}
	else
	{
		color = vec4(v_color.xyz, 1.0);
	}
	o_color = color;
}
