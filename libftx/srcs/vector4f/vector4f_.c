/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector4f.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jguyet <jguyet@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/07 16:45:08 by jguyet            #+#    #+#             */
/*   Updated: 2017/10/07 17:17:39 by jguyet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftx.h"

#include <stdlib.h>
#include <math.h>

float			v4f_sqrt(t_vector4f *v)
{
	return (v->x * v->x + v->y * v->y + v->z * v->z + v->w * v->w);
}

float			v4f_magnitude(t_vector4f *v)
{
	return ((float)sqrt(v4f_sqrt(v)));
}

t_vector4f		*v4f_normalize(t_vector4f *v)
{
	float	mag;

	mag = v4f_magnitude(v);
	v->x /= mag;
	v->y /= mag;
	v->z /= mag;
	v->w /= mag;
	return (v);
}
