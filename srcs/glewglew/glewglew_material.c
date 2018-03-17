/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   glewglew_material.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jguyet <jguyet@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/10 12:57:52 by jguyet            #+#    #+#             */
/*   Updated: 2018/03/10 12:57:53 by jguyet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#define GLEWGLEW_PROGRAMME

#include "glewglew.h"

t_material		*new_material(char *name)
{
	t_material	*material;

	if (!(material = (struct s_material*)malloc(sizeof(struct s_material))))
		return (NULL);
	initialize_material(material);
	material->name = ft_strdup(name);
	return (material);
}

void			initialize_material(t_material *material)
{
	material->name = NULL;
	material->block.diffuse[0] = 0.0f;
	material->block.diffuse[1] = 0.0f;
	material->block.diffuse[2] = 0.0f;
	material->block.diffuse[3] = 1.0f;
	material->block.diffuse_texture = true;
	material->block.has_texture_position = false;
	material->diffuse_texture = ft_strdup("assets/poney.bmp");
}

void			destruct_material(t_material *material)
{
	if (material->diffuse_texture != NULL)
		free(material->diffuse_texture);
	free(material->name);
	free(material);
}
