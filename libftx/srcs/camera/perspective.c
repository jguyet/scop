/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   perspective.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jguyet <jguyet@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/11 10:44:59 by jguyet            #+#    #+#             */
/*   Updated: 2018/03/11 10:45:00 by jguyet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftx.h"

#include <math.h>

t_matrix4f	*matrix4f_perspective(float fov, float aspect_ratio, float near, float far)
{
	float		radian_fov;
	t_matrix4f	*m;

	radian_fov = ft_radians(fov);
	m = new_matrix4f();
	m->matrix[0][0] = 1.0f / (aspect_ratio * radian_fov);
	m->matrix[1][1] = 1.0f / radian_fov;
	m->matrix[2][2] = (-1.0f * (near+far)) / (far - near);
	m->matrix[2][3] = -1.0f;
	m->matrix[3][2] = (-1.0f * (2 * far * near)) / (far - near);
	return (m);
}
