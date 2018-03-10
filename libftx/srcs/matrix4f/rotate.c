/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jguyet <jguyet@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/10 14:46:45 by jguyet            #+#    #+#             */
/*   Updated: 2018/03/10 14:46:47 by jguyet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftx.h"

#include <math.h>

static void		rotate_x(t_matrix4f *m, float x)
{
	m->matrix[0][0] = 1;
	m->matrix[0][1] = 0;
	m->matrix[0][2] = 0;
	m->matrix[0][3] = 0;
	m->matrix[1][0] = 0;
	m->matrix[1][1] = (float)cos(x);
	m->matrix[1][2] = -(float)sin(x);
	m->matrix[1][3] = 0;
	m->matrix[2][0] = 0;
	m->matrix[2][1] = (float)sin(x);
	m->matrix[2][2] = (float)cos(x);
	m->matrix[2][3] = 0;
	m->matrix[3][0] = 0;
	m->matrix[3][1] = 0;
	m->matrix[3][2] = 0;
	m->matrix[3][3] = 1;
}

static void		rotate_y(t_matrix4f *m, float y)
{
	m->matrix[0][0] = (float)cos(y);
	m->matrix[0][1] = 0;
	m->matrix[0][2] = (float)sin(y);
	m->matrix[0][3] = 0;
	m->matrix[1][0] = 0;
	m->matrix[1][1] = 1;
	m->matrix[1][2] = 0;
	m->matrix[1][3] = 0;
	m->matrix[2][0] = -(float)sin(y);
	m->matrix[2][1] = 0;
	m->matrix[2][2] = (float)cos(y);
	m->matrix[2][3] = 0;
	m->matrix[3][0] = 0;
	m->matrix[3][1] = 0;
	m->matrix[3][2] = 0;
	m->matrix[3][3] = 1;
}

static void		rotate_z(t_matrix4f *m, float z)
{
	m->matrix[0][0] = (float)cos(z);
	m->matrix[0][1] = -(float)sin(z);
	m->matrix[0][2] = 0;
	m->matrix[0][3] = 0;
	m->matrix[1][0] = (float)sin(z);
	m->matrix[1][1] = (float)cos(z);
	m->matrix[1][2] = 0;
	m->matrix[1][3] = 0;
	m->matrix[2][0] = 0;
	m->matrix[2][1] = 0;
	m->matrix[2][2] = 1;
	m->matrix[2][3] = 0;
	m->matrix[3][0] = 0;
	m->matrix[3][1] = 0;
	m->matrix[3][2] = 0;
	m->matrix[3][3] = 1;
}

t_matrix4f		*matrix_rotate(t_matrix4f *matrix, float angle,\
	t_vector3f *type)
{
	t_matrix4f	*m;
	t_matrix4f	*dst;

	m = new_matrix4f();
	if (type->x == 1 && type->y == 0 && type->z == 0)
		rotate_x(m, angle);
	if (type->x == 0 && type->y == 1 && type->z == 0)
		rotate_y(m, angle);
	if (type->x == 0 && type->y == 0 && type->z == 1)
		rotate_z(m, angle);
	dst = m;
	if (matrix != NULL)
	{
		dst = matrix4f_mul(matrix, m);
		destruct_matrix4f(m);
	}
	destruct_matrix4f(matrix);
	destruct_vector3f(type);
	return (dst);
}
