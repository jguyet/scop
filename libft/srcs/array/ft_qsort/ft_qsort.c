/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_qsort.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jguyet <jguyet@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/04 17:46:50 by jguyet            #+#    #+#             */
/*   Updated: 2017/03/04 17:46:52 by jguyet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include <stdlib.h>

#include "mapft.h"
#include "libft.h"

void		ft_qsort(void *base, size_t mmemb, char *type,\
			int (*compar)(const void *, const void *))
{
	char	**tmpc;
	int		*tmpi;
	size_t	i;

	i = 0;
	if (strcmp(type, "int*") == 0)
	{
		tmpi = malloc(sizeof(int) * mmemb);
		while (i < mmemb)
			tmpi[i++] = 0;
		ft_qsort_integer(base, mmemb, compar, tmpi);
	}
	else if (strcmp(type, "char*") == 0)
	{
		tmpc = malloc(sizeof(char*) * mmemb);
		while (i < mmemb)
			tmpc[i++] = NULL;
		ft_qsort_string(base, mmemb, compar, tmpc);
	}
}
