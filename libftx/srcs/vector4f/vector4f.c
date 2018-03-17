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

t_vector4f		*new_vector4f(float x, float y, float z, float w)
{
	t_vector4f	*v;

	if (!(v = (t_vector4f*)malloc(sizeof(struct s_vector4f))))
		return (NULL);
	v->x = x;
	v->y = y;
	v->z = z;
	v->w = w;
	return (v);
}

t_vector4f		*initialize_vector4f(t_vector4f *v)
{
	v->x = 0.f;
	v->y = 0.f;
	v->z = 0.f;
	v->w = 0.f;
	return (v);
}

void			destruct_vector4f(t_vector4f *v)
{
	free(v);
}
