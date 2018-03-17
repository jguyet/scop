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
	model->iterator_location = \
	glGetUniformLocation(model->shader->id, "u_iterator");
	glBindFragDataLocation(model->shader->id, 0, "o_color");
}
