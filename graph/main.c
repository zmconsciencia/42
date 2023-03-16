/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jabecass <jabecass@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/17 16:16:59 by jabecass          #+#    #+#             */
/*   Updated: 2023/03/16 14:28:46 by jabecass         ###   ########.fr       */
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
	put_floor(w, h);
	paint_line(&data()->border, data()->crystal.x, data()->crystal.y, data()->map.map);
	paint_icon(&data()->player, data()->piece.x, data()->piece.y);
	mlx_put_image_to_window(data()->window.mlx_ptr, data()->window.win_ptr, image.img_ptr, 0, 0);
}

void	put_floor(int w, int h)
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

void	paint_line(t_img *image, int x, int y, char **map)
{
	int	i;
	int	j;
	
	j = 0;
	x = 0;
	y = 0;
	while (map[j])
	{
		i = 0;
		while (map[0][i] && map[0][i] == '1')
		{
			paint_icon(image, x, y);
			x += 32;
			i++;
		}
		j++;
		y += 32;
	}
}

void	load_icon(char *path)
{
	(data())->player.img_ptr = mlx_xpm_file_to_image(data()->window.mlx_ptr, path, &data()->player.w, &data()->player.h);
	(data())->player.addr = mlx_get_data_addr(data()->player.img_ptr, &(data()->player.bpp),
			&(data()->player.line_len), &(data()->player.endian));
}

void	load_border(char *path)
{
	(data())->border.img_ptr = mlx_xpm_file_to_image(data()->window.mlx_ptr, path, &data()->border.w, &data()->border.h);
	(data())->border.addr = mlx_get_data_addr(data()->border.img_ptr, &(data()->border.bpp),
			&(data()->border.line_len), &(data()->border.endian));
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
	paint_floor(32 * (data())->map.map_elem, 32 * (data())->map.map_lines);
	return (0);
}

void	initialize()
{
	(data())->window = new_program(32 * (data())->map.map_elem, 32 * (data())->map.map_lines, "so_long");
	if(!data()->window.mlx_ptr || !data()->window.win_ptr)
		exit(1);
	(data())->image = new_img(32 * (data())->map.map_elem, 32 * (data())->map.map_lines);
	(data())->piece.x = 20;
	(data())->piece.y = 20;
	(data())->crystal.x = 0;
	(data())->crystal.y = 0;
	load_border("imgs/bill.xpm");
	load_icon("imgs/hobbit.xpm");
	paint_floor(32 * (data())->map.map_elem, 32 * (data())->map.map_lines);
	mlx_hook(data()->window.win_ptr, 2, 1L<<0, move, data());
	mlx_hook(data()->window.win_ptr, 17, 0, exit_tutorial, data());
	mlx_loop(data()->window.mlx_ptr);
}

int	main(int ac, char **av)
{
	if (ac == 2)
	{
		if (map_checker(av[1]))
			initialize();
	}
	else
		ft_putstr_fd("Wrong number of arguments\n", 2);
	return (0);
}