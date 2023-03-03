/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   header.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jabecass <jabecass@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/17 16:15:11 by jabecass          #+#    #+#             */
/*   Updated: 2023/03/03 16:56:29 by jabecass         ###   ########.fr       */
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

#  define LEFT 65361
#  define DOWN 65364
#  define UP 65362
#  define RIGHT 65363

#include "mlx_linux/mlx.h"
#include <string.h>
#include <stdlib.h>
#include <stdio.h>

typedef struct s_win {
	void	*mlx_ptr;
	void	*win_ptr;
	int		height;
	int		width;
}	t_win;

typedef struct s_img {
	t_win	win;
	void	*img_ptr;
	char	*addr;
	int		h;
	int		w;
	int		bpp;
	int		endian;
	int		line_len;
}		t_img;

typedef struct s_piece{
	unsigned short int	x;
	unsigned short int	y;
	t_img			gordo;
} t_piece;

typedef	struct tudo{
	t_win		window;
	t_img		image;
	t_piece		piece;
	char		*path;
}	all;

#endif