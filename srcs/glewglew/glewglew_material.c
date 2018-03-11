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
	initialize_vector4f(&material->diffuse);
	initialize_vector4f(&material->ambiente);
	initialize_vector4f(&material->specular);
	initialize_vector4f(&material->emission);
	material->shininess = 0;
	material->diffuse_texture = NULL;
	material->specular_texture = NULL;
	material->ambiante_texture = NULL;
}

void			destruct_material(t_material *material)
{
	ft_strdel(&material->name);
	free(material);
}
