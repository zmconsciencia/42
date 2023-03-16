/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jabecass <jabecass@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/08 15:15:48 by jabecass          #+#    #+#             */
/*   Updated: 2023/03/16 14:09:55 by jabecass         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

t_win	new_program(int w, int h, char *str)
{
	void	*mlx_ptr;

	mlx_ptr = mlx_init();
	return((t_win) {mlx_ptr, mlx_new_window(mlx_ptr, w, h, str), w, h});
}

void	my_mlx_pixel_put(t_img data, int x, int y, int color)
{
	char	*dst;

	if (-16777216 != color)
	{
		dst = data.addr + (y * data.line_len + x * (data.bpp / 8));
		*(unsigned int*)dst = color;
	}
}

int	my_mlx_pixel_get(t_img data, int x, int y)
{
	char	*dst;

	dst = data.addr + (y * data.line_len + x * (data.bpp / 8));
	return (*(unsigned int*)dst);
}

t_img	new_img(int w, int h)
{
	t_img	image;

	image.img_ptr = mlx_new_image(data()->window.mlx_ptr, w, h);
	image.addr = mlx_get_data_addr(image.img_ptr, &(image.bpp),
			&(image.line_len), &(image.endian));
	image.w = w;
	image.h = h;
	return (image);
}

int     exit_tutorial(t_win *window)
{
	if (window)
	{
		mlx_destroy_image(data()->window.mlx_ptr, data()->image.img_ptr);
		mlx_destroy_window (window->mlx_ptr, window->win_ptr);
	}
	exit(1);
}
