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

t_screen	*new_screen(void)
{
	t_screen	*screen;

	if (!(screen = (struct s_screen*)malloc(sizeof(struct s_screen))))
		return (NULL);
	initialize_screen(screen);
	return (screen);
}

void		initialize_screen(t_screen *screen)
{
	screen->width = 0;
	screen->height = 0;
	screen->middle_width = 0;
	screen->middle_heigth = 0;
}
