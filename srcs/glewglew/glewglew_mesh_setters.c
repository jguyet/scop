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
	if (mesh->vertexs != NULL)
		free(mesh->vertexs);
	mesh->vertexs = vertex_array;
	mesh->vertexs_length++;
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

t_face		*mesh_add_face_indice(t_mesh *mesh)
{
	t_face	*face;
	float	r;

	if (!(face = (struct s_face*)malloc(sizeof(struct s_face))))
		return (NULL);
	face->vertexs = newintegerhashmap(1);
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
