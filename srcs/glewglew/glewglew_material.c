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
	material->block.ambiante[0] = 0.0f;
	material->block.ambiante[1] = 0.0f;
	material->block.ambiante[2] = 0.0f;
	material->block.ambiante[3] = 1.0f;
	material->block.specular[0] = 0.0f;
	material->block.specular[1] = 0.0f;
	material->block.specular[2] = 0.0f;
	material->block.specular[3] = 1.0f;
	material->block.emission[0] = 0.0f;
	material->block.emission[1] = 0.0f;
	material->block.emission[2] = 0.0f;
	material->block.emission[3] = 1.0f;
	material->block.shininess = 0.0f;
	material->block.diffuse_texture = false;
	material->block.specular_texture = false;
	material->block.ambiante_texture = false;
	material->diffuse_texture = NULL;
	material->specular_texture = NULL;
	material->ambiante_texture = NULL;
}

void			destruct_material(t_material *material)
{
	if (material->diffuse_texture != NULL)
		free(material->diffuse_texture);
	if (material->specular_texture != NULL)
		free(material->specular_texture);
	if (material->ambiante_texture != NULL)
		free(material->ambiante_texture);
	free(material->name);
	free(material);
}
