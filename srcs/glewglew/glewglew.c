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

t_glewglew	*new_glewglew(void)
{
	t_glewglew	*g;

	if ((g = (struct s_glewglew*)malloc(sizeof(struct s_glewglew))) == NULL)
		return (NULL);
	g->build_file = &glewglew_build_file;
	g->materials_map = newstringhashmap(10);
	g->meshs_map = newstringhashmap(10);
	g->vertexs = newintegerhashmap(10);
	g->texturecoords = newintegerhashmap(10);
	g->normals = newintegerhashmap(10);
	g->current_mesh = NULL;
	g->current_material = NULL;
	g->initializer.absolute_path = NULL;
	g->meshs = NULL;
	g->meshs_size = 0;
	return (g);
}

t_mesh		*glewglew_add_mesh(t_glewglew *g, char *name)
{
	t_mesh	*mesh;
	int		i;
	t_mesh	**meshs;

	mesh = new_mesh(name);
	g->meshs_map->remove(g->meshs_map, name);
	g->meshs_map->add(g->meshs_map, name, mesh);
	if ((meshs = (struct s_mesh**)malloc(sizeof(struct s_mesh*) *\
	(g->meshs_size + 1))) == NULL)
		return (NULL);
	i = 0;
	while (i < g->meshs_size)
	{
		meshs[i] = g->meshs[i];
		i++;
	}
	if (g->meshs != NULL)
		free(g->meshs);
	meshs[i] = mesh;
	g->meshs = meshs;
	g->meshs_size++;
	return (mesh);
}

t_material	*glewglew_add_material(t_glewglew *g, char *name)
{
	t_material	*material;

	material = new_material(name);
	g->materials_map->add(g->materials_map, name, material);
	return (material);
}

void		glewglew_add_vertex(t_glewglew *g, float x, float y, float z)
{
	t_vector3f	*vec;

	vec = new_vector3f(x, y, z);
	g->vertexs->add(g->vertexs, g->vertexs->size, vec);
}

void		glewglew_add_normal(t_glewglew *g, float x, float y, float z)
{
	t_vector3f	*vec;

	vec = new_vector3f(x, y, z);
	g->normals->add(g->normals, g->normals->size, vec);
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

	if (g->texturecoords->size > 0)
	{
		vec = g->texturecoords->get(g->texturecoords,\
			face->texturecoords->get(face->texturecoords, id) - 1);
		mesh_add_texturecoord(mesh, vec->x, vec->y);
	}
	else
	{
		mesh_add_texturecoord(mesh,\
			id % 3 == 1 ? 1.0f : 0.0f, id % 3 == 2 ? 1.0f : 0.0f);
	}
	mesh_add_color(mesh, face->color.x, face->color.y, face->color.z);
	vec = g->vertexs->get(g->vertexs,\
		face->vertexs->get(face->vertexs, id) - 1);
	mesh_add_vertex(mesh, vec->x, vec->y, vec->z);
	return (mesh->vertexs_length - 1);
}

void		glewglew_build_one_face(t_glewglew *g, t_mesh *mesh, t_face *face)
{
	int	veco[3];

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
		glewglew_recenter(mesh);
		i++;
	}
}

void		destruct_glewglew(t_glewglew *g)
{
	if (g->meshs != NULL)
		free(g->meshs);
	destruct_hashmap(g->materials_map, free, destruct_material);
	destruct_hashmap(g->meshs_map, free, destruct_mesh);
	destruct_hashmap(g->vertexs, NULL, destruct_vector3f);
	destruct_hashmap(g->texturecoords, NULL, destruct_vector3f);
	destruct_hashmap(g->normals, NULL, destruct_vector3f);
	free(g->initializer.absolute_path);
	free(g);
}
