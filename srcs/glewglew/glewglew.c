/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   glewglew.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jguyet <jguyet@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/10 12:16:29 by jguyet            #+#    #+#             */
/*   Updated: 2018/03/10 12:16:30 by jguyet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#define GLEWGLEW_PROGRAMME

#include "glewglew.h"

t_glewglew	*new_glewglew(void)
{
	t_glewglew	*g;

	if ((g = (struct s_glewglew*)malloc(sizeof(struct s_glewglew))) == NULL)
		return (NULL);
	g->build_file = &glewglew_build_file;
	g->materials_map = newstringhashmap(10);
	g->meshs_map = newstringhashmap(10);
	g->vertexs = newintegerhashmap(10);
	g->texturecoords = newintegerhashmap(10);
	g->current_mesh = NULL;
	g->current_material = NULL;
	g->initializer.absolute_path = NULL;
	g->meshs = NULL;
	g->meshs_size = 0;
	initialize_vector3f(&g->max);
	initialize_vector3f(&g->min);
	return (g);
}

t_mesh		*glewglew_add_mesh(t_glewglew *g, char *name)
{
	t_mesh	*mesh;
	int		i;
	t_mesh	**meshs;

	mesh = new_mesh(name);
	g->meshs_map->remove(g->meshs_map, name);
	g->meshs_map->add(g->meshs_map, name, mesh);
	if ((meshs = (struct s_mesh**)malloc(sizeof(struct s_mesh*) *\
	(g->meshs_size + 1))) == NULL)
		return (NULL);
	i = 0;
	while (i < g->meshs_size)
	{
		meshs[i] = g->meshs[i];
		i++;
	}
	if (g->meshs != NULL)
		free(g->meshs);
	meshs[i] = mesh;
	g->meshs = meshs;
	g->meshs_size++;
	return (mesh);
}

t_material	*glewglew_add_material(t_glewglew *g, char *name)
{
	t_material	*material;

	material = new_material(name);
	g->materials_map->add(g->materials_map, name, material);
	return (material);
}

void		destruct_glewglew(t_glewglew *g)
{
	if (g->meshs != NULL)
		free(g->meshs);
	destruct_hashmap(g->materials_map, free, destruct_material);
	destruct_hashmap(g->meshs_map, free, destruct_mesh);
	destruct_hashmap(g->vertexs, NULL, destruct_vector3f);
	destruct_hashmap(g->texturecoords, NULL, destruct_vector3f);
	free(g->initializer.absolute_path);
	free(g);
}
