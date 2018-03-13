/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   load_shaders.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jguyet <jguyet@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/10 16:13:02 by jguyet            #+#    #+#             */
/*   Updated: 2018/03/10 16:13:04 by jguyet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "scop.h"

void		load_shaders(t_scop *scop)
{
	scop->shaders->add(scop->shaders,\
		"global",\
		new_shader("shaders/global.vert", "shaders/global.frag"));
}
