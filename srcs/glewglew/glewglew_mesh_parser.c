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
		g->current_mesh = glewglew_add_mesh(g, split[1]);
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
			atoi(split[1]) - 1, atoi(split[2]) - 1, atoi(split[3]) - 1);
	}
	else if (array_length(split) == 5)
	{
		mesh_add_face(g->current_mesh,\
			atoi(split[1]) - 1, atoi(split[2]) - 1, atoi(split[3]) - 1);
		mesh_add_face(g->current_mesh,\
			atoi(split[1]) - 1, atoi(split[3]) - 1, atoi(split[4]) - 1);
	}
	free_array(split);
}
