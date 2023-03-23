/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jabecass <jabecass@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/23 17:19:09 by jabecass          #+#    #+#             */
/*   Updated: 2023/03/23 17:19:30 by jabecass         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

int	move(int kp)
{
	char	*t;

	if (data()->count > 0)
		return (0);
	(data())->moves += increase_counter(kp);
	move_handle(kp);
	collectible((data())->map.map);
	finish(data()->map.map);
	paint_canva(32 * (data())->map.map_elem, \
		32 * (data())->map.map_lines, (data())->map.map);
	t = NULL;
	t = ft_itoa((data())->moves);
	mlx_string_put((data())->window.mlx_ptr, \
		(data())->window.win_ptr, 5, 15, 0x000000FF, t);
	free(t);
	return (0);
}
