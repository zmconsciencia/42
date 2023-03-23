/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   header.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jabecass <jabecass@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/17 16:15:11 by jabecass          #+#    #+#             */
/*   Updated: 2023/03/23 17:20:09 by jabecass         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HEADER_H
# define HEADER_H

# define BACK 0xc0e070

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 1
# endif

# include "../mlx_linux/mlx.h"
# include <string.h>
# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include <X11/keysym.h>
# include <X11/X.h>
# include <X11/Xlib.h>
# include <fcntl.h>
# include <limits.h>

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

typedef struct s_map{
	char	**map;
	int		map_lines;
	int		map_elem;
	int		c;
}	t_map;

typedef struct s_point{
	int		x;
	int		y;
}	t_point;

typedef struct s_player {
	t_img	image;
	t_point	start;
	int		x;
	int		y;
	int		i;
	int		j;
	int		status;
}	t_player;

typedef struct s_data{
	t_win		window;
	t_img		image;
	t_player	player;
	char		*path;
	t_map		map;
	t_point		piece;
	t_point		crystal;
	t_img		border;
	t_img		floor;
	t_img		collectible;
	t_img		exit;
	int			count;
	int			moves;
}	t_data;

t_win	new_program(int w, int h, char *str);
void	my_mlx_pixel_put(t_img data, int x, int y, int color);
int		my_mlx_pixel_get(t_img data, int x, int y);
t_img	new_img(int w, int h);
void	paint_floor(int w, int h, char **map);
void	paint_icon(t_img *image, int x, int y);
void	load_icon(char *path);
int		move(int key_pressed);
int		exit_tutorial(t_win *window);
void	initialize(void);
t_data	*data(void);
int		map_name(char *pathname);
int		wall_check(char **map);
int		ceiling_check(char **map);
int		floor_check(char **map);
int		border_check(char **map);
void	ft_putstr_fd(char *s, int fd);
int		map_check(char **map, char *pathname);
int		same_size(char **map);
int		line_count(char **map);
char	**load_map_zico(char **map, int fd, int line_count);
int		map_checker(char *map_path);
size_t	ft_strlen(const char *str);
char	*ft_strjoin(char *str1, char *str2);
int		clearstack(char *stack);
char	*get_next_line(int fd);
char	**ft_matrixdup(char **map);
int		elem_count(char *line);
int		path_finder(char	**map);
char	**flood_fill(char **tab, t_point size, t_point begin);
void	put_floor(int w, int h);
t_point	findplayer(char	**map);
void	findp(char	**map);
void	paint_both(t_img *image, int w, int h);
void	paint_canva(int w, int h, char **map);
void	load_icon(char *path);
void	load_border(char *path);
void	load_floor(char *path);
void	load_collectible(char *path);
void	load_exit(char *path);
void	collectible(char **map);
int		is_walk(char **map, int key_pressed);
int		allowed_char(char **map);
int		parse_singles(char **map);
void	find_objective(char **map);
void	finish(char **map);
int		game_loop(void *a);
void	ft_free(void);
int		free_arr(char **map);
char	*ft_itoa(int n);
void	move_handle(int kp);
int	increase_counter(int kp);

#endif