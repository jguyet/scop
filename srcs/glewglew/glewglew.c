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
	g->current_mesh = NULL;
	g->current_material = NULL;
	if ((g->meshs = (struct s_mesh**)malloc(sizeof(struct s_mesh*))) == NULL)
		return (NULL);
	g->meshs_size = 0;
	if ((g->materials = (struct s_material**)\
		malloc(sizeof(struct s_material*))) == NULL)
		return (NULL);
	g->materials_size = 0;
	return (g);
}

t_mesh		*glewglew_add_mesh(t_glewglew *g, char *name)
{
	t_mesh	*mesh;
	int		i;
	t_mesh	**meshs;

	mesh = new_mesh(name);
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
	free(g->meshs);
	meshs[i] = mesh;
	g->meshs_size++;
	g->meshs = meshs;
	return (mesh);
}

t_material	*glewglew_add_material(t_glewglew *g, char *name)
{
	t_material	*material;
	int			i;
	t_material	**materials;

	material = new_material(name);
	g->materials_map->add(g->materials_map, name, material);
	if ((materials = (struct s_material**)malloc(sizeof(struct s_material*) *\
	 	(g->materials_size + 1))) == NULL)
		return (NULL);
	i = 0;
	while (i < g->materials_size)
	{
		materials[i] = g->materials[i];
		i++;
	}
	free(g->meshs);
	materials[i] = material;
	g->materials_size++;
	g->materials = materials;
	return (material);
}

void		destruct_glewglew(t_glewglew *g)
{
	int i;

	i = 0;
	while (i < g->meshs_size)
	{
		destruct_mesh(g->meshs[i]);
		i++;
	}
	free(g->meshs);
	i = 0;
	while (i < g->materials_size)
	{
		destruct_material(g->materials[i]);
		i++;
	}
	free(g->materials);
	destruct_hashmap(g->materials_map);
	destruct_hashmap(g->meshs_map);
	free(g);
}
