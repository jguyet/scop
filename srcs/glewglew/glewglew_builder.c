/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   glewglew_builder.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jguyet <jguyet@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/10 12:28:37 by jguyet            #+#    #+#             */
/*   Updated: 2018/03/10 12:28:40 by jguyet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#define GLEWGLEW_PROGRAMME

#include "glewglew.h"

int		glewglew_build_file(t_glewglew *g, const char *filename)
{
	char	*path;
	char	*content;

	path = ft_strjoin(g->initializer.absolute_path, filename);
	content = file_get_contents(path);
	content = ft_replace(content, "\t", "");
	content = ft_replace(content, "\r", "");
	g->initializer.lexer_obj = newstringhashmap(10);
	g->initializer.lexer_obj->add(\
		g->initializer.lexer_obj, "o", &mesh_parser_add_mesh);
	g->initializer.lexer_obj->add(\
		g->initializer.lexer_obj, "v", &mesh_parser_add_vertex);
	g->initializer.lexer_obj->add(\
		g->initializer.lexer_obj, "vt", &mesh_parser_add_texture_position);
	g->initializer.lexer_obj->add(\
		g->initializer.lexer_obj, "vn", &mesh_parser_add_normal);
	g->initializer.lexer_obj->add(\
		g->initializer.lexer_obj, "f", &mesh_parser_add_face);
	g->initializer.lexer_obj->add(\
		g->initializer.lexer_obj, "mtllib", &mesh_parser_add_material);
	parse_obj(g, content);
	free(content);
	free(path);
	destruct_hashmap(g->initializer.lexer_obj);
	return (1);
}

void	parse_obj(t_glewglew *g, char *content)
{
	int		i;
	char	**split;
	char	**split_line;
	void	*ptr;

	i = -1;
	split = ft_split_string(content, "\n");
	while (++i < (int)array_length(split))
	{
		split_line = ft_split_string(split[i], " ");
		if ((int)array_length(split_line) == 0)
		{
			free_array(split_line);
			continue ;
		}
		ptr = g->initializer.lexer_obj->get(g->initializer.lexer_obj,\
			split_line[0]);
		if (ptr != NULL)
			(*(void (*)(struct s_glewglew *g, char *line))ptr)(g, split[i]);
		free_array(split_line);
	}
	free_array(split);
}

int		glewglew_build_material(t_glewglew *g, const char *filename)
{
	char		*path;
	char		*content;

	path = ft_strjoin(g->initializer.absolute_path, filename);
	content = file_get_contents(path);
	content = ft_replace(content, "\t", "");
	content = ft_replace(content, "\r", "");
	g->initializer.lexer_material = newstringhashmap(10);
	g->initializer.lexer_material->add(\
		g->initializer.lexer_material, "newmtl", &material_parser_new_material);
	g->initializer.lexer_material->add(\
		g->initializer.lexer_material, "Ka", &material_parser_add_ambiante);
	g->initializer.lexer_material->add(\
		g->initializer.lexer_material, "Kd", &material_parser_add_diffuse);
	g->initializer.lexer_material->add(\
		g->initializer.lexer_material, "Ks", &material_parser_add_specular);
	parse_material(g, content);
	free(content);
	free(path);
	destruct_hashmap(g->initializer.lexer_material);
	return (1);
}

void	parse_material(t_glewglew *g, char *content)
{
	int		i;
	char	**split;
	char	**split_line;
	void	*ptr;

	i = -1;
	split = ft_split_string(content, "\n");
	while (++i < (int)array_length(split))
	{
		split_line = ft_split_string(split[i], " ");
		if ((int)array_length(split_line) == 0)
		{
			free_array(split_line);
			continue ;
		}
		ptr = g->initializer.lexer_material->get(g->initializer.lexer_material,\
			split_line[0]);
		if (ptr != NULL)
			(*(void (*)(struct s_glewglew *g, char *line))ptr)(g, split[i]);
		free_array(split_line);
	}
	free_array(split);
}
