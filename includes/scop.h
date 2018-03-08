/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   scop.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jguyet <jguyet@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/07 15:33:02 by jguyet            #+#    #+#             */
/*   Updated: 2017/10/07 15:33:20 by jguyet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCOP_H
# define SCOP_H

# include <libft.h>
# include <printf.h>
# include <libftx.h>

# ifdef linux
#   include <GL/glew.h>
#   include <SDL2/SDL.h>
# endif

# ifdef __APPLE__
#   include <OpenGL/gl3.h>
#   include <SDL2/SDL.h>
# endif

# include <stdlib.h>

typedef struct	s_scop
{

}				t_scop;

t_scop				*new_scop(void);
t_scop				*static_scop(void);
void				destruct_scop(t_scop *scop);

#endif