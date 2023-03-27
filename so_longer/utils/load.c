/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   load.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jabecass <jabecass@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/22 17:34:34 by jabecass          #+#    #+#             */
/*   Updated: 2023/03/22 17:36:18 by jabecass         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

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
