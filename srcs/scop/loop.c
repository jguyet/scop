/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   loop.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jguyet <jguyet@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/08 13:19:12 by jguyet            #+#    #+#             */
/*   Updated: 2018/03/08 13:21:27 by jguyet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "scop.h"

void			render_loop(t_scop *s)
{
	while (1)
	{
		SDL_GL_SwapWindow(s->window);
		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

		SDL_Event	event;
		while(SDL_PollEvent(&event))
		{
			if(event.type == SDL_QUIT)
			{
				return ;
			}
		}
	}
}
