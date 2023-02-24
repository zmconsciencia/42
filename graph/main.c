/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jabecass <jabecass@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/17 16:16:59 by jabecass          #+#    #+#             */
/*   Updated: 2023/02/23 10:26:15 by jabecass         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

void	my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
	char	*dst;

	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int*)dst = color;
}

void	put_block(t_data *data, coords starting_point, coords size, int color)
{
	int a;
	int b;

	a = starting_pixel;
	b = starting_pixel;
	while (b < size_y)
	{
		while (a++ < size_x)
			my_mlx_pixel_put(data, a, b, color);
		a = starting_pixel;
		b++;
	}
}

int	main(void)
{
	t_data	img;
	void	*mlx;
	void	*mlx_win;
	int		starting_point;
	int		size;

	starting_point = 5;
	size = 25;
	mlx = mlx_init();
	mlx_win = mlx_new_window(mlx, 1920, 1080, "Graph");
	img.img = mlx_new_image(mlx, 1920, 1080);
	img.addr = mlx_get_data_addr(img.img, &img.bits_per_pixel, &img.line_length,\
		&img.endian);
	put_block(&img, starting_point, size, size, RED);
    starting_point += size + 5;
	size += starting_point;
    put_block(&img, starting_point, size, size, WHITE);
	mlx_put_image_to_window(mlx, mlx_win, img.img, 0, 0);
	mlx_loop(mlx);
}