/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bmp.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jguyet <jguyet@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/13 02:56:06 by jguyet            #+#    #+#             */
/*   Updated: 2018/03/13 02:56:07 by jguyet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "scop.h"

GLuint		bind_texture(unsigned int width,\
	unsigned int height, unsigned char *data)
{
	GLuint	textureid;

	glGenTextures(1, &textureid);
	glBindTexture(GL_TEXTURE_2D, textureid);
	glTexImage2D(GL_TEXTURE_2D, 0,\
		GL_RGB, width, height, 0, GL_BGR, GL_UNSIGNED_BYTE, data);
	glTexParameteri(GL_TEXTURE_2D,\
		GL_TEXTURE_MAG_FILTER, GL_LINEAR);
	glTexParameteri(GL_TEXTURE_2D,\
		GL_TEXTURE_MIN_FILTER, GL_LINEAR_MIPMAP_LINEAR);
	glGenerateMipmap(GL_TEXTURE_2D);
	return (textureid);
}

BOOLEAN		build_header(t_bmp *bmp, FILE *file, const char *imagepath)
{
	if (!file)
	{
		ft_printf("Image \"%s\" doesn't exists\n", imagepath);
		return (false);
	}
	if (fread(bmp->header, 1, 54, file) != 54)
	{
		ft_printf("Image \"%s\" as not a correct BMP file Header too small\n",\
			imagepath);
		fclose(file);
		return (false);
	}
	if (bmp->header[0] != 'B' || bmp->header[1] != 'M')
	{
		ft_printf(\
			"Image \"%s\" as not a correct BMP file No BM Magick Number\n",\
			imagepath);
		fclose(file);
		return (false);
	}
	return (true);
}

BOOLEAN		build_data(t_bmp *bmp, FILE *file)
{
	bmp->datapos = *(int*)&(bmp->header[0x0A]);
	bmp->imagesize = *(int*)&(bmp->header[0x22]);
	bmp->width = *(int*)&(bmp->header[0x12]);
	bmp->height = *(int*)&(bmp->header[0x16]);
	if (bmp->imagesize == 0)
		bmp->imagesize = bmp->width * bmp->height * 3;
	if (bmp->datapos == 0)
		bmp->datapos = 54;
	bmp->data = (unsigned char*)malloc(bmp->imagesize);
	if (!bmp->data)
		return (0);
	fread(bmp->data, 1, bmp->imagesize, file);
	return (true);
}

GLuint		load_bmp(const char *imagepath)
{
	struct s_bmp	bmp;
	GLuint			textureid;
	FILE			*file;
	char			**split;

	split = ft_split_string(imagepath, ".");
	if (ft_strcmp(split[array_length(split) - 1], "bmp") != 0)
	{
		ft_printf("\"%s\" Not a correct BMP file\n", imagepath);
		free_array(split);
		return (0);
	}
	free_array(split);
	file = fopen(imagepath, "rb");
	if (build_header(&bmp, file, imagepath) == false)
		return (0);
	build_data(&bmp, file);
	fclose(file);
	textureid = bind_texture(bmp.width, bmp.height, bmp.data);
	free(bmp.data);
	return (textureid);
}
