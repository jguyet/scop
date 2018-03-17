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
		ft_printf("Add Mesh %s\n", split[1]);
		g->current_mesh = glewglew_add_mesh(g, split[1]);
	}
	free_array(split);
}

void	mesh_parser_use_material(t_glewglew *g, char *line)
{
	char		**split;
	t_material	*material;

	if (g->current_mesh == NULL)
	{
		mesh_parser_add_mesh(g, "o default");
	}
	split = ft_split_string(line, " ");
	if (array_length(split) == 2)
	{
		if ((material = \
			g->materials_map->get(g->materials_map, split[1])) != NULL)
		{
			if (g->current_mesh->faces_i->size > 0)
			{
				ft_printf("Add Mesh %s\n", split[1]);
				g->current_mesh = glewglew_add_mesh(g, split[1]);
			}
			if (ft_strcmp(g->current_mesh->material->name, "None") == 0)
				destruct_material(g->current_mesh->material);
			g->current_mesh->material = material;
		}
	}
	free_array(split);
}

void	mesh_parser_add_vertex(t_glewglew *g, char *line)
{
	char		**split;

	split = ft_split_string(line, " ");
	if (array_length(split) == 4)
	{
		glewglew_add_vertex(g,\
			atof(split[1]), atof(split[2]), atof(split[3]));
	}
	free_array(split);
}

void	mesh_parser_add_texture_position(t_glewglew *g, char *line)
{
	char		**split;

	split = ft_split_string(line, " ");
	if (array_length(split) >= 3)
	{
		glewglew_add_texturecoord(g,\
			atof(split[1]), atof(split[2]));
	}
	free_array(split);
}

void	mesh_parser_add_material(t_glewglew *g, char *line)
{
	char **split;

	split = ft_split_string(line, " ");
	if (array_length(split) == 2)
	{
		g->current_material = NULL;
		glewglew_build_material(g, split[1]);
		g->current_material = NULL;
	}
	free_array(split);
}
