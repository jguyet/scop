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

	if (g->current_material == NULL)
		return ;
	split = ft_split_string(line, " ");
	if (array_length(split) == 4)
	{
		g->current_material->diffuse.x = atof(split[1]);
		g->current_material->diffuse.y = atof(split[2]);
		g->current_material->diffuse.z = atof(split[3]);
		g->current_material->diffuse.w = 1.0f;
		ft_printf("ADD diffuse\n");
	}
	free_array(split);
}

void	material_parser_add_ambiante(t_glewglew *g, char *line)
{
	char		**split;

	if (g->current_material == NULL)
		return ;
	split = ft_split_string(line, " ");
	if (array_length(split) == 4)
	{
		g->current_material->ambiente.x = atof(split[1]);
		g->current_material->ambiente.y = atof(split[2]);
		g->current_material->ambiente.z = atof(split[3]);
		g->current_material->ambiente.w = 1.0f;
		ft_printf("ADD ambient\n");
	}
	free_array(split);
}

void	material_parser_add_specular(t_glewglew *g, char *line)
{
	char		**split;

	if (g->current_material == NULL)
		return ;
	split = ft_split_string(line, " ");
	if (array_length(split) == 4)
	{
		g->current_material->specular.x = atof(split[1]);
		g->current_material->specular.y = atof(split[2]);
		g->current_material->specular.z = atof(split[3]);
		g->current_material->specular.w = 1.0f;
		ft_printf("ADD specular\n");
	}
	free_array(split);
}

void	material_parser_add_diffuse_texture(t_glewglew *g, char *line)
{
	char		**split;

	if (g->current_material == NULL)
		return ;
	split = ft_split_string(line, " ");
	if (array_length(split) == 1)
	{
		g->current_material->diffuse_texture = ft_strdup(split[1]);
		ft_printf("ADD diffuse texture\n");
	}
	free_array(split);
}

void	material_parser_add_specular_texture(t_glewglew *g, char *line)
{
	char		**split;

	if (g->current_material == NULL)
		return ;
	split = ft_split_string(line, " ");
	if (array_length(split) == 1)
	{
		g->current_material->specular_texture = ft_strdup(split[1]);
		ft_printf("ADD specular texture\n");
	}
	free_array(split);
}

void	material_parser_add_ambient_texture(t_glewglew *g, char *line)
{
	char		**split;

	if (g->current_material == NULL)
		return ;
	split = ft_split_string(line, " ");
	if (array_length(split) == 1)
	{
		g->current_material->ambiante_texture = ft_strdup(split[1]);
		ft_printf("ADD ambient texture\n");
	}
	free_array(split);
}
