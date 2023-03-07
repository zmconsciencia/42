/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jabecass <jabecass@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/17 16:16:59 by jabecass          #+#    #+#             */
/*   Updated: 2023/03/07 19:25:26 by jabecass         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

void	paint_icon(t_img *image, int x, int y);

all	*data()
{
	static all data;
	
	return (&data);
}

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

void	paint_floor(int w, int h)
{
	t_img	image;
	
	image = data()->image;
	int i;
	int j = 0;
	while (j < h)
	{
		i = 0;
		while (i < w)
		{
			my_mlx_pixel_put(image, i, j, PINK);
			i++;
		}
		j++;
	}
	paint_icon(&data()->pice, data()->piece.x, data()->piece.y);
	mlx_put_image_to_window(data()->window.mlx_ptr, data()->window.win_ptr, image.img_ptr, 0, 0);
}

void	paint_icon(t_img *image, int x, int y)
{	
	int i = 0;
	int j = 0;
	
	
	while (j < image->h)
	{
		i = 0;
		while (i < image->w)
		{
			my_mlx_pixel_put(data()->image, x + i, y + j, my_mlx_pixel_get(*image, i, j));
			i++;
		}
		j++;
	}
}

void	load_icon(char *path)
{

	data()->pice.img_ptr = mlx_xpm_file_to_image(data()->window.mlx_ptr, path, &data()->pice.w, &data()->pice.h);
	data()->pice.addr = mlx_get_data_addr(data()->pice.img_ptr, &(data()->pice.bpp),
			&(data()->pice.line_len), &(data()->pice.endian));
}

int	move(int key_pressed)
{
	if (key_pressed == XK_d)
		data()->piece.x += 16;
	else if (key_pressed == XK_s)
		data()->piece.y += 16;
	else if (key_pressed == XK_a)
		data()->piece.x -= 16;
	else if (key_pressed == XK_w)
		data()->piece.y -= 16;
	paint_floor(300, 300);
	return (0);
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

void	initialize()
{
	data()->window = new_program(300, 300, "so_long");
	if(!data()->window.mlx_ptr || !data()->window.win_ptr)
		exit(1);
	data()->image = new_img(300, 300);
	data()->piece.x = 5;
	data()->piece.y = 5;
	load_icon("chess-pieces/piece1.xpm");
	printf("%i\n", my_mlx_pixel_get(data()->pice, 0, 0));
	paint_floor(300, 300);
	mlx_hook(data()->window.win_ptr, 2, 1L<<0, move, data());
	mlx_hook(data()->window.win_ptr, 17, 0, exit_tutorial, data());
	mlx_loop(data()->window.mlx_ptr);
}

int	main()
{
	initialize();
	return (0);
}
