/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   glewglew_material_parser.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jguyet <jguyet@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/10 20:30:22 by jguyet            #+#    #+#             */
/*   Updated: 2018/03/10 20:30:24 by jguyet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#define GLEWGLEW_PROGRAMME

#include "glewglew.h"

void	material_parser_new_material(t_glewglew *g, char *line)
{
	t_material	*material;
	char		**split;

	split = ft_split_string(line, " ");
	if (array_length(split) == 2)
	{
		material = new_material(split[1]);
		g->materials_map->add(g->materials_map, material->name, material);
		g->current_material = material;
		ft_printf("Add Material \"%s\"\n", split[1]);
	}
	free_array(split);
}

void	material_parser_add_diffuse(t_glewglew *g, char *line)
{
	char		**split;

	if (g->current_material == NULL)
		return ;
	split = ft_split_string(line, " ");
	if (array_length(split) == 4)
	{
		g->current_material->block.diffuse[0] = atof(split[1]);
		g->current_material->block.diffuse[1] = atof(split[2]);
		g->current_material->block.diffuse[2] = atof(split[3]);
		g->current_material->block.diffuse[3] = 1.0f;
		ft_printf("diffuse (%s,%s,%s)\n", split[1], split[2], split[3]);
	}
	free_array(split);
}

void	material_parser_add_diffuse_texture(t_glewglew *g, char *line)
{
	char		**split;

	if (g->current_material == NULL)
		return ;
	split = ft_split_string(line, " ");
	if (array_length(split) == 2)
	{
		if (g->current_material->diffuse_texture != NULL)
			free(g->current_material->diffuse_texture);
		g->current_material->diffuse_texture = \
		ft_dstrjoin(g->initializer.absolute_path, ft_strdup(split[1]), 2);
		g->current_material->block.diffuse_texture = true;
		ft_printf("diffuse texture \"%s\"\n", split[1]);
	}
	free_array(split);
}
