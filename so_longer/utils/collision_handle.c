/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   collision_handle.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jabecass <jabecass@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/22 17:49:25 by jabecass          #+#    #+#             */
/*   Updated: 2023/03/23 17:19:28 by jabecass         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

void	collectible(char **map)
{
	map = data()->map.map;
	find_objective(map);
	if (map[data()->player.j][data()->player.i] == 'C')
		map[data()->player.j][data()->player.i] = '0';
}

void	finish(char **map)
{
	map = data()->map.map;
	if ((data())->map.c == 0)
	{
		if (map[data()->player.j][data()->player.i] == 'E')
			data()->count++;
	}
}

int	is_walk(char **map, int key_pressed)
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

void	move_handle(int kp)
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
}

int	increase_counter(int kp)
{
	if ((kp == XK_d || kp == XK_Right) && is_walk((data())->map.map, kp))
		return (1);
	else if ((kp == XK_s || kp == XK_Down) && is_walk((data())->map.map, kp))
		return (1);
	else if ((kp == XK_a || kp == XK_Left) && is_walk((data())->map.map, kp))
		return (1);
	else if ((kp == XK_w || kp == XK_Up) && is_walk((data())->map.map, kp))
		return (1);
	return (0);
}
