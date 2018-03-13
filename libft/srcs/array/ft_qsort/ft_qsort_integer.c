/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_qsort_integer.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jguyet <jguyet@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/13 18:04:21 by jguyet            #+#    #+#             */
/*   Updated: 2018/03/13 18:10:59 by jguyet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include <stdlib.h>

#include "mapft.h"
#include "libft.h"

static void	cmpqsortinteger(int *base, int *tmp, size_t size,\
	int (*compar)(const void*, const void*))
{
	size_t i;

	i = 0;
	while (i < size)
	{
		if (base[i] != 0 && *tmp != -1\
			&& compar(&base[*tmp], &base[i]) > 0)
			*tmp = i;
		else if (base[i] != 0 && *tmp == -1)
			*tmp = i;
		i++;
	}
}

static void	asigncurrenttabtobaseinteger(int *base, int *tab, size_t size)
{
	size_t i;

	i = 0;
	while (i < size)
	{
		base[i] = 0;
		if (tab[i] != 0)
		{
			base[i] = tab[i];
		}
		i++;
	}
	free(tab);
}

void		ft_qsort_integer(int *base, size_t mmemb,\
			int (*compar)(const void *, const void *), int *tab)
{
	int		tmp;
	size_t	count;

	if (tab == NULL)
		return ;
	count = 0;
	while (1)
	{
		tmp = -1;
		cmpqsortinteger(base, &tmp, mmemb, compar);
		if (tmp == -1)
			break ;
		tab[count++] = base[tmp];
		base[tmp] = 0;
	}
	asigncurrenttabtobaseinteger(base, tab, mmemb);
}
