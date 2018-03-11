/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   camera.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jguyet <jguyet@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/08 11:02:35 by jguyet            #+#    #+#             */
/*   Updated: 2018/03/08 11:02:36 by jguyet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftx.h"

#include <stdlib.h>

t_camera		*new_camera(void)
{
	t_camera *c;

	if ((c = (struct s_camera*)malloc(sizeof(struct s_camera))) == NULL)
		return (NULL);
	initialize_transform(&c->transform);
	c->model = NULL;
	c->view = NULL;
	c->projection = NULL;
	c->fov = 0;
	c->aspect_ratio = 0;
	c->near = 0;
	c->far = 0;
	c->matrix = NULL;
	return (c);
}

void			destruct_camera(t_camera *c)
{
	if (c->view != NULL)
		destruct_matrix4f(c->view);
	if (c->projection != NULL)
		destruct_matrix4f(c->projection);
	if (c->matrix != NULL)
		destruct_matrix4f(c->matrix);
	free(c);
}
