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

out vec4 o_color;

void main()
{
	vec3 vdiffuse = vec3(diffuse.xyz);
	vec4 color = vec4(vdiffuse.xyz, 1.0);

	if (diffuse_texture == true)
	{
		texture(u_texture_diffuse, v_vt.xy);// * vec4(vdiffuse.xyz, 1.0);
	}
	o_color = color;
}
