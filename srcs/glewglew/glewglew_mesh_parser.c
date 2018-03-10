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

	split = ft_strsplit(line, ' ');

	if (array_length(split) == 2)
	{
		glewglew_add_mesh(g, split[1]);
		g->current_mesh = g->meshs_map->get(g->meshs_map, split[1]);
		ft_printf("NEW MESH %s\n", split[1]);
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
		mesh_add_vertex(g->current_mesh, atof(split[1]), atof(split[2]), atof(split[3]));
		ft_printf("v vertex\n");
	}
	free_array(split);
}

void	mesh_parser_add_texture_position(t_glewglew *g, char *line)
{
	(void)g;
	(void)line;
	ft_printf("vt position\n");
}

void	mesh_parser_add_normal(t_glewglew *g, char *line)
{
	(void)g;
	(void)line;
	ft_printf("vn normal\n");
}

void	mesh_parser_add_face(t_glewglew *g, char *line)
{
	char	**split;

	if (g->current_mesh == NULL)
		return ;
	split = ft_strsplit(line, ' ');
	if (array_length(split) == 4)//TRIANGLES
	{
		mesh_add_face(g->current_mesh, atoi(split[1]), atoi(split[2]), atoi(split[3]));
		ft_printf("f face TRIANGLES\n");
	}
	else if (array_length(split) == 5)//QUADS
	{
		mesh_add_face(g->current_mesh, atoi(split[1]), atoi(split[2]), atoi(split[3]));
		mesh_add_face(g->current_mesh, atoi(split[3]), atoi(split[2]), atoi(split[4]));
		ft_printf("f face QUADS\n");
	}
	free_array(split);
}
