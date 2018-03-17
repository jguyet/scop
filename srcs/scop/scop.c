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
#include "glewglew.h"

t_scop				*new_scop(void)
{
	static t_scop	*s = NULL;

	if (s != NULL)
		return (s);
	if ((s = (struct s_scop*)malloc(sizeof(struct s_scop))) == NULL)
		return (NULL);
	s->model = NULL;
	s->shader = NULL;
	s->screen = new_screen(1280, 1280);
	s->texture = true;
	s->rotate = true;
	s->model_path = ft_strdup("assets/42.obj");
	s->properties = new_propeties("scop.properties");
	return (s);
}

t_scop				*static_scop(void)
{
	return (new_scop());
}

void				load_args(t_scop *scop, int argc, char **argv)
{
	if (argc != 2)
		return ;
	free(scop->model_path);
	scop->model_path = ft_strdup(argv[1]);
}

int					main(int argc, char **argv)
{
	t_scop	*scop;

	scop = static_scop();
	build_window(scop);
	build_context(scop);
	load_args(scop, argc, argv);
	if (file_exists(scop->model_path) == false)
	{
		ft_fprintf(2, "File \"%s\"doesn't exists\n", scop->model_path);
		return (1);
	}
	load_shaders(scop);
	load_models(scop);
	load_inputs(scop);
	load_camera(scop);
	render_loop(scop);
	destruct_context(scop);
	destruct_window(scop);
	return (0);
}
