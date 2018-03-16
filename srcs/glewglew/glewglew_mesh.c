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
	mesh->normals = NULL;
	mesh->colors = NULL;
	mesh->texturecoords = NULL;
	mesh->faces = NULL;
	mesh->vertexs_length = 0;
	mesh->normals_length = 0;
	mesh->texturecoords_length = 0;
	mesh->faces_length = 0;
	mesh->colors_length = 0;
	mesh->material = new_material("None");
	mesh->current_face = NULL;
	initialize_vector3f(&mesh->max);
	initialize_vector3f(&mesh->min);
	return (mesh);
}

void		mesh_calcul_position(t_mesh *mesh, float x, float y, float z)
{
	if (x >= mesh->max.x)
		mesh->max.x = x;
	if (x <= mesh->min.x)
		mesh->min.x = x;
	if (y >= mesh->max.y)
		mesh->max.y = y;
	if (y <= mesh->min.y)
		mesh->min.y = y;
	if (z >= mesh->max.z)
		mesh->max.z = z;
	if (z <= mesh->min.z)
		mesh->min.z = z;
}

void		mesh_add_vertex(t_mesh *mesh, float x, float y, float z)
{
	int		i;
	float	*vertex_array;

	if (!(vertex_array =\
		(float *)malloc(sizeof(float) * ((mesh->vertexs_length + 1) * 3))))
		return ;
	i = 0;
	while (i < (mesh->vertexs_length * 3))
	{
		vertex_array[i] = mesh->vertexs[i];
		i++;
	}
	vertex_array[i + 0] = x;
	vertex_array[i + 1] = y;
	vertex_array[i + 2] = z;
	mesh_calcul_position(mesh, x, y, z);
	if (mesh->vertexs != NULL)
		free(mesh->vertexs);
	mesh->vertexs = vertex_array;
	mesh->vertexs_length++;
}

void		mesh_add_normal(t_mesh *mesh, float x, float y, float z)
{
	int		i;
	float	*normal_array;

	if (!(normal_array =\
		(float *)malloc(sizeof(float) * ((mesh->normals_length + 1) * 3))))
		return ;
	i = 0;
	while (i < (mesh->normals_length * 3))
	{
		normal_array[i] = mesh->normals[i];
		i++;
	}
	normal_array[i + 0] = x;
	normal_array[i + 1] = y;
	normal_array[i + 2] = z;
	if (mesh->normals != NULL)
		free(mesh->normals);
	mesh->normals = normal_array;
	mesh->normals_length++;
}

void		mesh_add_texturecoord(t_mesh *mesh, float x, float y)
{
	int		i;
	float	*uv_array;

	if (!(uv_array = (float *)malloc(sizeof(float) *\
		((mesh->texturecoords_length + 1) * 2))))
		return ;
	i = 0;
	while (i < (mesh->texturecoords_length * 2))
	{
		uv_array[i] = mesh->texturecoords[i];
		i++;
	}
	uv_array[i + 0] = x;
	uv_array[i + 1] = y;
	if (mesh->texturecoords != NULL)
		free(mesh->texturecoords);
	mesh->texturecoords = uv_array;
	mesh->texturecoords_length++;
}

void		mesh_add_color(t_mesh *mesh, float x, float y, float z)
{
	int		i;
	float	*color_array;

	if (!(color_array = (float *)malloc(sizeof(float) *\
		((mesh->colors_length + 1) * 3))))
		return ;
	i = 0;
	while (i < (mesh->colors_length * 3))
	{
		color_array[i] = mesh->colors[i];
		i++;
	}
	color_array[i + 0] = x;
	color_array[i + 1] = y;
	color_array[i + 2] = z;
	if (mesh->colors != NULL)
		free(mesh->colors);
	mesh->colors = color_array;
	mesh->colors_length++;
}

void		mesh_add_face(t_mesh *mesh, unsigned int v1,\
	unsigned int v2, unsigned int v3)
{
	int				i;
	unsigned short	*face_array;

	if (!(face_array = (unsigned short *)malloc(sizeof(unsigned short) *\
		((mesh->faces_length + 1) * 3))))
		return ;
	i = 0;
	while (i < (mesh->faces_length * 3))
	{
		face_array[i] = mesh->faces[i];
		i++;
	}
	face_array[i + 0] = v1;
	face_array[i + 1] = v2;
	face_array[i + 2] = v3;
	if (mesh->faces != NULL)
		free(mesh->faces);
	mesh->faces = face_array;
	mesh->faces_length++;
}

void		mesh_add_vertex_indice(t_mesh *mesh, int id)
{
	mesh->current_face->vertexs->add(mesh->current_face->vertexs,\
		mesh->current_face->vertexs->size, id);
}

void		mesh_add_normal_indice(t_mesh *mesh, int id)
{
	mesh->current_face->normals->add(mesh->current_face->normals,\
		mesh->current_face->normals->size, id);
}

void		mesh_add_texture_position_indice(t_mesh *mesh, int id)
{
	mesh->current_face->texturecoords->add(mesh->current_face->texturecoords,\
		mesh->current_face->texturecoords->size, id);
}

t_face		*mesh_add_face_indice(t_mesh *mesh)
{
	t_face	*face;
	float	r;

	if (!(face = (struct s_face*)malloc(sizeof(struct s_face))))
		return (NULL);
	face->vertexs = newintegerhashmap(1);
	face->normals = newintegerhashmap(1);
	face->texturecoords = newintegerhashmap(1);
	face->type = POLIGON_FACE;
	r = 0.0f;
	while (r < 0.1f || r > 0.3f)
		r = (float)(rand() % 255) / 255.0f;
	face->color.x = r;
	face->color.y = r;
	face->color.z = r;
	mesh->faces_i->add(mesh->faces_i, mesh->faces_i->size, face);
	return (face);
}

void		destruct_face(t_face *face)
{
	destruct_hashmap(face->vertexs, NULL, NULL);
	destruct_hashmap(face->normals, NULL, NULL);
	destruct_hashmap(face->texturecoords, NULL, NULL);
	free(face);
}

void		destruct_mesh(t_mesh *mesh)
{
	free(mesh->name);
	if (mesh->vertexs != NULL)
		free(mesh->vertexs);
	if (mesh->normals != NULL)
		free(mesh->normals);
	if (mesh->colors != NULL)
		free(mesh->colors);
	if (mesh->texturecoords != NULL)
		free(mesh->texturecoords);
	destruct_hashmap(mesh->faces_i, NULL, destruct_face);
	free(mesh->faces);
	//free(mesh->material);
	free(mesh);
}
