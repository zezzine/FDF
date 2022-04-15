/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zezzine <zezzine@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/16 09:42:54 by zezzine           #+#    #+#             */
/*   Updated: 2022/03/25 14:48:19 by zezzine          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	ft_putstr(char *s)
{
	int	i;

	i = 0;
	while (s[i])
	{
		write(2, &s[i], 1);
		i++;
	}
}

void	set_2d(t_fdf *fdf)
{
	int	i;
	int	j;

	i = -1;
	while (++i < fdf->map.row)
	{
		j = -1;
		while (++j < fdf->map.column)
		{
			fdf->map.matrix[i][j].x = (float)j * ((HEIGHT / \
		(float)my_max(fdf->map.row, fdf->map.column)));
			fdf->map.matrix[i][j].y = (float)i * ((HEIGHT / \
		(float)my_max(fdf->map.row, fdf->map.column)));
		}
	}
}

void	_help(int j, int i, t_fdf *fdf, char **strs)
{
	while (++j < fdf->map.column)
			fdf->map.matrix[i][j].z = ft_atoi(strs[j]);
	free_all(strs);
}
