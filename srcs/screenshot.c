/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   screenshot.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rotrojan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/11 10:00:57 by rotrojan          #+#    #+#             */
/*   Updated: 2021/03/15 00:43:03 by rotrojan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

/*
** Self explanatory.
*/

static t_error	close_and_return(int fd, t_error error)
{
	close(fd);
	return (error);
}

/*
** Standard bitmap header.
*/

static t_bool	write_header(int fd, int size_data, t_main *main)
{
	unsigned char		header[54];
	int					tmp;

	ft_bzero(header, sizeof(header));
	header[0] = 0x42;
	header[1] = 0x4D;
	tmp = size_data << 16;
	ft_memcpy(&header[2], &tmp, 2);
	header[10] = 54;
	header[14] = 40;
	tmp = main->mlx.win_width;
	ft_memcpy(&header[18], &tmp, 4);
	tmp = main->mlx.win_height;
	ft_memcpy(&header[22], &tmp, 4);
	header[26] = 1;
	header[28] = 24;
	if ((write(fd, header, sizeof(header))) == -1)
		return (FALSE);
	return (TRUE);
}

/*
** The data of each pixel in a bitmap file is not stored the same way and in the
** same order than in the mlx.
*/

static void		fill_data(unsigned char **buffer, int **data, int width,
																	int height)
{
	int				i;
	int				j;
	int				i_data;

	i = 0;
	j = 0;
	i_data = width * height - 1;
	while (j < height)
	{
		while (i < width)
		{
			buffer[0][(j * width + (width - i - 1)) * 3] = (unsigned char)
				(data[0][i_data]);
			buffer[0][(j * width + (width - i - 1)) * 3 + 1] = (unsigned char)
				(data[0][i_data] >> 8);
			buffer[0][(j * width + (width - i - 1)) * 3 + 2] = (unsigned char)
				(data[0][i_data] >> 16);
			i++;
			i_data--;
		}
		i = 0;
		j++;
	}
}

/*
** Write in the file the data stored in the pixel array.
*/

static t_error	write_data(int fd, int nbr_pixel, t_main *main)
{
	unsigned char	*buffer;
	int				size_buffer;
	t_error			ret;

	size_buffer = nbr_pixel * 3;
	if (!(buffer = (unsigned char*)malloc(sizeof(unsigned char) * size_buffer)))
		return (MALLOC_ERR);
	ret = NO_ERROR;
	fill_data(&buffer, &main->mlx.data, main->mlx.win_width,
		main->mlx.win_height);
	if ((write(fd, buffer, size_buffer)) == -1)
		ret = BMP_ERR;
	free(buffer);
	return (ret);
}

/*
** Create the bmp file and init all the variables nedded for the header.
** Then, write the header, fill the file with the data (in the proper order) and
** finally close the file. Checks are made all along.
*/

t_error			screen_shot(t_main *main)
{
	int				fd;
	int				pixel_bytes_per_row;
	int				padding_bytes_per_row;
	int				size_data;
	t_error			ret;

	if ((fd = open("save.bmp", O_CREAT | O_WRONLY | O_TRUNC,
		S_IRUSR | S_IWUSR | S_IRGRP | S_IWGRP | S_IROTH | S_IWOTH)) != -1)
	{
		pixel_bytes_per_row = main->mlx.win_width * 3;
		padding_bytes_per_row = (4 - (pixel_bytes_per_row % 4)) % 4;
		size_data = (pixel_bytes_per_row + padding_bytes_per_row)
			* main->mlx.win_height;
		if (!write_header(fd, size_data, main))
			return (close_and_return(fd, BMP_ERR));
		if ((ret = write_data(fd, main->mlx.win_width * main->mlx.win_height,
			main)) != NO_ERROR)
			return (close_and_return(fd, ret));
		return (close_and_return(fd, NO_ERROR));
	}
	else
		return (close_and_return(fd, BMP_ERR));
}
