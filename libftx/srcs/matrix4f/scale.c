/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   scale.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jguyet <jguyet@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/15 21:05:23 by jguyet            #+#    #+#             */
/*   Updated: 2018/03/15 21:05:25 by jguyet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftx.h"

static t_matrix4f   *init_scale(float x, float y, float z)
{
	t_matrix4f	*m;

	m = new_matrix4f();
	m->matrix[0][0] = x;
	m->matrix[0][1] = 0;
	m->matrix[0][2] = 0;
	m->matrix[0][3] = 0;
	m->matrix[1][0] = 0;
	m->matrix[1][1] = y;
	m->matrix[1][2] = 0;
	m->matrix[1][3] = 0;
	m->matrix[2][0] = 0;
	m->matrix[2][1] = 0;
	m->matrix[2][2] = z;
	m->matrix[2][3] = 0;
	m->matrix[3][0] = 0;
	m->matrix[3][1] = 0;
	m->matrix[3][2] = 0;
	m->matrix[3][3] = 1;
	return (m);
}

t_matrix4f		*get_matrix_scale(t_vector3f *scale)
{
	t_matrix4f *scaling;

	scaling = init_scale(scale->x, scale->y, scale->x);
	return (scaling);
}

t_matrix4f		*matrix_scale(t_matrix4f *matrix, t_vector3f *scale)
{
	t_matrix4f *scaling;
	t_matrix4f *dst;

	scaling = init_scale(scale->x, scale->y, scale->x);
	dst = matrix4f_mul(matrix, scaling);
	destruct_matrix4f(scaling);
	destruct_matrix4f(matrix);
	return (dst);
}
