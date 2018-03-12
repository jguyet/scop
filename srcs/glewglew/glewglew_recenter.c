/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   glewglew_recenter.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jguyet <jguyet@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/12 04:52:00 by jguyet            #+#    #+#             */
/*   Updated: 2018/03/12 04:52:01 by jguyet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#define GLEWGLEW_PROGRAMME

#include "glewglew.h"

void        glewglew_recenter(t_mesh *mesh)
{
    int i;

    i = 0;
    while (i < (mesh->vertexs_length * 3))
    {
        mesh->vertexs[i + 0] = mesh->vertexs[i + 0] -\
        (float)((mesh->max.x + mesh->min.x) / 2.f);
        mesh->vertexs[i + 1] = mesh->vertexs[i + 1] -\
        (float)((mesh->max.y + mesh->min.y) / 2.f);
        mesh->vertexs[i + 2] = mesh->vertexs[i + 2] -\
        (float)((mesh->max.z + mesh->min.z) / 2.f);
        i += 3;
    }
}
