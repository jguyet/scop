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
#include <stdlib.h>

static void	add_s_to_mat(t_matrix4f *matrix, t_vector3f *s)
{
	matrix->matrix[0][0] = s->x;
	matrix->matrix[1][0] = s->y;
	matrix->matrix[2][0] = s->z;
}

t_matrix4f	*matrix4f_look_at(t_vector3f *eye,\
	t_vector3f *center, t_vector3f *up)
{
	t_matrix4f	*matrix;
	t_vector3f	*f;
	t_vector3f	*s;
	t_vector3f	*u;

	f = v3f_normalize(new_vector3f(center->x - eye->x, center->y - eye->y,\
		center->z - eye->z));
	s = v3f_normalize(v3f_cross(f, up));
	u = v3f_cross(s, f);
	matrix = matrix4f_identity(1.0f);
	add_s_to_mat(matrix, s);
	matrix->matrix[0][1] = u->x;
	matrix->matrix[1][1] = u->y;
	matrix->matrix[2][1] = u->z;
	matrix->matrix[0][2] = -f->x;
	matrix->matrix[1][2] = -f->y;
	matrix->matrix[2][2] = -f->z;
	matrix->matrix[3][0] = -v3f_dot(s, eye);
	matrix->matrix[3][1] = -v3f_dot(u, eye);
	matrix->matrix[3][2] = v3f_dot(f, eye);
	free(f);
	free(s);
	free(u);
	return (matrix);
}
