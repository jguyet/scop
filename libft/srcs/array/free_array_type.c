/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_array_type.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jguyet <jguyet@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/10 19:42:56 by jguyet            #+#    #+#             */
/*   Updated: 2018/03/10 19:49:16 by jguyet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

#include <stdlib.h>

void	free_array_type(void **array, unsigned int size, const char *type)
{
	unsigned int	i;

	i = 0;
	while (i < size)
	{
		if (ft_strcmp("float**", type) == 0)
			free(((float**)array)[i]);
		else if (ft_strcmp("int**", type) == 0)
			free(((int**)array)[i]);
		else if (ft_strcmp("char**", type) == 0)
			free(((char**)array)[i]);
		else if (ft_strcmp("unsigned int**", type) == 0)
			free(((unsigned int**)array)[i]);
		i++;
	}
	free(array);
}
