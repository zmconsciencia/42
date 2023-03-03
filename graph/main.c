/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jabecass <jabecass@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/17 16:16:59 by jabecass          #+#    #+#             */
/*   Updated: 2023/03/03 17:06:42 by jabecass         ###   ########.fr       */
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

	dst = data.addr + (y * data.line_len + x * (data.bpp / 8));
	*(unsigned int*)dst = color;
}

t_img	new_img(int w, int h, t_win window)
{
	t_img	image;

	image.win = window;
	image.img_ptr = mlx_new_image(window.mlx_ptr, w, h);
	image.addr = mlx_get_data_addr(image.img_ptr, &(image.bpp),
			&(image.line_len), &(image.endian));
	image.w = w;
	image.h = h;
	return (image);
}

void	paint_black(int w, int h, t_img data)
{
	int i;
	int j = 0;
	while (j < h)
	{
		i = 0;
		while (i < w)
		{
			my_mlx_pixel_put(data, i, j, BLACK);
			i++;
		}
		j++;
	}
	printf("Ola\n");
}

int	move(int key_pressed, all *new)
{
	if (key_pressed == RIGHT)
		(*new).piece.x += 10;
	else if (key_pressed == DOWN)
		(*new).piece.y += 10;
	else if (key_pressed == LEFT)
		(*new).piece.x -= 10;
	else if (key_pressed == UP)
		(*new).piece.y -= 10;
	paint_black(300, 300, new->image);
	mlx_put_image_to_window(new->window.mlx_ptr, new->window.win_ptr, new->image.img_ptr, 0, 0);
	return (0);
}

int     exit_tutorial(t_win *window)
{
	if (window)
		mlx_destroy_window (window->mlx_ptr, window->win_ptr);
	exit(1);
}

int	main()
{
	t_img	pix;
	all		new;
	char	*relative_path = "./chess-pieces/piece1.xpm";
	
	new.window = new_program(300, 300, "First");
	if(!new.window.mlx_ptr || !new.window.win_ptr)
		return (1);
	pix = new_img(300, 300, new.window);
	pix.img_ptr = mlx_xpm_file_to_image(new.window.mlx_ptr, relative_path, &pix.w, &pix.h);
	pix.addr = mlx_get_data_addr(pix.img_ptr, &pix.bpp, &pix.line_len, &pix.endian);
	mlx_put_image_to_window(new.window.mlx_ptr, new.window.win_ptr, pix.img_ptr, 0, 0);
	mlx_hook(new.window.win_ptr, 2, 1L<<0, move, &new);
	mlx_hook(new.window.win_ptr, 17, 0, exit_tutorial, &new);
	mlx_loop(new.window.mlx_ptr);
	return (0);
}
