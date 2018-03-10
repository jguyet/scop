/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   model.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jguyet <jguyet@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/10 16:22:39 by jguyet            #+#    #+#             */
/*   Updated: 2018/03/10 16:27:25 by jguyet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "scop.h"
#include "glewglew.h"

t_model			*new_model(const char *file_path, t_shader *shader)
{
	t_model		*m;

	if (!(m = (struct s_model*)malloc(sizeof(struct s_model))))
		return (NULL);
	m->shader = shader;
	m->glewglew = new_glewglew();
	if (m->glewglew->build_file(m->glewglew, file_path, ".obj") == 0)
	{
		return (NULL);
	}
	return (m);
}

void			destruct_model(t_model *model)
{
	destruct_glewglew(model->glewglew);
	free(model);
}
