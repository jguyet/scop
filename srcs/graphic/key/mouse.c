/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mouse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jguyet <jguyet@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/10 16:50:16 by jguyet            #+#    #+#             */
/*   Updated: 2018/03/10 16:50:29 by jguyet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "scop.h"

t_mouse		*new_mouse(void)
{
	t_mouse	*mouse;
	int		i;

	if ((mouse = (struct s_mouse*)malloc(sizeof(struct s_mouse))) == NULL)
		return (NULL);
	initialize_vector2f(&mouse->position);
	initialize_vector2f(&mouse->lastPosition);
	mouse->handle_motion_event = &mouse_motion_event_handler;
	mouse->handle_button_event = &mouse_button_event_handler;
	i = 0;
	while (i < 8)
	{
		mouse->pressedButton[i++] = false;
	}
	return (mouse);
}

void		destruct_mouse(t_mouse *mouse)
{
	free(mouse);
}

void		mouse_motion_event_handler(t_mouse *mouse, SDL_Event *event)
{
	float mw;
	float mh;

	if (event->type != SDL_MOUSEMOTION)
		return ;
	mw = 500;
	mh = 500;
	mouse->lastPosition.x = mouse->position.x;
	mouse->lastPosition.y = mouse->position.y;
	mouse->position.x = -(event->motion.x - mw);
	mouse->position.y = -(event->motion.y - mh);
	if (mouse->lastPosition.x == 0 && mouse->lastPosition.y == 0)
	{
		return ;
	}
}

void		mouse_button_event_handler(t_mouse *mouse, SDL_Event *event)
{
	if (event->type != SDL_MOUSEBUTTONDOWN && event->type != SDL_MOUSEBUTTONUP)
		return ;
	mouse->pressedButton[event->button.button] = \
	(event->type == SDL_MOUSEBUTTONDOWN) ? true : false;
}

BOOLEAN		get_button(t_mouse *mouse, unsigned int button)
{
	return (mouse->pressedButton[button]);
}
