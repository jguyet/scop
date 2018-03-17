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
	m->iterator = 0.0f;
	m->draw_mode = GL_TRIANGLES;
	m->glewglew = new_glewglew();
	m->glewglew->initializer.absolute_path = file_absolute_path(file_path);
	base_name = file_base_name(file_path);
	if (m->glewglew->build_file(m->glewglew, base_name) == 0)
	{
		return (NULL);
	}
	free(base_name);
	build_model(m);
	return (m);
}

void			build_model(t_model *model)
{
	build_model_textures(model);
	build_model_shader(model);
	build_model_vao(model);
}

void			destruct_model(t_model *model)
{
	destruct_glewglew(model->glewglew);
	free(model);
}

void			draw_model(t_model *model, t_matrix4f *m,\
	t_matrix4f *v, t_matrix4f *p)
{
	int		i;
	t_mesh	*mesh;

	glUseProgram(model->shader->id);
	glUniformMatrix4fv(model->projection_location,\
		1, GL_FALSE, &p->matrix[0][0]);
	glUniform1f(model->iterator_location, model->iterator);
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
		glDrawElements(model->draw_mode,\
			mesh->faces_length * 3, GL_UNSIGNED_SHORT, 0);
		glBindVertexArray(0);
	}
	glUseProgram(0);
}
