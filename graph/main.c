/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jabecass <jabecass@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/17 16:16:59 by jabecass          #+#    #+#             */
/*   Updated: 2023/02/17 18:35:20 by jabecass         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

void	my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
	char	*dst;

	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int*)dst = color;
}

int	main(void)
{
	t_data	img;
	void	*mlx;
	void	*mlx_win;
	int		x;
	int		y;

	x = 5;
	y = 5;
	mlx = mlx_init();
	mlx_win = mlx_new_window(mlx, 1920, 1080, "Graph");
	img.img = mlx_new_image(mlx, 1920, 1080);
	img.addr = mlx_get_data_addr(img.img, &img.bits_per_pixel, &img.line_length,\
		&img.endian);
	while (x++ <= 100)
		my_mlx_pixel_put(&img, x, y, 0x00FF0000);
	while (y++ <= 100)
		my_mlx_pixel_put(&img, x, y, 0x00FF0000);
	while (x-- > 5)
		my_mlx_pixel_put(&img, x, y, 0x00FF0000);
	while (y-- > 5)
		my_mlx_pixel_put(&img, x, y, 0x00FF0000);
	mlx_put_image_to_window(mlx, mlx_win, img.img, 0, 0);
	mlx_loop(mlx);
}