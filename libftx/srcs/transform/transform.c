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
	initialize_transform(t);
	return (t);
}

t_transform	*initialize_transform(t_transform *t)
{
	initialize_vector3f(&t->position);
	initialize_vector3f(&t->rotation);
	initialize_vector3f(&t->scale);
	return (t);
}

void		destruct_transform(t_transform *t)
{
	free(t);
}
