#version 410

uniform u_material {
	vec4 diffuse;
	vec4 ambient;
	vec4 specular;
	vec4 emissive;
	float shininess;
	int diffuse_texture;
	int specular_texture;
	int ambiante_texture;
};

out vec4 o_color;

void main()
{
	o_color = vec4(diffuse.xyz, 1.0);
}
