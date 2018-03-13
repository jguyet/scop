/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shader.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jguyet <jguyet@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/10 15:53:13 by jguyet            #+#    #+#             */
/*   Updated: 2018/03/10 15:53:14 by jguyet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "scop.h"

static BOOLEAN			compile_source_shader(unsigned int source_id,\
	const char *source_content)
{
	int				log_length;
	char			*logs;
	BOOLEAN			result;

	glShaderSource(source_id, 1, &source_content, NULL);
	glCompileShader(source_id);
	glGetShaderiv(source_id, GL_COMPILE_STATUS, &result);
	glGetShaderiv(source_id, GL_INFO_LOG_LENGTH, &log_length);
	if (log_length > 0)
	{
		logs = (GLchar*)malloc(log_length);
		if (logs == NULL)
			return (false);
		bzero(logs, log_length);
		glGetShaderInfoLog(source_id, log_length, &log_length, logs);
		ft_fprintf(2, "Erreur de compilation:\n%s", logs);
		free(logs);
	}
	return (result);
}

static BOOLEAN			build_shader_program(t_shader *shader)
{
	int				log_length;
	char			*logs;
	BOOLEAN			result;

	shader->id = glCreateProgram();
	glAttachShader(shader->id, shader->vertex_shader_id);
	glAttachShader(shader->id, shader->fragment_shader_id);
	glLinkProgram(shader->id);
	glGetProgramiv(shader->id, GL_LINK_STATUS, &result);
	glGetProgramiv(shader->id, GL_INFO_LOG_LENGTH, &log_length);
	if (log_length > 0)
	{
		logs = (GLchar*)malloc(log_length);
		if (logs == NULL)
			return (false);
		bzero(logs, log_length);
		glGetShaderInfoLog(shader->id, log_length, &log_length, logs);
		ft_fprintf(2, "Erreur de compilation:\n%s", logs);
		free(logs);
	}
	glDetachShader(shader->id, shader->vertex_shader_id);
	glDetachShader(shader->id, shader->fragment_shader_id);
	return (result);
}

static unsigned int		load_program_shaders(t_shader *shader,\
	const char *vertex_file_path, const char *fragment_file_path)
{
	shader->vert_content = file_get_contents(vertex_file_path);
	shader->frag_content = file_get_contents(fragment_file_path);
	compile_source_shader(shader->vertex_shader_id, shader->vert_content);
	compile_source_shader(shader->fragment_shader_id, shader->frag_content);
	build_shader_program(shader);
	glDeleteShader(shader->vertex_shader_id);
	glDeleteShader(shader->fragment_shader_id);
	free(shader->vert_content);
	free(shader->frag_content);
	return (shader->id);
}

t_shader				*new_shader(const char *vertex_file_path,\
	const char *fragment_file_path)
{
	t_shader *shader;

	if ((shader = (struct s_shader*)malloc(sizeof(struct s_shader))) == NULL)
		return (NULL);
	shader->vertex_shader_id = glCreateShader(GL_VERTEX_SHADER);
	shader->fragment_shader_id = glCreateShader(GL_FRAGMENT_SHADER);
	shader->id = load_program_shaders(shader, vertex_file_path,\
		fragment_file_path);
	return (shader);
}
