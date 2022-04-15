/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zezzine <zezzine@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/15 16:57:47 by zezzine           #+#    #+#             */
/*   Updated: 2022/04/15 16:57:49 by zezzine          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H
# include <mlx.h>
# include <math.h>
# include <fcntl.h>
# include <stdlib.h>
# include <unistd.h>
# include "get_next_line.h"
# define HEIGHT 1080.0f
# define WIDTH 1920.0f

typedef struct s_dda{
	int		dx;
	int		dy;
	int		steps;
	float	yinc;
	float	xinc;
}			t_dda;

typedef struct s_data{
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}				t_data;

typedef struct s_point {
	float	y;
	float	x;
	float	z;
	int		color;
}			t_point;

typedef struct s_map {
	t_point	**matrix;
	int		column;
	int		row;
}			t_map;

typedef struct s_fdf {
	void	*mlx;
	void	*win;
	int		width;
	int		height;
	t_map	map;
	t_data	img;
}			t_fdf;

void	free_all(char **strs);
int		my_max(int row, int column);
void	get_map(char *filename, t_fdf *fdf);
void	draw_line(t_fdf *fdf, int color);
void	extension_error(char *s);
void	events(int key, t_fdf *fdf);
int		clean_close(t_fdf *fdf);
int		ft_mouse_input(int key, void *mlx_win);
int		ft_input(int key, t_fdf *fdf);
void	draw_line(t_fdf *fdf, int color);
void	isometric(t_fdf *fdf);
void	ft_putstr(char *s);
void	error(char *s);
void	set_2d(t_fdf *fdf);
void	set_point(t_map *map, int i, int j, char **strs);
void	_help(int j, int i, t_fdf *fdf, char **strs);
int		ft_atoi(const char *str);
char	**ft_split(char const *s, char c);
int		ft_strncmp(const char *s1, const char *s2, size_t n);
char	*ft_strrchr(const char *s, int c);

#endif
