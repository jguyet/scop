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
		(void)g;
		material = new_material(split[1]);
		g->current_material = material;
		ft_printf("new Material %s\n", split[1]);
	}
	free_array(split);
}

void	material_parser_add_diffuse(t_glewglew *g, char *line)
{
	char		**split;

	split = ft_split_string(line, " ");
	if (array_length(split) == 4)
	{
		(void)g;
		ft_printf("ADD diffuse\n");
	}
	free_array(split);
}

void	material_parser_add_ambiante(t_glewglew *g, char *line)
{
	(void)g;
	(void)line;
	ft_printf("ADD ambiante\n");
}

void	material_parser_add_specular(t_glewglew *g, char *line)
{
	(void)g;
	(void)line;
	ft_printf("ADD specular\n");
}
