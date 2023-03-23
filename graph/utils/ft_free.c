/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jabecass <jabecass@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/23 16:00:55 by jabecass          #+#    #+#             */
/*   Updated: 2023/03/23 18:17:44 by jabecass         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

int	free_arr(char **map)
{
	int	i;

	i = -1;
	if (!map)
		return (1);
	while (map[++i])
	{
		free(map[i]);
	}
	free(map);
	return (1);
}

void	ft_free(void)
{
	mlx_destroy_image((data())->window.mlx_ptr, (data())->player.image.img_ptr);
	mlx_destroy_image((data())->window.mlx_ptr, (data())->border.img_ptr);
	mlx_destroy_image((data())->window.mlx_ptr, (data())->floor.img_ptr);
	mlx_destroy_image((data())->window.mlx_ptr, (data())->collectible.img_ptr);
	mlx_destroy_image((data())->window.mlx_ptr, (data())->exit.img_ptr);
	mlx_destroy_image((data())->window.mlx_ptr, (data())->image.img_ptr);
	mlx_destroy_window((data())->window.mlx_ptr, (data())->window.win_ptr);
	mlx_destroy_display((data())->window.mlx_ptr);
	free_arr((data())->map.map);
	free((data())->window.mlx_ptr);
}
