/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   file_get_contents.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jguyet <jguyet@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/08 13:27:27 by jguyet            #+#    #+#             */
/*   Updated: 2018/03/08 13:35:06 by jguyet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

#include <fcntl.h>
#include <unistd.h>
#include <sys/stat.h>
#include <printf.h>

static char	*read_contents(int fd, int size)
{
	int		i;
	int		ret;
	char	buffer[size + 1];
	char	*result;

	i = 0;
	ret = read(fd, buffer, size);
	if (ret == -1)
		return (ft_strnew(0));
	result = ft_strnew(ret);
	ft_memcpy(result, buffer, ret);
	return (result);
}

char	*file_get_contents(const char *filename)
{
	int			fd;
	struct stat	st;
	char		*result;

	if (stat(filename, &st) == -1)
		return (ft_strnew(0));
	fd = open(filename, O_RDONLY);
	if (fd < 0)
	{
		return (ft_strnew(0));
	}
	result = read_contents(fd, st.st_size);
	close(fd);
	return (result);
}
