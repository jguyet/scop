/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_qsort_string.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jguyet <jguyet@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/13 18:04:16 by jguyet            #+#    #+#             */
/*   Updated: 2018/03/13 18:10:33 by jguyet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include <stdlib.h>

#include "mapft.h"
#include "libft.h"

static void	cmpqsortstring(char **base, int *tmp, size_t size,\
			int (*compar)(const void*, const void*))
{
	size_t i;

	i = 0;
	while (i < size)
	{
		if (base[i] != NULL && *tmp != -1\
			&& compar(base[*tmp], base[i]) > 0)
			*tmp = i;
		else if (base[i] != NULL && *tmp == -1)
			*tmp = i;
		i++;
	}
}

static void	asigncurrenttabtobase(char **base, char **tab, size_t size)
{
	size_t i;

	i = 0;
	while (i < size)
	{
		base[i] = NULL;
		if (tab[i] != NULL)
		{
			base[i] = tab[i];
		}
		i++;
	}
	free(tab);
}

void		ft_qsort_string(char **base, size_t mmemb,\
		int (*compar)(const void *, const void *), char **tab)
{
	int		tmp;
	size_t	count;

	if (tab == NULL)
		return ;
	count = 0;
	while (1)
	{
		tmp = -1;
		cmpqsortstring(base, &tmp, mmemb, compar);
		if (tmp == -1)
			break ;
		tab[count++] = base[tmp];
		base[tmp] = NULL;
	}
	asigncurrenttabtobase(base, tab, mmemb);
}
