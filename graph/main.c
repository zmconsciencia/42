/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jabecass <jabecass@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/17 16:16:59 by jabecass          #+#    #+#             */
/*   Updated: 2023/03/10 19:36:28 by jabecass         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

void	paint_icon(t_img *image, int x, int y);

t_data	*data()
{
	static t_data data;
	
	return (&data);
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
	(data())->pice.img_ptr = mlx_xpm_file_to_image(data()->window.mlx_ptr, path, &data()->pice.w, &data()->pice.h);
	(data())->pice.addr = mlx_get_data_addr(data()->pice.img_ptr, &(data()->pice.bpp),
			&(data()->pice.line_len), &(data()->pice.endian));
}

int	move(int key_pressed)
{
	if (key_pressed == XK_d || key_pressed == XK_Right)
		(data())->piece.x += 16;
	else if (key_pressed == XK_s || key_pressed == XK_Down)
		(data())->piece.y += 16;
	else if (key_pressed == XK_a || key_pressed == XK_Left)
		(data())->piece.x -= 16;
	else if (key_pressed == XK_w || key_pressed == XK_Up)
		(data())->piece.y -= 16;
	if (key_pressed == XK_Escape)
		exit_tutorial(&(data())->window);
	paint_floor(300, 300);
	return (0);
}

void	initialize()
{
	(data())->window = new_program(300, 300, "so_long");
	if(!data()->window.mlx_ptr || !data()->window.win_ptr)
		exit(1);
	(data())->image = new_img(300, 300);
	(data())->piece.x = 5;
	(data())->piece.y = 5;
	load_icon("chess-pieces/piece1.xpm");
	paint_floor(300, 300);
	mlx_hook(data()->window.win_ptr, 2, 1L<<0, move, data());
	mlx_hook(data()->window.win_ptr, 17, 0, exit_tutorial, data());
	mlx_loop(data()->window.mlx_ptr);
}

int	main(int ac, char **av)
{
	char *matrix[] = {"1111111111111111111111111111111111","1E0000000000000C00000C000000000001","1010010100100000101001000000010101","1010010010101010001001000000010101","1P0000000C00C0000000000000000000C1","1111111111111111111111111111111111", NULL};
	
	if (ac == 2)
	{
		if (map_check(matrix, av[1]))
			initialize();
	}
	return (0);
}