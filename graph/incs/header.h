/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   header.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jabecass <jabecass@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/17 16:15:11 by jabecass          #+#    #+#             */
/*   Updated: 2023/03/10 16:18:47 by jabecass         ###   ########.fr       */
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
#  define PINK 14326936

#  define LEFT 65361
#  define DOWN 65364
#  define UP 65362
#  define RIGHT 65363

#include "../mlx_linux/mlx.h"
#include <string.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <X11/keysym.h>
#include <X11/X.h>
#include <X11/Xlib.h>

typedef struct s_win {
	void	*mlx_ptr;
	void	*win_ptr;
	int		height;
	int		width;
}	t_win;

typedef struct s_img {
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

typedef struct s_map {
	char	**map;
	int		width;
	int		height;
}	t_map;

typedef	struct s_data{
	t_win		window;
	t_img		image;
	t_img		pice;
	t_piece		piece;
	char		*path;
}	t_data;

t_win	new_program(int w, int h, char *str);
void	my_mlx_pixel_put(t_img data, int x, int y, int color);
int		my_mlx_pixel_get(t_img data, int x, int y);
t_img	new_img(int w, int h);
void	paint_floor(int w, int h);
void	paint_icon(t_img *image, int x, int y);
void	load_icon(char *path);
int		move(int key_pressed);
int		exit_tutorial(t_win *window);
void	initialize();
t_data	*data();
int		map_name(char *map);
int	wall_check(char **map);
int	ceiling_floor_check(char **map);
int	count_lines(char **map);
int	border_check(char **map);
void	ft_putstr_fd(char *s, int fd);
int map_check(char **map, char *name);
int same_size(char **map);

#endif