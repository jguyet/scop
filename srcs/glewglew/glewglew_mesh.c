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

	if (!(mesh = (struct s_mesh*)malloc(sizeof(struct s_mech*))))
		return (NULL);
	mesh->name = ft_strdup(name);
	if (!(mesh->vertexs = (float **)malloc(sizeof(float*))))
		return (NULL);
	mesh->vertexs_length = 0;
	if (!(mesh->normals = (float **)malloc(sizeof(float*))))
		return (NULL);
	mesh->normals_length = 0;
	if (!(mesh->texturecoords = (float **)malloc(sizeof(float*))))
		return (NULL);
	mesh->texturecoords_length = 0;
	if (!(mesh->faces = (unsigned int **)malloc(sizeof(unsigned int*))))
		return (NULL);
	mesh->faces_length = 0;
	return (mesh);
}

void		mesh_add_vertex(t_mesh *mesh, float x, float y, float z)
{
	int		i;
	float	*vertex;
	float	**vertex_array;

	if (!(vertex = (float *)malloc(sizeof(float*) * 3)))
		return ;
	vertex[0] = x;
	vertex[1] = y;
	vertex[2] = z;
	if (!(vertex_array = (float **)malloc(sizeof(float*) * (mesh->vertexs_length + 1))))
		return ;
	i = 0;
	while (i < mesh->vertexs_length)
	{
		vertex_array[i] = mesh->vertexs[i];
		i++;
	}
	vertex_array[i] = vertex;
	free(mesh->vertexs);
	mesh->vertexs = vertex_array;
	mesh->vertexs_length++;
}

void		mesh_add_normal(t_mesh *mesh, float x, float y, float z)
{
	int		i;
	float	*normal;
	float	**normal_array;

	if (!(normal = (float *)malloc(sizeof(float*) * 3)))
		return ;
	normal[0] = x;
	normal[1] = y;
	normal[2] = z;
	if (!(normal_array = (float **)malloc(sizeof(float*) * (mesh->normals_length + 1))))
		return ;
	i = 0;
	while (i < mesh->normals_length)
	{
		normal_array[i] = mesh->normals[i];
		i++;
	}
	normal_array[i] = normal;
	free(mesh->normals);
	mesh->normals = normal_array;
	mesh->normals_length++;
}

void		mesh_add_texturecoord(t_mesh *mesh, float x, float y)
{
	int		i;
	float	*uv;
	float	**uv_array;

	if (!(uv = (float *)malloc(sizeof(float*) * 2)))
		return ;
	uv[0] = x;
	uv[1] = y;
	if (!(uv_array = (float **)malloc(sizeof(float*) * (mesh->texturecoords_length + 1))))
		return ;
	i = 0;
	while (i < mesh->texturecoords_length)
	{
		uv_array[i] = mesh->texturecoords[i];
		i++;
	}
	uv_array[i] = uv;
	free(mesh->texturecoords);
	mesh->texturecoords = uv_array;
	mesh->texturecoords_length++;
}

void		destruct_mesh(t_mesh *mesh)
{
	ft_strdel(&mesh->name);
	free_array_type((void**)mesh->vertexs, mesh->vertexs_length, "float**");
	free_array_type((void**)mesh->normals, mesh->normals_length, "float**");
	free_array_type((void**)mesh->texturecoords, mesh->texturecoords_length, "float**");
	free_array_type((void**)mesh->faces, mesh->faces_length, "unsigned int*");
	free(mesh);
}
