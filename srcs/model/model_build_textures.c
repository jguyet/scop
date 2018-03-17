/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   model.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jguyet <jguyet@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/16 05:11:38 by jguyet            #+#    #+#             */
/*   Updated: 2018/03/16 05:11:40 by jguyet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "scop.h"
#include "glewglew.h"

void			build_model_textures(t_model *model)
{
	int		i;
	t_mesh	*mesh;

	i = -1;
	while (++i < model->glewglew->meshs_size)
	{
		mesh = model->glewglew->meshs[i];
		if (mesh->material->block.diffuse_texture)
		{
			mesh->material->diffuse_texture_id =\
			load_bmp(mesh->material->diffuse_texture);
			if (mesh->material->diffuse_texture_id == 0)
			{
				mesh->material->diffuse_texture_id =\
				load_bmp("assets/poney.bmp");
			}
		}
	}
}
