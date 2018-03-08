/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   scop.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jguyet <jguyet@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/07 15:31:16 by jguyet            #+#    #+#             */
/*   Updated: 2018/03/08 13:02:11 by jguyet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "scop.h"

t_scop				*new_scop(void)
{
	static t_scop	*s = NULL;

	if (s != NULL)
		return (s);
	if ((s = (struct s_scop*)malloc(sizeof(struct s_scop))) == NULL)
		return (NULL);
	return (s);
}

t_scop				*static_scop(void)
{
	return (new_scop());
}

void				destruct_scop(t_scop *scop)
{
	free(scop);
}

int					main(int argc, char **argv)
{
	t_scop	*scop;

	(void)argc;
	(void)argv;

	scop = static_scop();
	build_window(scop);
	build_context(scop);

	render_loop(scop);

	destruct_context(scop);
	destruct_window(scop);
	destruct_scop(scop);
	return (0);
}
