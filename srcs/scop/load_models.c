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

void		load_models(t_scop *scop)
{
	//scop->models->add(scop->models, "42", new_model("objs/42.obj", (t_shader*)scop->shaders->get(scop->shaders, "global")));
	// scop->models->add(scop->models, "plan", new_model("objs/plan.obj", (t_shader*)scop->shaders->get(scop->shaders, "global")));
	scop->models->add(scop->models, "test", new_model("objs/test.obj", (t_shader*)scop->shaders->get(scop->shaders, "global")));
	//scop->models->add(scop->models, "bomb", new_model("objs/bomb.obj", (t_shader*)scop->shaders->get(scop->shaders, "global")));
	//scop->models->add(scop->models, "teapot", new_model("objs/teapot2.obj", (t_shader*)scop->shaders->get(scop->shaders, "global")));
}
