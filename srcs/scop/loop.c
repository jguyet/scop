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

void			render_loop(t_scop *s)
{
	SDL_Event	event;

	float rotation = 0;

	while (1)
	{
		SDL_GL_SwapWindow(s->window);
		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

		build_look_at_projection(s->camera);

		t_model *current_model = (t_model*)s->models->get(s->models, "42");

		t_matrix4f	*model = matrix4f_identity();

		model = matrix_rotate(model, rotation * (MATHF_PI * 2) / 360, new_vector3f(0.0f, 1.0f, 0.0f));

		draw_model(current_model, model, s->camera->view, s->camera->projection);

		if (get_key(s->keyboard, 81))//down
		{
			s->camera->transform.position.z -= 0.01f;
		}
		if (get_key(s->keyboard, 82))//up
		{
			s->camera->transform.position.z += 0.01f;
		}
		if (get_key(s->keyboard, 80))//down
		{
			s->camera->transform.position.x -= 0.01f;
		}
		if (get_key(s->keyboard, 79))//up
		{
			s->camera->transform.position.x += 0.01f;
		}
		if (get_key(s->keyboard, 44))//up
		{
			s->camera->transform.position.y += 0.01f;
		}

		while(SDL_PollEvent(&event))
		{
			if(event.type == SDL_QUIT)
			{
				return ;
			}
		}
		rotation += 0.1f;
	}
}
