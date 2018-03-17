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

void			loop_control_two(t_scop *s, t_model *model)
{
	if (get_keydown(s->keyboard, 40))
	{
		s->texture = !s->texture;
		s->keyboard->downkeys[40] = false;
	}
	if (s->texture == false && model->iterator < 1.0f)
		model->iterator += 0.015f;
	if (s->texture == true && model->iterator > 0.0f)
		model->iterator -= 0.008f;
	if (model->iterator > 1.0f)
		model->iterator = 1.00f;
	if (model->iterator < 0.0f)
		model->iterator = 0.00f;
	if (get_keydown(s->keyboard, 98))
	{
		s->rotate = !s->rotate;
		s->keyboard->downkeys[98] = false;
	}
	if (s->rotate == true)
		model->transform.rotation.y += 1.f;
}

void			move_control(t_scop *s, t_model *model)
{
	(void)s;
	if (get_key(s->keyboard, 94))
		model->transform.position.z -= 0.1f;
	if (get_key(s->keyboard, 92))
		model->transform.position.z += 0.1f;
	if (get_key(s->keyboard, 96))
		model->transform.position.x -= 0.1f;
	if (get_key(s->keyboard, 90))
		model->transform.position.x += 0.1f;
	if (get_key(s->keyboard, 225) && get_key(s->keyboard, 93))
		model->transform.position.y -= 0.1f;
	else if (get_key(s->keyboard, 93))
		model->transform.position.y += 0.1f;
	if (get_key(s->keyboard, 30))
		model->draw_mode = GL_TRIANGLES;
	if (get_key(s->keyboard, 31))
		model->draw_mode = GL_LINES;
	if (get_key(s->keyboard, 32))
		model->draw_mode = GL_POINTS;
}

void			rotate_control(t_scop *s, t_model *model)
{
	(void)s;
	if (get_key(s->keyboard, 225) && get_key(s->keyboard, 83))
		model->transform.rotation.x += 1.f;
	else if (get_key(s->keyboard, 83))
		model->transform.rotation.x -= 1.f;
	if (get_key(s->keyboard, 225) && get_key(s->keyboard, 103))
		model->transform.rotation.y += 1.f;
	else if (get_key(s->keyboard, 103))
		model->transform.rotation.y -= 1.f;
	if (get_key(s->keyboard, 225) && get_key(s->keyboard, 84))
		model->transform.rotation.z += 1.f;
	else if (get_key(s->keyboard, 84))
		model->transform.rotation.z -= 1.f;
}

void			scale_control(t_scop *s, t_model *model)
{
	(void)s;
	if (get_key(s->keyboard, 225) && get_key(s->keyboard, 85))
		model->transform.scale.x += 0.01f;
	else if (get_key(s->keyboard, 85))
		model->transform.scale.x -= 0.01f;
	if (get_key(s->keyboard, 225) && get_key(s->keyboard, 86))
		model->transform.scale.y += 0.01f;
	else if (get_key(s->keyboard, 86))
		model->transform.scale.y -= 0.01f;
	if (get_key(s->keyboard, 225) && get_key(s->keyboard, 87))
		model->transform.scale.z += 0.01f;
	else if (get_key(s->keyboard, 87))
		model->transform.scale.z -= 0.01f;
	if (get_key(s->keyboard, 225) && get_key(s->keyboard, 88))
	{
		model->transform.scale.x += 0.01f;
		model->transform.scale.y += 0.01f;
		model->transform.scale.z += 0.01f;
	}
	else if (get_key(s->keyboard, 88))
	{
		model->transform.scale.x -= 0.01f;
		model->transform.scale.y -= 0.01f;
		model->transform.scale.z -= 0.01f;
	}
}

void			loop_control(t_scop *s, t_model *model)
{
	if (get_key(s->keyboard, 81))
		s->camera->transform.position.x += 0.25f;
	if (get_key(s->keyboard, 82))
		s->camera->transform.position.x -= 0.25f;
	if (get_key(s->keyboard, 80))
		s->camera->transform.position.z += 0.25f;
	if (get_key(s->keyboard, 79))
		s->camera->transform.position.z -= 0.25f;
	if (get_key(s->keyboard, 225) && get_key(s->keyboard, 44))
		s->camera->transform.position.y -= 0.25f;
	else if (get_key(s->keyboard, 44))
		s->camera->transform.position.y += 0.25f;
	move_control(s, model);
	rotate_control(s, model);
	scale_control(s, model);
	loop_control_two(s, model);
	if (model->transform.scale.x < 0.01f)
		model->transform.scale.x = 0.01f;
	if (model->transform.scale.y < 0.01f)
		model->transform.scale.y = 0.01f;
	if (model->transform.scale.z < 0.01f)
		model->transform.scale.z = 0.01f;
}
