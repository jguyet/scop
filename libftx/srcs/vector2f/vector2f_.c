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

float			v2f_magnitude(t_vector2f *v)
{
	return ((float)sqrt(v2f_sqrt(v)));
}

t_vector2f		*v2f_normalize(t_vector2f *v)
{
	float mag;

	mag = v2f_magnitude(v);
	v->x /= mag;
	v->y /= mag;
	return (v);
}
