/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zezzine <zezzine@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/15 11:16:28 by zezzine           #+#    #+#             */
/*   Updated: 2022/03/26 12:28:45 by zezzine          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	main(int ac, char **av)
{
	t_fdf	*fdf;

	if (ac != 2)
		error("Wrong argument!!\n");
	fdf = (t_fdf *)malloc(sizeof(t_fdf));
	if (!fdf)
		return (0);
	if (ac < 2 || ac > 2)
		error("Bad Arguments\n");
	fdf->height = HEIGHT;
	fdf->width = WIDTH;
	fdf->mlx = mlx_init();
	fdf->win = mlx_new_window(fdf->mlx, WIDTH, HEIGHT, "FDF !");
	extension_error(av[1]);
	get_map(av[1], fdf);
	set_2d(fdf);
	isometric(fdf);
	draw_line(fdf, 0x00FFCC00);
	mlx_key_hook(fdf->win, ft_input, fdf);
	mlx_hook(fdf->win, 17, 0, clean_close, fdf);
	mlx_loop(fdf->mlx);
}
