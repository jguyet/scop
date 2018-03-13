/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   window.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jguyet <jguyet@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/08 13:04:27 by jguyet            #+#    #+#             */
/*   Updated: 2018/03/08 13:04:28 by jguyet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "scop.h"

void				build_window(t_scop *s)
{
	int flags;

	if (SDL_Init(SDL_INIT_VIDEO) == -1)
	{
		ft_printf("Can't init SDL:  %s\n", SDL_GetError());
		exit(0);
	}
	flags = SDL_WINDOW_OPENGL;
	s->window = SDL_CreateWindow("Scop",\
	SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED,\
	s->screen->width, s->screen->height, flags);
	if (!s->window)
	{
		ft_printf("Couldn't create window: %s\n", SDL_GetError());
		exit(0);
	}
}

void				destruct_window(t_scop *s)
{
	SDL_DestroyWindow(s->window);
}
