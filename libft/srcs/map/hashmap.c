/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hashmap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jguyet <jguyet@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/23 15:42:27 by jguyet            #+#    #+#             */
/*   Updated: 2017/02/23 15:42:29 by jguyet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#define PROG_MAP_FT
#include "mapft.h"

/*
** GENERATE KEY METHOD
*/

int			parsekey(t_hashmap *table, void *key)
{
	unsigned long int	hashkey;
	int					i;

	i = 0;
	hashkey = 0;
	if (table->type == STRING_MAPFT)
	{
		while (hashkey < ULONG_MAX && (*(char*)key))
		{
			hashkey = hashkey << 8;
			hashkey += (*(char*)key);
			i++;
			key++;
		}
	}
	else if (table->type == INTEGER_MAPFT)
		hashkey = (unsigned long int)key;
	return (hashkey % table->map_size);
}

/*
** INTEGER HASHMAP __CONTRUCTOR
*/

t_hashmap	*newintegerhashmap(int size)
{
	t_hashmap	*new;
	int			i;

	i = -1;
	if (!(new = (t_hashmap*)malloc(sizeof(t_hashmap))))
		return (NULL);
	new->add = add_hash;
	new->get = get_hash_value;
	new->clear = clear_hashtable;
	new->tostring = tostring_hashtable;
	new->foreach = foreach_hashtable;
	new->remove = remove_element_on_hashtable;
	new->map_size = size;
	new->type = INTEGER_MAPFT;
	new->size = 0;
	if (!(new->hashtable = (t_hash**)malloc(sizeof(t_hash*) * new->map_size)))
		return (NULL);
	while (++i < new->map_size)
		new->hashtable[i] = NULL;
	return (new);
}

/*
** STRING HASHMAP __CONTRUCTOR
*/

t_hashmap	*newstringhashmap(int size)
{
	t_hashmap	*new;
	int			i;

	i = -1;
	if (!(new = (t_hashmap*)malloc(sizeof(t_hashmap))))
		return (NULL);
	new->add = add_hash;
	new->get = get_hash_value;
	new->clear = clear_hashtable;
	new->tostring = tostring_hashtable;
	new->foreach = foreach_hashtable;
	new->remove = remove_element_on_hashtable;
	new->map_size = size;
	new->type = STRING_MAPFT;
	new->size = 0;
	if (!(new->hashtable = (t_hash**)malloc(sizeof(t_hash*) * new->map_size)))
		return (NULL);
	while (++i < new->map_size)
		new->hashtable[i] = NULL;
	return (new);
}

/*
** HASHMAP __DESTRUCTOR
*/

void		destruct_hashmap(t_hashmap *table,\
	void (*keyfunc)(), void (*valuefunc)())
{
	table->clear(table, keyfunc, valuefunc);
	free(table->hashtable);
	free(table);
}
