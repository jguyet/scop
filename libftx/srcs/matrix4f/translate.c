/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   translate.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jguyet <jguyet@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/15 21:08:16 by jguyet            #+#    #+#             */
/*   Updated: 2018/03/17 11:15:11 by jguyet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftx.h"

t_matrix4f		*matrix_translate(t_vector3f *v)
{
	t_matrix4f	*new;

	new = matrix4f_identity(1.0f);
	new->matrix[3][0] = v->x;
	new->matrix[3][1] = v->y;
	new->matrix[3][2] = v->z;
	return (new);
}
