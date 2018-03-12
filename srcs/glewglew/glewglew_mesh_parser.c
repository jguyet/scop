/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   glewglew_obj.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jguyet <jguyet@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/10 12:57:27 by jguyet            #+#    #+#             */
/*   Updated: 2018/03/10 12:57:28 by jguyet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#define GLEWGLEW_PROGRAMME

#include "glewglew.h"

void	mesh_parser_add_mesh(t_glewglew *g, char *line)
{
	char	**split;

	split = ft_split_string(line, " ");
	if (array_length(split) == 2)
	{
		if (g->current_mesh != NULL)
		{
			g->faces_offset += g->current_mesh->vertexs_length;

			ft_printf("offset %d\n", g->faces_offset);
		}
		g->current_mesh = glewglew_add_mesh(g, split[1]);
	}
	free_array(split);
}

void	mesh_parser_use_material(t_glewglew *g, char *line)
{
	char		**split;
	t_material	*material;

	if (g->current_mesh == NULL)
		return ;
	split = ft_split_string(line, " ");
	if ((int)array_length(split) == 2)
	{
		material = g->materials_map->get(g->materials_map, split[1]);
		if (material == NULL)
		{
			material = g->materials_map->get(g->materials_map, "None");
		}
		ft_printf("Usemtl :%s\n", split[1]);
		g->current_mesh->material = material;
	}
	free_array(split);
}

void	mesh_parser_add_vertex(t_glewglew *g, char *line)
{
	char		**split;

	if (g->current_mesh == NULL)
		return ;
	split = ft_split_string(line, " ");
	if (array_length(split) == 4)
	{
		mesh_add_vertex(g->current_mesh,\
			atof(split[1]), atof(split[2]), atof(split[3]));
	}
	free_array(split);
}

void	mesh_parser_add_texture_position(t_glewglew *g, char *line)
{
	(void)g;
	(void)line;
	if (g->current_mesh == NULL)
		return ;
}

void	mesh_parser_add_normal(t_glewglew *g, char *line)
{
	(void)g;
	(void)line;
	if (g->current_mesh == NULL)
		return ;
}

void	mesh_parser_add_face(t_glewglew *g, char *line)
{
	char	**split;

	if (g->current_mesh == NULL)
		return ;
	split = ft_split_string(line, " ");
	if (array_length(split) == 4)
	{
		mesh_add_face(g->current_mesh,\
			atoi(split[1]) - (g->faces_offset + 1), atoi(split[2]) - (g->faces_offset + 1), atoi(split[3]) - (g->faces_offset + 1));
	}
	else if (array_length(split) == 5)
	{
		mesh_add_face(g->current_mesh,\
			atoi(split[1]) - (g->faces_offset + 1), atoi(split[2]) - (g->faces_offset + 1), atoi(split[3]) - (g->faces_offset + 1));
		mesh_add_face(g->current_mesh,\
			atoi(split[1]) - (g->faces_offset + 1), atoi(split[3]) - (g->faces_offset + 1), atoi(split[4]) - (g->faces_offset + 1));
	}
	free_array(split);
}

void	mesh_parser_add_material(t_glewglew *g, char *line)
{
	char **split;

	split = ft_split_string(line, " ");
	if ((int)array_length(split) == 2)
	{
		g->current_material = NULL;
		glewglew_build_material(g, split[1]);
		g->current_material = NULL;
	}
	free_array(split);
}
