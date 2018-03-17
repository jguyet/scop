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

t_vector3f		*new_vector3f(float x, float y, float z)
{
	t_vector3f	*v;

	if (!(v = (t_vector3f*)malloc(sizeof(struct s_vector3f))))
		return (NULL);
	v->x = x;
	v->y = y;
	v->z = z;
	return (v);
}

t_vector3f		*initialize_vector3f(t_vector3f *v)
{
	v->x = 0.f;
	v->y = 0.f;
	v->z = 0.f;
	return (v);
}

void			destruct_vector3f(t_vector3f *v)
{
	free(v);
}

float			v3f_sqrt(t_vector3f *v)
{
	return (v->x * v->x + v->y * v->y + v->z * v->z);
}

float			v3f_magnitude(t_vector3f *v)
{
	return ((float)sqrt(v3f_sqrt(v)));
}
