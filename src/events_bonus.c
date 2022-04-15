/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zezzine <zezzine@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/09 18:21:47 by zezzine           #+#    #+#             */
/*   Updated: 2022/03/25 13:02:28 by zezzine          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	ft_translate(int key, t_fdf *fdf)
{
	int	i;
	int	j;

	i = 0;
	while (i < fdf->map.row)
	{
		j = 0;
		while (j < fdf->map.column)
		{
			if (key == 13)
				fdf->map.matrix[i][j].y -= 10;
			else if (key == 0)
				fdf->map.matrix[i][j].x -= 10;
			else if (key == 1)
				fdf->map.matrix[i][j].y += 10;
			else if (key == 2)
				fdf->map.matrix[i][j].x += 10;
			j++;
		}
		i++;
	}
	draw_line(fdf, 0x00FFCC00);
}

void	zoom_out(t_fdf *fdf)
{
	int	i;
	int	j;

	i = 0;
	while (i < fdf->map.row)
	{
		j = 0;
		while (j < fdf->map.column)
		{
			fdf->map.matrix[i][j].x = (WIDTH / 6)
				+ ((((5 * WIDTH) / 6) - (WIDTH / 6))
					/ WIDTH) * fdf->map.matrix[i][j].x;
			fdf->map.matrix[i][j].y = (HEIGHT / 6)
				+ ((((5 * HEIGHT) / 6) - (HEIGHT / 6))
					/ HEIGHT) * fdf->map.matrix[i][j].y;
			j++;
		}
		i++;
	}
	draw_line(fdf, 0x00FFCC00);
}

void	zoom_in(t_fdf *fdf)
{
	int	i;
	int	j;

	i = 0;
	while (i < fdf->map.row)
	{
		j = 0;
		while (j < fdf->map.column)
		{
			fdf->map.matrix[i][j].x = (WIDTH / -4)
				+ ((((5 * WIDTH) / 4) - (WIDTH / -4))
					/ WIDTH) * fdf->map.matrix[i][j].x;
			fdf->map.matrix[i][j].y = (HEIGHT / -4)
				+ ((((5 * HEIGHT) / 4) - (HEIGHT / -4))
					/ HEIGHT) * fdf->map.matrix[i][j].y;
			j++;
		}
		i++;
	}
	draw_line(fdf, 0x00FFCC00);
}

void	coloring(t_fdf *fdf)
{
	static int	color = 0;

	color++;
	if (color == 5)
		color = 0;
	if (color == 0)
		draw_line(fdf, 0x00FFCC00);
	else if (color == 1)
		draw_line(fdf, 0x0000CCFF);
	else if (color == 2)
		draw_line(fdf, 0x00FF00FF);
	else if (color == 3)
		draw_line(fdf, 0x00FF0000);
	else if (color == 4)
		draw_line(fdf, 0x000000FF);
}

void	events(int key, t_fdf *fdf)
{
	if (key == 13 || key == 0 || key == 1 || key == 2)
		ft_translate(key, fdf);
	else if (key == 24)
		zoom_in(fdf);
	else if (key == 27)
		zoom_out(fdf);
	else if (key == 8)
		coloring(fdf);
}
