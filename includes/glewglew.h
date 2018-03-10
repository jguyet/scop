/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   glewglew.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jguyet <jguyet@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/10 12:18:55 by jguyet            #+#    #+#             */
/*   Updated: 2018/03/10 12:19:33 by jguyet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GLEWGLEW_H
# define GLEWGLEW_H

# include <libft.h>
# include <libftx.h>
# include <printf.h>
# include <mapft.h>
# include <unistd.h>
# include <stdlib.h>

typedef struct				s_glewglew_initalizer
{
	char					*filename;
	char					*extension;
	t_hashmap				*lexer_obj;
}							t_glewglew_initalizer;

typedef	struct				s_material
{
	char					*name;
}							t_material;

typedef struct				s_mesh
{
	char					*name;
	float					*vertexs;
	int						vertexs_length;
	float					*normals;
	int						normals_length;
	float					*texturecoords;
	int						texturecoords_length;
	unsigned int			*faces;
	int						faces_length;
	unsigned int			vao;
}							t_mesh;

typedef struct				s_glewglew
{
	t_glewglew_initalizer	initializer;
	int						(*build_file)(struct s_glewglew *, const char *, const char *);
	t_material				**materials;
	int						materials_size;
	t_hashmap				*materials_map;
	t_mesh					**meshs;
	int						meshs_size;
	t_hashmap				*meshs_map;
	t_mesh					*current_mesh;
	t_material				*current_material;
}							t_glewglew;

# ifdef GLEWGLEW_PROGRAMME

/*
** GLEWGLEW PROGRAMME
*/
int							glewglew_build_file(t_glewglew *g, const char *filename, const char *extension);
t_mesh						*glewglew_add_mesh(t_glewglew *g, char *name);
t_material					*glewglew_add_material(t_glewglew *g, char *name);

/*
** MESH
*/
t_mesh						*new_mesh(char *name);
void						destruct_mesh(t_mesh *mesh);
void						parse_obj(t_glewglew *g, char *content);
void						mesh_add_vertex(t_mesh *mesh, float x, float y, float z);
void						mesh_add_normal(t_mesh *mesh, float x, float y, float z);
void						mesh_add_texturecoord(t_mesh *mesh, float x, float y);
void						mesh_add_face(t_mesh *mesh, unsigned int v1, unsigned int v2, unsigned int v3);

void						mesh_parser_add_mesh(t_glewglew *g, char *line);
void						mesh_parser_add_vertex(t_glewglew *g, char *line);
void						mesh_parser_add_texture_position(t_glewglew *g, char *line);
void						mesh_parser_add_normal(t_glewglew *g, char *line);
void						mesh_parser_add_face(t_glewglew *g, char *line);

/*
** MATERIAL
*/
t_material					*new_material(char *name);
void						destruct_material(t_material *material);

# endif

/*
** .obj library
*/
t_glewglew					*new_glewglew(void);
void						destruct_glewglew(t_glewglew *g);

#endif
