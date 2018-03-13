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

# if __APPLE__
#  define GLFW_INCLUDE_GLCOREARB
# endif

# include <libft.h>
# include <printf.h>
# include <libftx.h>

# ifdef linux
#  include <GL/glew.h>
#  include <SDL2/SDL.h>
# endif

# ifdef __APPLE__
#  include <OpenGL/gl3.h>
#  include <SDL2/SDL.h>
# endif

# include <stdlib.h>

# include "glewglew.h"

# define DEGREE_TO_RADIAN (MATHF_PI * 2) / 360

typedef struct		s_bmp
{
	unsigned char	header[54];
	unsigned int	datapos;
	unsigned int	width;
	unsigned int	height;
	unsigned int	imagesize;
	unsigned char	*data;
}					t_bmp;

typedef struct		s_shader
{
	unsigned int	id;
	unsigned int	vertex_shader_id;
	unsigned int	fragment_shader_id;
	char			*vert_content;
	char			*frag_content;
}					t_shader;

typedef struct		s_model
{
	t_shader		*shader;
	t_glewglew		*glewglew;
	unsigned int	vertex_location;
	unsigned int	texture_location;
	unsigned int	projection_location;
	unsigned int	view_location;
	unsigned int	model_location;
	unsigned int	material_location;
	unsigned int	texture_diffuse_location;
}					t_model;

typedef struct		s_keyboard
{
	void			(*handle_event)(struct s_keyboard*, SDL_Event *);
	BOOLEAN			pressedkeys[301];
}					t_keyboard;

typedef struct		s_mouse
{
	t_vector2f		position;
	t_vector2f		lastposition;
	void			(*handle_motion_event)(struct s_mouse*, SDL_Event *);
	void			(*handle_button_event)(struct s_mouse*, SDL_Event *);
	BOOLEAN			pressedbutton[8];
}					t_mouse;

typedef struct		s_screen
{
	unsigned int	width;
	unsigned int	height;
	unsigned int	middle_width;
	unsigned int	middle_height;
}					t_screen;

typedef struct		s_scop
{
	SDL_Window		*window;
	SDL_GLContext	*context;
	t_hashmap		*models;
	t_hashmap		*shaders;
	t_mouse			*mouse;
	t_keyboard		*keyboard;
	t_camera		*camera;
	t_screen		*screen;
}					t_scop;

/*
** BMP
*/
GLuint				load_bmp(const char *imagepath);

/*
** SHADERS
*/
t_shader			*new_shader(const char *vertex_file_path,\
					const char *fragment_file_path);
/*
**	MODELS
*/
t_model				*new_model(const char *file_path, t_shader *shader);
void				destruct_model(t_model *model);
void				load_model_textures(t_model *model);
void				build_model_shader(t_model *model);
void				build_model_vao(t_model *model);
void				draw_model(t_model *model,\
					t_matrix4f *m, t_matrix4f *v, t_matrix4f *p);

/*
** MOUSE
*/
t_mouse				*new_mouse(void);
void				destruct_mouse(t_mouse *mouse);
BOOLEAN				get_button(t_mouse *mouse, unsigned int button);
void				mouse_motion_event_handler(t_mouse *mouse,\
					SDL_Event *event);
void				mouse_button_event_handler(t_mouse *mouse,\
					SDL_Event *event);

/*
** KEYBOARD
*/
t_keyboard			*new_keyboard(void);
void				destruct_keyboard(t_keyboard *keyboard);
BOOLEAN				get_key(t_keyboard *keyboard, unsigned int key);
void				keyboard_event_handler(t_keyboard *keyboard,\
					SDL_Event *event);

/*
** SCREEN
*/
t_screen			*new_screen(int width, int height);
void				destruct_screen(t_screen *screen);

/*
** SCOP
*/
t_scop				*new_scop(void);
t_scop				*static_scop(void);
void				destruct_scop(t_scop *scop);

/*
** SCOP PROGRAMME
*/
void				build_window(t_scop *s);
void				build_context(t_scop *s);
void				load_models(t_scop *scop);
void				load_shaders(t_scop *scop);
void				load_inputs(t_scop *scop);
void				load_camera(t_scop *s);
void				render_loop(t_scop *s);
void				destruct_context(t_scop *s);
void				destruct_window(t_scop *s);

void				build_look_at_projection(t_camera *camera,\
					t_screen *screen);

#endif
