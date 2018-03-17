/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector3f.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jguyet <jguyet@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/07 16:27:44 by jguyet            #+#    #+#             */
/*   Updated: 2017/10/07 16:37:16 by jguyet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftx.h"

#include <stdlib.h>
#include <math.h>

t_vector3f		*v3f_normalize(t_vector3f *v)
{
	float mag;

	mag = v3f_magnitude(v);
	v->x /= mag;
	v->y /= mag;
	v->z /= mag;
	return (v);
}

t_vector3f		*v3f_mul(t_vector3f *v1, t_vector3f *v2)
{
	t_vector3f *dst;

	dst = new_vector3f(0, 0, 0);
	dst->x = v1->x * v2->x;
	dst->y = v1->y * v2->y;
	dst->z = v1->z * v2->z;
	return (dst);
}

t_vector3f		*v3f_cross(t_vector3f *v1, t_vector3f *v2)
{
	float nx;
	float ny;
	float nz;

	nx = v1->y * v2->z - v1->z * v2->y;
	ny = v1->z * v2->x - v1->x * v2->z;
	nz = v1->x * v2->y - v1->y * v2->x;
	return (new_vector3f(nx, ny, nz));
}

float			v3f_dot(t_vector3f *r1, t_vector3f *r2)
{
	return (r1->x * r2->x + r1->y * r2->y + r1->z * r2->z);
}
