/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   loop.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jguyet <jguyet@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/08 13:19:12 by jguyet            #+#    #+#             */
/*   Updated: 2018/03/08 13:21:27 by jguyet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "scop.h"

t_matrix4f		*build_model_rotation(t_model *model)
{
	t_matrix4f	*model_matrix;

	model_matrix = matrix4f_identity(1.0f);
	model_matrix = matrix_rotate(model_matrix,\
		model->transform.rotation.y * DEGREE_TO_RADIAN,\
		new_vector3f(0.0f, 1.0f, 0.0f));
	model_matrix = matrix_rotate(model_matrix,\
		model->transform.rotation.x * DEGREE_TO_RADIAN,\
		new_vector3f(1.0f, 0.0f, 0.0f));
	model_matrix = matrix_rotate(model_matrix,\
		model->transform.rotation.z * DEGREE_TO_RADIAN,\
		new_vector3f(0.0f, 0.0f, 1.0f));
	return (model_matrix);
}

t_matrix4f		*build_model_scale(t_model *model)
{
	t_matrix4f	*model_matrix;

	model_matrix = get_matrix_scale(&model->transform.scale);
	return (model_matrix);
}

t_matrix4f		*build_model_position(t_model *model)
{
	t_matrix4f	*model_matrix;

	model_matrix = matrix_translate(&model->transform.position);
	return (model_matrix);
}

void			draw_scene(t_scop *s, t_model *model, t_matrix4f *tmp_matrix)
{
	t_matrix4f	*scale_matrix;
	t_matrix4f	*rotate_matrix;
	t_matrix4f	*translate_matrix;
	t_matrix4f	*model_matrix;

	build_look_at_projection(s->camera, s->screen);
	rotate_matrix = build_model_rotation(model);
	scale_matrix = build_model_scale(model);
	translate_matrix = build_model_position(model);
	tmp_matrix = matrix4f_mul(rotate_matrix, scale_matrix);
	model_matrix = matrix4f_mul(tmp_matrix, translate_matrix);
	draw_model(model, model_matrix,\
		s->camera->view, s->camera->projection);
	destruct_matrix4f(model_matrix);
	destruct_matrix4f(scale_matrix);
	destruct_matrix4f(translate_matrix);
	destruct_matrix4f(rotate_matrix);
	destruct_matrix4f(tmp_matrix);
}

void			render_loop(t_scop *s)
{
	SDL_Event	event;

	while (1)
	{
		SDL_GL_SwapWindow(s->window);
		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
		glClearColor(0.0f, 0.0f, 1.0f, 0.0f);
		draw_scene(s, s->model, NULL);
		loop_control(s, s->model);
		if (get_key(s->keyboard, 41))
			return ;
		while (SDL_PollEvent(&event))
		{
			if (event.type == SDL_QUIT)
			{
				return ;
			}
		}
	}
}
