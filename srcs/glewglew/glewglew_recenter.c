/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   glewglew_recenter.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jguyet <jguyet@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/12 04:52:00 by jguyet            #+#    #+#             */
/*   Updated: 2018/03/13 15:02:22 by jguyet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#define GLEWGLEW_PROGRAMME

#include "glewglew.h"

void	mesh_calcul_position(t_glewglew *g, t_vector3f *vec)
{
	if (vec->x >= g->max.x)
		g->max.x = vec->x;
	if (vec->x <= g->min.x)
		g->min.x = vec->x;
	if (vec->y >= g->max.y)
		g->max.y = vec->y;
	if (vec->y <= g->min.y)
		g->min.y = vec->y;
	if (vec->z >= g->max.z)
		g->max.z = vec->z;
	if (vec->z <= g->min.z)
		g->min.z = vec->z;
}

void	glewglew_recenter(t_glewglew *g, t_mesh *mesh)
{
	int	i;

	i = 0;
	(void)g;
	while (i < (mesh->vertexs_length * 3))
	{
		mesh->vertexs[i + 0] = mesh->vertexs[i + 0] -\
		(float)((g->max.x + g->min.x) / 2.f);
		mesh->vertexs[i + 1] = mesh->vertexs[i + 1] -\
		(float)((g->max.y + g->min.y) / 2.f);
		mesh->vertexs[i + 2] = mesh->vertexs[i + 2] -\
		(float)((g->max.z + g->min.z) / 2.f);
		i += 3;
	}
}
