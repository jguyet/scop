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

#include "glewglew.h"

t_mesh		*new_mesh(char *name)
{
	t_mesh	*mesh;

	if (!(mesh = (struct s_mesh*)malloc(sizeof(struct s_mesh))))
		return (NULL);
	mesh->name = ft_strdup(name);
	if (!(mesh->vertexs = (float *)malloc(sizeof(float))))
		return (NULL);
	mesh->vertexs_length = 0;
	if (!(mesh->normals = (float *)malloc(sizeof(float))))
		return (NULL);
	mesh->normals_length = 0;
	if (!(mesh->texturecoords = (float *)malloc(sizeof(float))))
		return (NULL);
	mesh->texturecoords_length = 0;
	if (!(mesh->faces = (unsigned int *)malloc(sizeof(unsigned int))))
		return (NULL);
	mesh->faces_length = 0;
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
	free(mesh->texturecoords);
	mesh->texturecoords = uv_array;
	mesh->texturecoords_length++;
}

void		mesh_add_face(t_mesh *mesh, unsigned int v1, unsigned int v2,\
	unsigned int v3)
{
	int				i;
	unsigned int	*face_array;

	if (!(face_array = (unsigned int *)malloc(sizeof(unsigned int) *\
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
	free(mesh->faces);
	mesh->faces = face_array;
	mesh->faces_length++;
}

void		destruct_mesh(t_mesh *mesh)
{
	ft_strdel(&mesh->name);
	free(mesh->vertexs);
	free(mesh->normals);
	free(mesh->texturecoords);
	free(mesh->faces);
	free(mesh);
}
