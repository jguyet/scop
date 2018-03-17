/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keyboard.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jguyet <jguyet@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/10 16:50:08 by jguyet            #+#    #+#             */
/*   Updated: 2018/03/10 16:50:39 by jguyet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "scop.h"

t_keyboard		*new_keyboard(void)
{
	t_keyboard	*keyboard;
	int			i;

	if (!(keyboard = (struct s_keyboard*)malloc(sizeof(struct s_keyboard))))
		return (NULL);
	keyboard->handle_event = &keyboard_event_handler;
	i = 0;
	while (i < 301)
	{
		keyboard->downkeys[i] = false;
		keyboard->pressedkeys[i] = false;
		i++;
	}
	return (keyboard);
}

void			destruct_keyboard(t_keyboard *keyboard)
{
	free(keyboard);
}

void			keyboard_event_handler(t_keyboard *keyboard, SDL_Event *event)
{
	if (event->type != SDL_KEYDOWN && event->type != SDL_KEYUP)
		return ;
	keyboard->pressedkeys[event->key.keysym.scancode] =\
	(event->type == SDL_KEYDOWN \
		|| (event->type == SDL_KEYDOWN && event->key.repeat)) ? true : false;
	keyboard->downkeys[event->key.keysym.scancode] =\
	(event->type == SDL_KEYDOWN && !event->key.repeat) ? true : false;
}

BOOLEAN			get_key(t_keyboard *keyboard, unsigned int key)
{
	return (keyboard->pressedkeys[key]);
}

BOOLEAN			get_keydown(t_keyboard *keyboard, unsigned int key)
{
	return (keyboard->downkeys[key]);
}
