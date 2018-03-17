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

void	mesh_parser_get_face_indices(t_glewglew *g, char *string_face)
{
	char	**split;

	split = ft_split_string(string_face, "/");
	if (array_length(split) > 0)
		mesh_add_vertex_indice(g->current_mesh, atoi(split[0]));
	if (array_length(split) > 1)
		mesh_add_texture_position_indice(g->current_mesh, atoi(split[1]));
	free_array(split);
}

void	mesh_parser_add_face(t_glewglew *g, char *line)
{
	char	**split;
	int		i;

	if (g->current_mesh == NULL)
	{
		mesh_parser_add_mesh(g, "o default");
		return ;
	}
	g->current_mesh->current_face = mesh_add_face_indice(g->current_mesh);
	split = ft_split_string(line, " ");
	i = 1;
	while (i < (int)array_length(split))
	{
		mesh_parser_get_face_indices(g, split[i]);
		i++;
	}
	free_array(split);
}
