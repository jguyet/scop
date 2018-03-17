/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   matrix4f.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jguyet <jguyet@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/07 16:50:44 by jguyet            #+#    #+#             */
/*   Updated: 2018/03/08 11:36:12 by jguyet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftx.h"

#include <stdlib.h>
#include <math.h>

t_matrix4f		*new_matrix4f(void)
{
	t_matrix4f	*m;

	if (!(m = (t_matrix4f*)malloc(sizeof(struct s_matrix4f))))
		return (NULL);
	initialize_matrix4f(m);
	return (m);
}

t_matrix4f		*initialize_matrix4f(t_matrix4f *m)
{
	int			x;
	int			y;

	x = 0;
	while (x < 4)
	{
		y = 0;
		while (y < 4)
		{
			m->matrix[x][y] = 0;
			y++;
		}
		x++;
	}
	return (m);
}

t_matrix4f		*copy_matrix4f(t_matrix4f *origin)
{
	t_matrix4f	*dst;
	int			x;
	int			y;

	if (!(dst = new_matrix4f()))
		return (NULL);
	x = 0;
	while (x < 4)
	{
		y = 0;
		while (y < 4)
		{
			dst->matrix[x][y] = origin->matrix[x][y];
			y++;
		}
		x++;
	}
	return (dst);
}

void			destruct_matrix4f(t_matrix4f *m)
{
	free(m);
}

t_matrix4f		*matrix4f_identity(float t)
{
	t_matrix4f	*i;

	i = new_matrix4f();
	i->matrix[0][0] = t;
	i->matrix[1][1] = t;
	i->matrix[2][2] = t;
	i->matrix[3][3] = 1.0f;
	return (i);
}
