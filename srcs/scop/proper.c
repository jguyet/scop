/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   proper.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jguyet <jguyet@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/16 05:19:02 by jguyet            #+#    #+#             */
/*   Updated: 2018/03/16 05:19:04 by jguyet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "mapft.h"
#include "printf.h"
#include <stdlib.h>

static void	add_properties(t_hashmap *prop, const char *line)
{
	char	**split_line;

	split_line = ft_split_string(line, "=");
	if (array_length(split_line) == 2\
		&& prop->get(prop, split_line[0]) == NULL)
	{
		prop->add(prop, split_line[0], ft_strdup(split_line[1]));
	}
	free_array(split_line);
}

t_hashmap	*new_propeties(const char *file_path)
{
	t_hashmap	*prop;
	char		*content;
	char		**split;
	size_t		i;

	prop = newstringhashmap(10);
	i = -1;
	content = file_get_contents(file_path);
	split = ft_split_string(content, "\n");
	while (++i < array_length(split))
	{
		if (ft_strcontains(split[i], "=") == false)
			continue ;
		add_properties(prop, split[i]);
	}
	free_array(split);
	free(content);
	return (prop);
}

void		destruct_properties(t_hashmap *prop)
{
	destruct_hashmap(prop, free, free);
}
