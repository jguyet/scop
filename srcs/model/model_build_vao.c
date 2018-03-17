/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   model.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jguyet <jguyet@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/16 05:11:38 by jguyet            #+#    #+#             */
/*   Updated: 2018/03/16 05:11:40 by jguyet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "scop.h"
#include "glewglew.h"

void			add_array_to_buffer_element(void *array, \
	unsigned int array_size, unsigned int element_size, unsigned int location)
{
	GLuint	buffer;

	glGenBuffers(1, &buffer);
	glBindBuffer(GL_ARRAY_BUFFER, buffer);
	glBufferData(GL_ARRAY_BUFFER, array_size, array, GL_STATIC_DRAW);
	glEnableVertexAttribArray(location);
	glVertexAttribPointer(location, element_size, GL_FLOAT, false, 0, 0);
}

void			add_uniform_buffer(void *structure,\
	unsigned int element_size, unsigned int *location)
{
	glGenBuffers(1, location);
	glBindBuffer(GL_UNIFORM_BUFFER, *location);
	glBufferData(GL_UNIFORM_BUFFER, element_size, structure, GL_STATIC_DRAW);
	glBindBuffer(GL_UNIFORM_BUFFER, 0);
}

void			build_material_buffer(t_model *model,\
	t_mesh *mesh)
{
	(void)model;
	if (mesh->material->block.diffuse_texture)
	{
		mesh->material->block.diffuse_texture = false;
	}
	add_uniform_buffer((void*)&mesh->material->block,\
	sizeof(struct s_material_gl), &mesh->material_buffer_block_location);
}

void			build_vao(t_model *model, t_mesh *mesh)
{
	GLuint	buffer;

	glGenVertexArrays(1, &mesh->vao);
	glBindVertexArray(mesh->vao);
	glGenBuffers(1, &buffer);
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, buffer);
	glBufferData(GL_ELEMENT_ARRAY_BUFFER,\
		sizeof(unsigned short) * (3 * mesh->faces_length),\
		&mesh->faces[0], GL_STATIC_DRAW);
	if (mesh->vertexs_length > 0)
		add_array_to_buffer_element(&mesh->vertexs[0],\
			sizeof(float) * (3 * mesh->vertexs_length), 3,\
			model->vertex_location);
	if (mesh->texturecoords_length > 0)
		add_array_to_buffer_element(&mesh->texturecoords[0],\
			sizeof(float) * (2 * mesh->texturecoords_length), 2,\
			model->texture_location);
	if (mesh->colors_length > 0)
		add_array_to_buffer_element(&mesh->colors[0],\
			sizeof(float) * (3 * mesh->colors_length), 3,\
			model->color_location);
	glBindVertexArray(0);
	build_material_buffer(model, mesh);
}

void			build_model_vao(t_model *model)
{
	int		i;

	i = 0;
	while (i < model->glewglew->meshs_size)
	{
		build_vao(model, model->glewglew->meshs[i]);
		i++;
	}
}
