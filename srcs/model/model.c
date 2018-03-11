/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   model.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jguyet <jguyet@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/10 16:22:39 by jguyet            #+#    #+#             */
/*   Updated: 2018/03/10 16:27:25 by jguyet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "scop.h"
#include "glewglew.h"

t_model			*new_model(const char *file_path, t_shader *shader)
{
	t_model		*m;

	if (!(m = (struct s_model*)malloc(sizeof(struct s_model))))
		return (NULL);
	m->shader = shader;
	m->glewglew = new_glewglew();
	if (glewglew_build_file(m->glewglew, file_path, ".obj") == 0)
	{
		return (NULL);
	}
	load_model_textures(m);
	build_model_shader(m);
	build_model_vao(m);
	return (m);
}

void			destruct_model(t_model *model)
{
	destruct_glewglew(model->glewglew);
	free(model);
}

void			load_model_textures(t_model *model)
{
	(void)model;
}

void			build_model_shader(t_model *model)
{
	model->vertex_location = glGetAttribLocation(model->shader->id,"a_pos");
	model->projection_location = glGetUniformLocation(model->shader->id, "u_projMatrix");
	model->view_location = glGetUniformLocation(model->shader->id, "u_viewMatrix");
	model->model_location = glGetUniformLocation(model->shader->id, "u_modelMatrix");

	glBindFragDataLocation(model->shader->id, 0, "o_color");
}

void			build_model_vao(t_model *model)
{
	int i;
	t_mesh	*mesh;
	GLuint	buffer;

	i = -1;
	while (++i < model->glewglew->meshs_size)
	{
		mesh = model->glewglew->meshs[i];

		ft_printf("min %f,%f,%f max %f,%f,%f\n", mesh->min.x, mesh->min.y, mesh->min.z, mesh->max.x, mesh->max.y, mesh->max.z);
		ft_printf("center %f,%f,%f\n", ((mesh->max.x + mesh->min.x) / 2), ((mesh->max.y + mesh->min.y) / 2), ((mesh->max.z + mesh->min.z) / 2));

		glGenVertexArrays(1,&mesh->vao);
		glBindVertexArray(mesh->vao);
		glGenBuffers(1, &buffer);
        glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, buffer);
        glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(unsigned int) * mesh->faces_length * 3, &mesh->faces[0], GL_STATIC_DRAW);
		if (mesh->vertexs_length > 0)
		{
			for (int o = 0; o < (mesh->vertexs_length * 3); o += 3)
			{
				mesh->vertexs[o + 0] = mesh->vertexs[o + 0] - (float)((mesh->max.x + mesh->min.x) / 2.f);
				mesh->vertexs[o + 1] = mesh->vertexs[o + 1] - (float)((mesh->max.y + mesh->min.y) / 2.f);
				mesh->vertexs[o + 2] = mesh->vertexs[o + 2] - (float)((mesh->max.z + mesh->min.z) / 2.f);
			}

			glGenBuffers(1, &buffer);
            glBindBuffer(GL_ARRAY_BUFFER, buffer);
            glBufferData(GL_ARRAY_BUFFER, sizeof(float) * 3 * mesh->vertexs_length, &mesh->vertexs[0], GL_STATIC_DRAW);
            glEnableVertexAttribArray(model->vertex_location);
            glVertexAttribPointer(model->vertex_location, 3, GL_FLOAT, false, 0, 0);
		}
		glBindVertexArray(0);
        glBindBuffer(GL_ARRAY_BUFFER, 0);
        glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, 0);
	}
}

void			draw_model(t_model *model, t_matrix4f *m, t_matrix4f *v, t_matrix4f *p)
{
	int	i;
	t_mesh	*mesh;

	glUseProgram(model->shader->id);

	glUniformMatrix4fv(model->projection_location, 1, GL_FALSE, &p->matrix[0][0]);
	glUniformMatrix4fv(model->view_location, 1, GL_FALSE, &v->matrix[0][0]);
	glUniformMatrix4fv(model->model_location, 1, GL_FALSE, &m->matrix[0][0]);
	i = -1;
	while (++i < model->glewglew->meshs_size)
	{
		mesh = model->glewglew->meshs[i];
		glBindVertexArray(mesh->vao);
		glDrawElements(GL_TRIANGLES,  mesh->faces_length * 3, GL_UNSIGNED_INT, 0);
		glBindVertexArray(0);
	}

	glUseProgram(0);
}
