/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   load_inputs.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jguyet <jguyet@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/10 17:33:11 by jguyet            #+#    #+#             */
/*   Updated: 2018/03/10 17:37:01 by jguyet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "scop.h"

int			input_callback_interval(void *userdata, SDL_Event *event)
{
	t_scop	*scop;

	(void)userdata;
	scop = static_scop();
	scop->mouse->handle_motion_event(scop->mouse, event);
	scop->mouse->handle_button_event(scop->mouse, event);
	scop->keyboard->handle_event(scop->keyboard, event);
	return (1);
}

void		load_inputs(t_scop *scop)
{
	scop->keyboard = new_keyboard();
	scop->mouse = new_mouse();
	SDL_AddEventWatch(input_callback_interval, NULL);
}
