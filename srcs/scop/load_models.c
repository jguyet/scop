/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   load_models.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jguyet <jguyet@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/10 16:13:11 by jguyet            #+#    #+#             */
/*   Updated: 2018/03/10 16:13:13 by jguyet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "scop.h"

void		load_model_position(t_scop *scop, t_model *model)
{
	char	*positions[3];

	positions[0] = scop->properties->get(scop->properties,\
		"scop.model.transform.position.x");
	positions[1] = scop->properties->get(scop->properties,\
		"scop.model.transform.position.y");
	positions[2] = scop->properties->get(scop->properties,\
		"scop.model.transform.position.z");
	if (positions[0] != NULL)
		model->transform.position.x = atof(positions[0]);
	if (positions[1] != NULL)
		model->transform.position.y = atof(positions[1]);
	if (positions[2] != NULL)
		model->transform.position.z = atof(positions[2]);
}

void		load_model_rotation(t_scop *scop, t_model *model)
{
	char	*rotations[3];

	rotations[0] = scop->properties->get(scop->properties,\
		"scop.model.transform.rotation.x");
	rotations[1] = scop->properties->get(scop->properties,\
		"scop.model.transform.rotation.y");
	rotations[2] = scop->properties->get(scop->properties,\
		"scop.model.transform.rotation.z");
	if (rotations[0] != NULL)
		model->transform.rotation.x = atof(rotations[0]);
	if (rotations[1] != NULL)
		model->transform.rotation.y = atof(rotations[1]);
	if (rotations[2] != NULL)
		model->transform.rotation.z = atof(rotations[2]);
}

void		load_model_scale(t_scop *scop, t_model *model)
{
	char	*scales[3];

	scales[0] = scop->properties->get(scop->properties,\
		"scop.model.transform.scale.x");
	scales[1] = scop->properties->get(scop->properties,\
		"scop.model.transform.scale.y");
	scales[2] = scop->properties->get(scop->properties,\
		"scop.model.transform.scale.z");
	if (scales[0])
		model->transform.scale.x = atof(scales[0]);
	if (scales[1])
		model->transform.scale.y = atof(scales[1]);
	if (scales[2])
		model->transform.scale.z = atof(scales[2]);
}

void		load_models(t_scop *scop)
{
	scop->model = new_model(\
		scop->properties->get(scop->properties, "scop.model.path"),\
		scop->shader);
	load_model_position(scop, scop->model);
	load_model_rotation(scop, scop->model);
	load_model_scale(scop, scop->model);
}
