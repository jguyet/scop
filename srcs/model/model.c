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

t_model			*new_model(const char *file_path, t_shader *shader)
{
	t_model		*m;
	char		*base_name;

	if (!(m = (struct s_model*)malloc(sizeof(struct s_model))))
		return (NULL);
	initialize_transform(&m->transform);
	m->transform.scale.x = 1.0f;
	m->transform.scale.y = 1.0f;
	m->transform.scale.z = 1.0f;
	m->shader = shader;
	m->glewglew = new_glewglew();
	m->glewglew->initializer.absolute_path = file_absolute_path(file_path);
	base_name = file_base_name(file_path);
	if (m->glewglew->build_file(m->glewglew, base_name) == 0)
	{
		return (NULL);
	}
	free(base_name);
	build_model(m, true);
	return (m);
}

void			build_model(t_model *model, BOOLEAN texture)
{
	if (texture == true)
		load_model_textures(model);
	build_model_shader(model);
	build_model_vao(model, texture);
}

void			destruct_model(t_model *model)
{
	destruct_glewglew(model->glewglew);
	free(model);
}

void			load_model_textures(t_model *model)
{
	int		i;
	t_mesh	*mesh;

	i = -1;
	while (++i < model->glewglew->meshs_size)
	{
		mesh = model->glewglew->meshs[i];

		if (mesh->material->block.diffuse_texture)
		{
			mesh->material->diffuse_texture_id =\
			load_bmp(mesh->material->diffuse_texture);
		}
	}
}

void			build_model_shader(t_model *model)
{
	model->vertex_location = \
	glGetAttribLocation(model->shader->id, "a_v");
	model->texture_location = \
	glGetAttribLocation(model->shader->id, "a_vt");
	model->color_location = \
	glGetAttribLocation(model->shader->id, "a_color");
	model->projection_location = \
	glGetUniformLocation(model->shader->id, "u_projMatrix");
	model->view_location = \
	glGetUniformLocation(model->shader->id, "u_viewMatrix");
	model->model_location = \
	glGetUniformLocation(model->shader->id, "u_modelMatrix");
	model->material_location = \
	glGetUniformBlockIndex(model->shader->id, "u_material");
	model->texture_diffuse_location = \
	glGetUniformLocation(model->shader->id, "u_texture_diffuse");
	glBindFragDataLocation(model->shader->id, 0, "o_color");
}

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
	t_mesh *mesh, BOOLEAN texture)
{
	BOOLEAN has_texture;

	(void)model;
	has_texture = false;
	if (texture && mesh->material->block.diffuse_texture)
	{
		has_texture = true;
		mesh->material->block.diffuse_texture = false;
	}
	add_uniform_buffer((void*)&mesh->material->block,\
	sizeof(struct s_material_gl), &mesh->material_buffer_block_location);
	if (has_texture)
	{
		mesh->material->block.diffuse_texture = true;
	}
}

void			build_vao(t_model *model, t_mesh *mesh, BOOLEAN texture)
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
	{
		add_array_to_buffer_element(&mesh->vertexs[0],\
			sizeof(float) * (3 * mesh->vertexs_length), 3,\
			model->vertex_location);
	}
	if (mesh->texturecoords_length > 0)
	{
		add_array_to_buffer_element(&mesh->texturecoords[0],\
			sizeof(float) * (2 * mesh->texturecoords_length), 2,\
			model->texture_location);
	}
	if (mesh->colors_length > 0)
	{
		add_array_to_buffer_element(&mesh->colors[0],\
			sizeof(float) * (3 * mesh->colors_length), 3,\
			model->color_location);
	}
	glBindVertexArray(0);
	build_material_buffer(model, mesh, texture);
}

void			build_model_vao(t_model *model, BOOLEAN texture)
{
	int		i;

	i = 0;
	while (i < model->glewglew->meshs_size)
	{
		build_vao(model, model->glewglew->meshs[i], texture);
		i++;
	}
}

void			draw_model(t_model *model, t_matrix4f *m,\
	t_matrix4f *v, t_matrix4f *p)
{
	int		i;
	t_mesh	*mesh;

	glUseProgram(model->shader->id);
	glUniformMatrix4fv(model->projection_location,\
		1, GL_FALSE, &p->matrix[0][0]);
	glUniformMatrix4fv(model->view_location, 1, GL_FALSE, &v->matrix[0][0]);
	glUniformMatrix4fv(model->model_location, 1, GL_FALSE, &m->matrix[0][0]);
	glUniform1i(model->texture_diffuse_location, 0);
	i = -1;
	while (++i < model->glewglew->meshs_size)
	{
		mesh = model->glewglew->meshs[i];
		glBindBufferRange(GL_UNIFORM_BUFFER, model->material_location,\
			mesh->material_buffer_block_location,\
			0, sizeof(struct s_material_gl));
		if (mesh->material->block.diffuse_texture)
			glBindTexture(GL_TEXTURE_2D, mesh->material->diffuse_texture_id);
		glBindVertexArray(mesh->vao);
		glDrawElements(GL_TRIANGLES,\
			mesh->faces_length * 3, GL_UNSIGNED_SHORT, 0);
		glBindVertexArray(0);
	}
	glUseProgram(0);
}
