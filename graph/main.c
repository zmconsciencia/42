/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jabecass <jabecass@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/17 16:16:59 by jabecass          #+#    #+#             */
/*   Updated: 2023/03/21 19:20:51 by jabecass         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

t_data	*data(void)
{
	static t_data	data;

	return (&data);
}

void	put_floor(int w, int h)
{
	t_img	image;
	int		i;
	int		j;

	image = data()->image;
	j = 0;
	while (j < h)
	{
		i = 0;
		while (i < w)
		{
			my_mlx_pixel_put(image, i, j, BACK);
			i++;
		}
		j++;
	}
}

void	paint_floor(int w, int h, char **map)
{
	t_img	image;
	int		i;
	int		j;

	j = 0;
	w = 0;
	h = 0;
	image = data()->image;
	put_floor(32 * (data())->map.map_elem, 32 * (data())->map.map_lines);
	while (map[j])
	{
		i = -1;
		while (map[j][++i] && map[j][i] != '\n')
		{
			if (map[j][i] == '1')
				paint_icon(&(data())->border, w, h);
			else if (map[j][i] == '0' || map[j][i] == 'P')
				paint_icon(&(data())->floor, w, h);
			else if (map[j][i] == 'C')
			{
				paint_icon(&(data())->floor, w, h);
				paint_icon(&(data())->collectible, w, h);
			}
			else if (map[j][i] == 'E')
			{
				paint_icon(&(data())->floor, w, h);
				paint_icon(&(data())->exit, w, h);
			}
			w += 32;
		}
		j++;
		h += 32;
	}
	paint_icon(&(data())->player.image, (data())->player.x, (data())->player.y);
	mlx_put_image_to_window(data()->window.mlx_ptr, data()->window.win_ptr, image.img_ptr, 0, 0);
}

void	paint_icon(t_img *image, int x, int y)
{	
	int	j;
	int	i;

	i = 0;
	j = 0;
	while (j < image->h)
	{
		i = 0;
		while (i < image->w)
		{
			my_mlx_pixel_put(data()->image, x + i, y + j, \
				my_mlx_pixel_get(*image, i, j));
			i++;
		}
		j++;
	}
}

void	load_icon(char *path)
{
	(data())->player.image.img_ptr = \
		mlx_xpm_file_to_image(data()->window.mlx_ptr, \
			path, &data()->player.image.w, &data()->player.image.h);
	(data())->player.image.addr = \
		mlx_get_data_addr(data()->player.image.img_ptr, \
			&(data()->player.image.bpp), \
			&(data()->player.image.line_len), &(data()->player.image.endian));
}

void	load_border(char *path)
{
	(data())->border.img_ptr = \
		mlx_xpm_file_to_image(data()->window.mlx_ptr, \
			path, &data()->border.w, &data()->border.h);
	(data())->border.addr = mlx_get_data_addr(data()->border.img_ptr, \
		&(data()->border.bpp), \
			&(data()->border.line_len), &(data()->border.endian));
}

void	load_floor(char *path)
{
	(data())->floor.img_ptr = \
		mlx_xpm_file_to_image(data()->window.mlx_ptr, \
			path, &data()->floor.w, &data()->floor.h);
	(data())->floor.addr = \
		mlx_get_data_addr(data()->floor.img_ptr, &(data()->floor.bpp), \
			&(data()->floor.line_len), &(data()->floor.endian));
}

void	load_collectible(char *path)
{
	(data())->collectible.img_ptr = \
		mlx_xpm_file_to_image(data()->window.mlx_ptr, \
			path, &data()->collectible.w, &data()->collectible.h);
	(data())->collectible.addr = \
		mlx_get_data_addr(data()->collectible.img_ptr, \
			&(data()->collectible.bpp), \
			&(data()->collectible.line_len), &(data()->collectible.endian));
}

void	load_exit(char *path)
{
	(data())->exit.img_ptr = \
		mlx_xpm_file_to_image(data()->window.mlx_ptr, \
			path, &data()->exit.w, &data()->exit.h);
	(data())->exit.addr = \
		mlx_get_data_addr(data()->exit.img_ptr, &(data()->exit.bpp), \
			&(data()->exit.line_len), &(data()->exit.endian));
}

void	collectible(char **map)
{
	map = data()->map.map;
	if (map[data()->player.j][data()->player.i] == 'C')
	{
		map[data()->player.j][data()->player.i] = '0';
	}
}

int		is_walk(char **map, int	key_pressed)
{
	map = (data())->map.map;
	if (key_pressed == XK_d || key_pressed == XK_Right)
	{
		if (map[data()->player.j][data()->player.i + 1] != '1') 
			return (1);
	}
	else if (key_pressed == XK_s || key_pressed == XK_Down)
	{
		if (map[data()->player.j + 1][data()->player.i] != '1')
			return (1);
	}
	else if (key_pressed == XK_a || key_pressed == XK_Left)
	{
		if (map[data()->player.j][data()->player.i - 1] != '1')
			return (1);
	}
	else if (key_pressed == XK_w || key_pressed == XK_Up)
	{
		if (map[data()->player.j - 1][data()->player.i] != '1')
			return (1);
	}
	return (0);
}

int	move(int kp)
{
	if ((kp == XK_d || kp == XK_Right) && is_walk((data())->map.map, kp))
	{
		(data())->player.x += 32;
		(data())->player.i++;
	}
	else if ((kp == XK_s || kp == XK_Down) && is_walk((data())->map.map, kp))
	{
		(data())->player.y += 32;
		(data())->player.j++;
	}
	else if ((kp == XK_a || kp == XK_Left) && is_walk((data())->map.map, kp))
	{
		(data())->player.x -= 32;
		(data())->player.i--;
	}
	else if ((kp == XK_w || kp == XK_Up) && is_walk((data())->map.map, kp))
	{
		(data())->player.y -= 32;
		(data())->player.j--;
	}
	if (kp == XK_Escape)
		exit_tutorial(&(data())->window);
	collectible((data())->map.map);
	paint_floor(32 * (data())->map.map_elem, \
		32 * (data())->map.map_lines, (data())->map.map);
	return (0);
}

void	initialize()
{
	(data())->window = new_program(32 * (data())->map.map_elem, \
		32 * (data())->map.map_lines, "so_long");
	if (!data()->window.mlx_ptr || !data()->window.win_ptr)
		exit(1);
	(data())->image = new_img(32 * (data())->map.map_elem, \
		32 * (data())->map.map_lines);
	findP((data())->map.map);
	load_border("imgs/walls.xpm");
	load_icon("imgs/hobbit.xpm");
	load_floor("imgs/floor.xpm");
	load_collectible("imgs/white_crystal.xpm");
	load_exit("imgs/black_crystal.xpm");
	paint_floor(32 * (data())->map.map_elem, \
		32 * (data())->map.map_lines, (data())->map.map);
	mlx_hook(data()->window.win_ptr, 2, 1L << 0, move, data());
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