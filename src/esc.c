/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   esc.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zezzine <zezzine@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/23 19:40:37 by zezzine           #+#    #+#             */
/*   Updated: 2022/03/25 13:02:18 by zezzine          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	clean_close(t_fdf *fdf)
{
	mlx_destroy_window(fdf->mlx, fdf->win);
	exit(0);
}

int	ft_iso(int key, t_fdf *fdf)
{
	static char	iso = 0;

	if (key == 34)
	{
		if (iso == 0)
		{
			set_2d(fdf);
			draw_line(fdf, 0x00FFCC00);
			iso = 1;
		}
		else
		{
			isometric(fdf);
			draw_line(fdf, 0x00FFCC00);
			iso = 0;
		}
	}
	return (0);
}

int	ft_input(int key, t_fdf *fdf)
{
	if (key == 53)
		clean_close(fdf);
	if (key == 34 || key == 45)
		ft_iso(key, fdf);
	else
		events(key, fdf);
	return (0);
}
