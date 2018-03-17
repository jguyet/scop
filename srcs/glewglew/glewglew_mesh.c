/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   glewglew_mesh.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jguyet <jguyet@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/10 18:41:08 by jguyet            #+#    #+#             */
/*   Updated: 2018/03/10 19:09:20 by jguyet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#define GLEWGLEW_PROGRAMME

#include "glewglew.h"

t_mesh		*new_mesh(char *name)
{
	t_mesh	*mesh;

	if (!(mesh = (struct s_mesh*)malloc(sizeof(struct s_mesh))))
		return (NULL);
	mesh->name = ft_strdup(name);
	mesh->faces_i = newintegerhashmap(10);
	mesh->vertexs = NULL;
	mesh->colors = NULL;
	mesh->texturecoords = NULL;
	mesh->faces = NULL;
	mesh->vertexs_length = 0;
	mesh->texturecoords_length = 0;
	mesh->faces_length = 0;
	mesh->colors_length = 0;
	mesh->material = new_material("None");
	mesh->current_face = NULL;
	initialize_vector3f(&mesh->max);
	initialize_vector3f(&mesh->min);
	return (mesh);
}

void		mesh_add_vertex_indice(t_mesh *mesh, int id)
{
	mesh->current_face->vertexs->add(mesh->current_face->vertexs,\
		mesh->current_face->vertexs->size, id);
}

void		mesh_add_texture_position_indice(t_mesh *mesh, int id)
{
	mesh->current_face->texturecoords->add(mesh->current_face->texturecoords,\
		mesh->current_face->texturecoords->size, id);
}

void		destruct_face(t_face *face)
{
	destruct_hashmap(face->vertexs, NULL, NULL);
	destruct_hashmap(face->texturecoords, NULL, NULL);
	free(face);
}

void		destruct_mesh(t_mesh *mesh)
{
	free(mesh->name);
	if (mesh->vertexs != NULL)
		free(mesh->vertexs);
	if (mesh->colors != NULL)
		free(mesh->colors);
	if (mesh->texturecoords != NULL)
		free(mesh->texturecoords);
	destruct_hashmap(mesh->faces_i, NULL, destruct_face);
	free(mesh->faces);
	free(mesh);
}
