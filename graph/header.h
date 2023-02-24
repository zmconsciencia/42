/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   header.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jabecass <jabecass@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/17 16:15:11 by jabecass          #+#    #+#             */
/*   Updated: 2023/02/24 22:39:50 by jabecass         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HEADER_H
# define HEADER_H

#  define LIGHT_BLUE 0x0099FFFF
#  define YELLOW 0x00FFFF00
#  define RED 0x00FF0000
#  define BLUE 0x000033FF
#  define GREEN 0x0000CC00
#  define BLACK 0x00000000
#  define PURPLE 0x00000033	
#  define WHITE 0x00FFFFFF


#include "mlx_linux/mlx.h"

typedef struct s_data {
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}	t_data;

typedef struct cordenadas {
	int	x;
	int	y;
}	coords;


#endif