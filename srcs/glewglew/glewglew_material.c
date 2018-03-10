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

	if ((material = (struct s_material*)malloc(sizeof(struct s_material))) == NULL)
		return (NULL);
	material->name = ft_strdup(name);
	return (material);
}

void			destruct_material(t_material *material)
{
	ft_strdel(&material->name);
	free(material);
}
