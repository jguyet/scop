/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector2f.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jguyet <jguyet@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/07 16:44:50 by jguyet            #+#    #+#             */
/*   Updated: 2017/10/07 16:44:52 by jguyet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftx.h"

#include <stdlib.h>
#include <math.h>

t_vector2f		*new_vector2f(float x, float y)
{
	t_vector2f	*v;

	if (!(v = (t_vector2f*)malloc(sizeof(struct s_vector2f))))
		return (NULL);
	v->x = x;
	v->y = y;
	return (v);
}

t_vector2f		*initialize_vector2f(t_vector2f *v)
{
	v->x = 0.f;
	v->y = 0.f;
	return (v);
}

void			destruct_vector2f(t_vector2f *v)
{
	free(v);
}

float			v2f_sqrt(t_vector2f *v)
{
	return (v->x * v->x + v->y * v->y);
}
