/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zezzine <zezzine@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/10 12:41:05 by zezzine           #+#    #+#             */
/*   Updated: 2022/03/25 12:53:02 by zezzine          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
	char	*dst;

	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int *)dst = color;
}

void	dda(t_point p1, t_point p2, t_fdf *fdf, int color)
{
	float	x;
	float	y;
	int		i;
	t_dda	dda;

	y = p1.y;
	x = p1.x;
	i = 0;
	dda.dx = p2.x - p1.x;
	dda.dy = p2.y - p1.y;
	if (abs(dda.dx) > abs(dda.dy))
		dda.steps = abs(dda.dx);
	else
		dda.steps = abs(dda.dy);
	dda.xinc = dda.dx / (float)dda.steps;
	dda.yinc = dda.dy / (float)dda.steps;
	while (i <= dda.steps)
	{
		if ((x >= 0 && x < WIDTH) && (y >= 0 && y < HEIGHT))
			my_mlx_pixel_put(&fdf->img, x, y, color);
		x += dda.xinc;
		y += dda.yinc;
		i++;
	}
}

void	draw_line(t_fdf *fdf, int color)
{
	int			x;
	int			y;

	fdf->img.img = mlx_new_image(fdf->mlx, fdf->width, fdf->height);
	fdf->img.addr = mlx_get_data_addr(fdf->img.img, &fdf->img.bits_per_pixel,
			&fdf->img.line_length, &fdf->img.endian);
	y = 0;
	while (y < fdf->map.row)
	{
		x = 0;
		while (x < fdf->map.column)
		{
			if (x + 1 < fdf->map.column)
				dda(fdf->map.matrix[y][x],
					fdf->map.matrix[y][x + 1], fdf, color);
			if (y + 1 < fdf->map.row)
				dda(fdf->map.matrix[y][x],
					fdf->map.matrix[y + 1][x], fdf, color);
			x++;
		}
		y++;
	}
	mlx_put_image_to_window(fdf->mlx, fdf->win, fdf->img.img, 0, 0);
	mlx_destroy_image(fdf->mlx, fdf->img.img);
}

void	isometric(t_fdf *fdf)
{
	int	i;
	int	j;
	int	x;
	int	y;

	i = 0;
	while (i < fdf->map.row)
	{
		j = 0;
		while (j < fdf->map.column)
		{
			x = fdf->map.matrix[i][j].x;
			y = fdf->map.matrix[i][j].y;
			fdf->map.matrix[i][j].x = (x - y) / 2 + (WIDTH / 2);
			fdf->map.matrix[i][j].y = (x + y) / 4
				- fdf->map.matrix[i][j].z * 2 + (HEIGHT / 4);
			j++;
		}
		i++;
	}
}
