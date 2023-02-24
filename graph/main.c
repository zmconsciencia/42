/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jabecass <jabecass@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/17 16:16:59 by jabecass          #+#    #+#             */
/*   Updated: 2023/02/24 19:28:18 by jabecass         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

void	my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
	char	*dst;

	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int*)dst = color;
}

void	put_block(t_data *data, coords starting_point, coords endpoint, int color)
{
	int a;
	int b;
	int	j;
	int	k;

	a = starting_point.x;
	b = starting_point.y;
	j = endpoint.x;
	k = endpoint.y;
	while (b < k)
	{
		while (a++ < j)
			my_mlx_pixel_put(data, a, b, color);
		a = starting_point.x;
		b++;
	}
}

void	put_line(t_data *data, int length, int color1, int color2, coords starting_point, coords endpoint, int controller)
{
	int	i;

	i = 1;
	while (i++ <= length)
	{
		if (i % 2 != 0)
			put_block(data, starting_point, endpoint, color1);
		else
			put_block(data, starting_point, endpoint, color2);
		starting_point.x += controller;
		endpoint.x += controller;
	}
}

int	main(void)
{
	t_data		img;
	void		*mlx;
	void		*mlx_win;
	coords		starting_point;
	coords		endpoint;
	int			controller;
	int			j;

	j = 1;
	starting_point.x = 5;
	starting_point.y = 5;
	controller = 50;
	endpoint.x = starting_point.x + controller;
	endpoint.y = starting_point.y + controller;
	mlx = mlx_init();
	mlx_win = mlx_new_window(mlx, 1920, 1080, "Graph");
	img.img = mlx_new_image(mlx, 1920, 1080);
	img.addr = mlx_get_data_addr(img.img, &img.bits_per_pixel, &img.line_length,\
		&img.endian);
	while (j++ <= 8)
	{
		if (j % 2 != 0)
			put_line(&img, 8, RED, LIGHT_BLUE, starting_point, endpoint, controller);
		else
			put_line(&img, 8, LIGHT_BLUE, RED, starting_point, endpoint, controller);
		starting_point.y += controller;
		endpoint.y += controller;
	}
	mlx_put_image_to_window(mlx, mlx_win, img.img, 0, 0);
	mlx_loop(mlx);
}