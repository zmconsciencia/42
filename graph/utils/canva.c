/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   canva.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jabecass <jabecass@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/22 17:36:47 by jabecass          #+#    #+#             */
/*   Updated: 2023/03/22 17:37:37 by jabecass         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

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
	int		i;
	int		j;

	j = -1;
	w = 0;
	h = 0;
	put_floor(32 * (data())->map.map_elem, 32 * (data())->map.map_lines);
	while (map[++j])
	{
		i = -1;
		while (map[j][++i] && map[j][i] != '\n')
		{
			if (map[j][i] == '1')
				paint_icon(&(data())->border, w, h);
			else if (map[j][i] == '0' || map[j][i] == 'P')
				paint_icon(&(data())->floor, w, h);
			else if (map[j][i] == 'C')
				paint_both(&(data())->collectible, w, h);
			else if (map[j][i] == 'E')
				paint_both(&(data())->exit, w, h);
			w += 32;
		}
		h += 32;
	}
}

void	paint_canva(int w, int h, char **map)
{
	paint_floor(w, h, map);
	paint_icon(&(data())->player.image, (data())->player.x, (data())->player.y);
	mlx_put_image_to_window(data()->window.mlx_ptr, \
		data()->window.win_ptr, data()->image.img_ptr, 0, 0);
}

void	paint_both(t_img *image, int w, int h)
{
	paint_icon(&(data())->floor, w, h);
	paint_icon(image, w, h);
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
