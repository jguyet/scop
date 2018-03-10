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

t_shader		*new_shader(const char * vertex_file_path, const char * fragment_file_path)
{
	t_shader *shader;

	if ((shader = (struct s_shader*)malloc(sizeof(struct s_shader))) == NULL)
		return (NULL);
	shader->id = loadShaders(vertex_file_path, fragment_file_path);
	return (shader);
}

unsigned int	loadShaders(const char * vertex_file_path,const char * fragment_file_path)
{
	GLuint	VertexShaderID = glCreateShader(GL_VERTEX_SHADER);
	GLuint	FragmentShaderID = glCreateShader(GL_FRAGMENT_SHADER);
	char	*vertFileStr = NULL;
	char	*fragFileStr = NULL;
	GLint	Result = GL_FALSE;
	int		InfoLogLength = 0;
	GLchar*	log = NULL;

	vertFileStr = file_get_contents(vertex_file_path);
	fragFileStr = file_get_contents(fragment_file_path);
	char const * VertexSourcePointer = vertFileStr;

	printf("Compiling shader : %s\n", vertex_file_path);
	glShaderSource(VertexShaderID, 1, &VertexSourcePointer , NULL);
	glCompileShader(VertexShaderID);
	glGetShaderiv(VertexShaderID, GL_COMPILE_STATUS, &Result);
	glGetShaderiv(VertexShaderID, GL_INFO_LOG_LENGTH, &InfoLogLength);
	if (InfoLogLength > 0)
	{
		log = (GLchar*)malloc(InfoLogLength);
		if (log == NULL)
		{
			fprintf(stderr,"Erreur d'allocation de mémoire pour le log de la compilation du shader\n");
			return 0;
		}
		bzero(log, InfoLogLength);
		glGetShaderInfoLog(VertexShaderID, InfoLogLength, &InfoLogLength, log);
		fprintf(stderr,"Erreur de compilation:\n%s",log);
		free(log);
	}
	printf("Compiling shader : %s\n", fragment_file_path);
	char const * FragmentSourcePointer = fragFileStr;
	glShaderSource(FragmentShaderID, 1, &FragmentSourcePointer , NULL);
	glCompileShader(FragmentShaderID);
	glGetShaderiv(FragmentShaderID, GL_COMPILE_STATUS, &Result);
	glGetShaderiv(FragmentShaderID, GL_INFO_LOG_LENGTH, &InfoLogLength);
	if (InfoLogLength > 0)
	{
		log = (GLchar*)malloc(InfoLogLength);
		if (log == NULL)
		{
			fprintf(stderr,"Erreur d'allocation de mémoire pour le log de la compilation du shader\n");
			return 0;
		}
		bzero(log, InfoLogLength);
		glGetShaderInfoLog(FragmentShaderID, InfoLogLength, &InfoLogLength, log);
		fprintf(stderr,"Erreur de compilation:\n%s",log);
		free(log);
	}
	GLuint ProgramID = glCreateProgram();
	glAttachShader(ProgramID, VertexShaderID);
	glAttachShader(ProgramID, FragmentShaderID);
	glLinkProgram(ProgramID);
	glGetProgramiv(ProgramID, GL_LINK_STATUS, &Result);
	glGetProgramiv(ProgramID, GL_INFO_LOG_LENGTH, &InfoLogLength);
	if (InfoLogLength > 0)
	{
		log = (GLchar*)malloc(InfoLogLength);
		bzero(log, InfoLogLength);
		if ( log == NULL )
		{
			fprintf(stderr,"Erreur d'allocation de mémoire pour le log de la compilation du shader\n");
			return 0;
		}
		glGetShaderInfoLog(ProgramID, InfoLogLength, &InfoLogLength, log);
		fprintf(stderr,"Erreur de compilation:\n%s",log);
		free(log);

	}
	free(vertFileStr);
	free(fragFileStr);
	glDetachShader(ProgramID, VertexShaderID);
	glDetachShader(ProgramID, FragmentShaderID);
	glDeleteShader(VertexShaderID);
	glDeleteShader(FragmentShaderID);
	return ProgramID;
}
