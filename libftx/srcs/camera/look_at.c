/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   look_at.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jguyet <jguyet@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/08 11:17:39 by jguyet            #+#    #+#             */
/*   Updated: 2018/03/08 11:26:37 by jguyet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftx.h"

#include <math.h>

static void		build_look_at_side(t_matrix4f *matrix, t_vector3f *side)
{
	matrix->matrix[0][0] = side->x;
	matrix->matrix[1][0] = side->y;
	matrix->matrix[2][0] = side->z;
	matrix->matrix[3][0] = 0;
}

static void		build_look_at_up(t_matrix4f *matrix, t_vector3f *up)
{
	matrix->matrix[0][1] = up->x;
	matrix->matrix[1][1] = up->y;
	matrix->matrix[2][1] = up->z;
	matrix->matrix[3][1] = 0;
}

static void		build_look_at_forward(t_matrix4f *matrix, t_vector3f *forward)
{
	matrix->matrix[0][2] = -forward->x;
	matrix->matrix[1][2] = -forward->y;
	matrix->matrix[2][2] = -forward->z;
	matrix->matrix[3][2] = 0;
}

t_matrix4f		*transform_look_at(t_vector3f *eye3d, t_vector3f *center3d,\
	t_vector3f *up3d)
{
	t_vector3f *forward;
	t_vector3f *side;
	t_vector3f *up;
	t_matrix4f *matrix;

	matrix = matrix4f_identity();
	forward = new_vector3f(center3d->x - eye3d->x, center3d->y - eye3d->y,\
		center3d->z - eye3d->z);
	forward = v3f_normalize(forward);
	side = new_vector3f(0, 0, 0);
	side->x = (forward->y * up3d->z) - (forward->z * up3d->y);
	side->y = (forward->z * up3d->x) - (forward->x * up3d->z);
	side->z = (forward->x * up3d->y) - (forward->y * up3d->x);
	side = v3f_normalize(side);
	up = new_vector3f(0, 0, 0);
	up->x = (side->y * forward->z) - (side->z * forward->y);
	up->y = (side->z * forward->x) - (side->x * forward->z);
	up->z = (side->x * forward->y) - (side->y * forward->x);
	build_look_at_side(matrix, side);
	build_look_at_up(matrix, up);
	build_look_at_forward(matrix, forward);
	matrix = transform_translation(matrix, new_vector3f(-eye3d->x,\
		-eye3d->y, -eye3d->z));
	return (matrix);
}
