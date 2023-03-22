/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initialize.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jabecass <jabecass@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/22 17:53:43 by jabecass          #+#    #+#             */
/*   Updated: 2023/03/22 17:54:05 by jabecass         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

t_data	*data(void)
{
	static t_data	data;

	return (&data);
}

void	initialize(void)
{
	(data())->window = new_program(32 * (data())->map.map_elem, \
		32 * (data())->map.map_lines, "so_long");
	if (!data()->window.mlx_ptr || !data()->window.win_ptr)
		exit(1);
	(data())->image = new_img(32 * (data())->map.map_elem, \
		32 * (data())->map.map_lines);
	findp((data())->map.map);
	load_border("imgs/walls.xpm");
	load_icon("imgs/hobbit.xpm");
	load_floor("imgs/floor.xpm");
	load_collectible("imgs/white_crystal.xpm");
	load_exit("imgs/black_crystal.xpm");
	paint_canva(32 * (data())->map.map_elem, \
		32 * (data())->map.map_lines, (data())->map.map);
	mlx_hook(data()->window.win_ptr, 2, 1L << 0, move, data());
	mlx_hook(data()->window.win_ptr, 17, 0, exit_tutorial, data());
	mlx_loop(data()->window.mlx_ptr);
}
