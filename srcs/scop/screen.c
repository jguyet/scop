/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   screen.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jguyet <jguyet@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/11 17:16:10 by jguyet            #+#    #+#             */
/*   Updated: 2018/03/11 17:25:23 by jguyet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "scop.h"

t_screen	*new_screen(int width, int height)
{
	t_screen	*screen;

	if (!(screen = (struct s_screen*)malloc(sizeof(struct s_screen))))
		return (NULL);
	screen->width = width;
	screen->height = height;
	screen->middle_width = screen->width / 2;
	screen->middle_height = screen->height / 2;
	return (screen);
}

void		destruct_screen(t_screen *screen)
{
	free(screen);
}
