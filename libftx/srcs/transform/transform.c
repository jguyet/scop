/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   transform.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jguyet <jguyet@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/08 18:57:18 by jguyet            #+#    #+#             */
/*   Updated: 2017/10/08 18:57:19 by jguyet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftx.h"

#include <stdlib.h>

t_transform	*new_transform(void)
{
	t_transform	*t;

	if (!(t = (t_transform*)malloc(sizeof(struct s_transform))))
		return (NULL);
	t->position = new_vector3f(0, 0, 0);
	t->rotation = new_vector3f(0, 0, 0);
	t->scale = new_vector3f(0, 0, 0);
	return (t);
}

void		destruct_transform(t_transform *t)
{
	destruct_vector3f(t->position);
	destruct_vector3f(t->rotation);
	destruct_vector3f(t->scale);
	free(t);
}
