/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   glewglew.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jguyet <jguyet@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/10 12:16:29 by jguyet            #+#    #+#             */
/*   Updated: 2018/03/10 12:16:30 by jguyet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#define GLEWGLEW_PROGRAMME

#include "glewglew.h"

void		glewglew_add_vertex(t_glewglew *g, float x, float y, float z)
{
	t_vector3f	*vec;

	vec = new_vector3f(x, y, z);
	g->vertexs->add(g->vertexs, g->vertexs->size, vec);
}

void		glewglew_add_texturecoord(t_glewglew *g, float x, float y)
{
	t_vector3f	*vec;

	vec = new_vector3f(x, y, 0.0f);
	g->texturecoords->add(g->texturecoords, g->texturecoords->size, vec);
}

int			glewglew_get_build_indice(t_glewglew *g, t_mesh *mesh,\
	t_face *face, int id)
{
	t_vector3f	*vec;

	if (id < 0)
		id = g->vertexs->size + id;
	if (g->texturecoords->size > 0)
	{
		vec = g->texturecoords->get(g->texturecoords,\
			face->texturecoords->get(face->texturecoords, id) - 1);
		if (vec != NULL)
			mesh_add_texturecoord(mesh, vec->x, vec->y);
		else
			mesh_add_texturecoord(mesh, 0, 0);
		mesh->material->block.has_texture_position = true;
	}
	mesh_add_color(mesh, face->color.x, face->color.y, face->color.z);
	vec = g->vertexs->get(g->vertexs,\
		face->vertexs->get(face->vertexs, id) - 1);
	if (vec != NULL)
	{
		mesh_add_vertex(mesh, vec->x, vec->y, vec->z);
		mesh_calcul_position(g, vec);
	}
	return (mesh->vertexs_length - 1);
}

void		glewglew_build_one_face(t_glewglew *g, t_mesh *mesh, t_face *face)
{
	int	veco[3];

	if (face->vertexs->size < 3)
		return ;
	veco[0] = glewglew_get_build_indice(g, mesh, face, 0);
	veco[1] = glewglew_get_build_indice(g, mesh, face, 1);
	veco[2] = glewglew_get_build_indice(g, mesh, face, 2);
	mesh_add_face(mesh, veco[0], veco[1], veco[2]);
	if (face->vertexs->size > 3)
	{
		veco[0] = glewglew_get_build_indice(g, mesh, face, 0);
		veco[1] = glewglew_get_build_indice(g, mesh, face, 2);
		veco[2] = glewglew_get_build_indice(g, mesh, face, 3);
		mesh_add_face(mesh, veco[0], veco[1], veco[2]);
	}
}

void		glewglew_build_faces(t_glewglew *g)
{
	t_mesh		*mesh;
	t_face		*face;
	int			i;
	int			o;

	i = 0;
	while (i < g->meshs_size)
	{
		mesh = g->meshs[i];
		o = 0;
		while (o < mesh->faces_i->size)
		{
			face = mesh->faces_i->get(mesh->faces_i, o);
			glewglew_build_one_face(g, mesh, face);
			o++;
		}
		i++;
	}
	i = 0;
	while (i < g->meshs_size)
	{
		mesh = g->meshs[i];
		glewglew_recenter(g, mesh);
		i++;
	}
}
