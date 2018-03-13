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

void			draw_scene(t_scop *s, float rotation_cicle)
{
	t_model		*current_model;
	t_matrix4f	*model_matrix;
	float		degree;

	build_look_at_projection(s->camera, s->screen);
	current_model = (t_model*)s->models->get(s->models, "test");
	model_matrix = matrix4f_identity(1.0f);
	degree = rotation_cicle * DEGREE_TO_RADIAN;
	model_matrix = matrix_rotate(model_matrix,\
		degree, new_vector3f(0.0f, 1.0f, 0.0f));
	draw_model(current_model, model_matrix,\
		s->camera->view, s->camera->projection);
	destruct_matrix4f(model_matrix);
}

void			scene_control(t_scop *s)
{
	if (get_key(s->keyboard, 81))
		s->camera->transform.position.z -= 0.1f;
	if (get_key(s->keyboard, 82))
		s->camera->transform.position.z += 0.1f;
	if (get_key(s->keyboard, 80))
		s->camera->transform.position.x -= 0.1f;
	if (get_key(s->keyboard, 79))
		s->camera->transform.position.x += 0.1f;
	if (get_key(s->keyboard, 44))
		s->camera->transform.position.y += 0.1f;
}

void			render_loop(t_scop *s)
{
	SDL_Event	event;
	float		rotation;

	rotation = 0;
	while (1)
	{
		SDL_GL_SwapWindow(s->window);
		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
		glClearColor(0.0f, 0.0f, 1.0f, 0.0f);
		draw_scene(s, rotation);
		scene_control(s);
		if (get_key(s->keyboard, 41))
			return ;
		while (SDL_PollEvent(&event))
		{
			if (event.type == SDL_QUIT)
			{
				return ;
			}
		}
		rotation += 1.f;
	}
}
