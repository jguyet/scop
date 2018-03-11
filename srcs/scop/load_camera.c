/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   load_camera.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jguyet <jguyet@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/11 10:40:12 by jguyet            #+#    #+#             */
/*   Updated: 2018/03/11 10:40:14 by jguyet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "scop.h"

void		load_camera(t_scop *s)
{
	s->camera = new_camera();
	build_look_at_projection(s->camera, s->screen);
}

void		build_look_at_projection(t_camera *camera, t_screen *screen)
{
	t_vector3f	to;
	t_vector3f	*up;

	if (camera->projection != NULL)
		destruct_matrix4f(camera->projection);
	if (camera->view != NULL)
		destruct_matrix4f(camera->view);
	initialize_vector3f(&to);
	up = new_vector3f(0, 1, 0);
	camera->projection = matrix4f_perspective(45.0f, screen->width / screen->height, 0.1f, 500.f);
	camera->view = matrix4f_look_at(&camera->transform.position, &to, up);
	free(up);
}
