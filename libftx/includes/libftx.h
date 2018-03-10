/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libftx.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jguyet <jguyet@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/08/21 00:27:38 by jguyet            #+#    #+#             */
/*   Updated: 2016/08/21 00:37:38 by jguyet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFTX_H
# define LIBFTX_H

# include <unistd.h>

# define MATHF_PI 3.14159

/*
**STRUCT libx
*/
typedef struct	s_vector2f
{
	float		x;
	float		y;
}				t_vector2f;

typedef struct	s_vector3f
{
	float		x;
	float		y;
	float		z;
}				t_vector3f;

typedef struct	s_vector4f
{
	float		x;
	float		y;
	float		z;
	float		w;
}				t_vector4f;

typedef struct	s_matrix4f
{
	float		matrix[4][4];
}				t_matrix4f;

typedef struct	s_transform
{
	t_vector3f	position;
	t_vector3f	rotation;
	t_vector3f	scale;
}				t_transform;

typedef struct	s_camera
{
	t_transform	*transform;
	t_matrix4f	*projection;
	float		fov;
	float		aspect_ratio;
	float		near;
	float		far;
	t_matrix4f	*model;
	t_matrix4f	*view;
	t_matrix4f	*matrix;
}				t_camera;

/*
** Vector2f
*/
t_vector2f		*new_vector2f(float x, float y);
t_vector2f		*initialize_vector2f(t_vector2f *v);
void			destruct_vector2f(t_vector2f *v);
float			v2f_sqrt(t_vector2f *v);
float			v2f_magnitude(t_vector2f *v);
t_vector2f		*v2f_normalize(t_vector2f *v);

/*
** Vector3f
*/
t_vector3f		*new_vector3f(float x, float y, float z);
t_vector3f		*initialize_vector3f(t_vector3f *v);
void			destruct_vector3f(t_vector3f *v);
float			v3f_sqrt(t_vector3f *v);
float			v3f_magnitude(t_vector3f *v);
t_vector3f		*v3f_normalize(t_vector3f *v);
t_vector3f		*v3f_cross(t_vector3f *v1, t_vector3f *v2);
t_vector3f		*v3f_mul(t_vector3f *v1, t_vector3f *v2);
float			ft_dot(t_vector3f *r1, t_vector3f *r2);

/*
** Vector4f
*/
t_vector4f		*new_vector4f(float x, float y, float z, float w);
t_vector4f		*initialize_vector4f(t_vector4f *v);
void			destruct_vector4f(t_vector4f *v);
float			v4f_sqrt(t_vector4f *v);
float			v4f_magnitude(t_vector4f *v);
t_vector4f		*v4f_normalize(t_vector4f *v);

/*
** Matrix4f
*/
t_matrix4f		*new_matrix4f(void);
t_matrix4f		*initialize_matrix4f(t_matrix4f *m);
void			destruct_matrix4f(t_matrix4f *m);
t_matrix4f		*matrix4f_identity(void);
t_matrix4f		*copy_matrix4f(t_matrix4f *origin);
t_matrix4f		*matrix4f_mul(t_matrix4f *m, t_matrix4f *m2);
t_vector3f		*apply_matrix4f_to_vertex(t_matrix4f *m, t_vector3f *v);
t_vector4f		*apply_matrix4f_to_vertex4f(t_matrix4f *m, t_vector4f *src);
t_matrix4f		*matrix4f_translate(t_vector3f *v);
t_matrix4f		*matrix_rotate(t_matrix4f *matrix, float angle,\
				t_vector3f *type);

/*
**	Mathf
*/
float			ft_radians(float degrees);
float			ft_clamp(float value, float max, float min);

/*
** Transform
*/
t_transform		*new_transform(void);
t_transform		*initialize_transform(t_transform *t);
void			destruct_transform(t_transform *t);

/*
** Camera
*/
t_camera		*new_camera(void);
void			destruct_camera(t_camera *c);

#endif
