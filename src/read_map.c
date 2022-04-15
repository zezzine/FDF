/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zezzine <zezzine@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/10 12:39:38 by zezzine           #+#    #+#             */
/*   Updated: 2022/03/26 14:53:53 by zezzine          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	my_max(int row, int column)
{
	if (row < column)
		return (column);
	else if (row > column)
		return (row);
	return (row);
}

int	numbers_in_line(char *line)
{
	int		count;
	char	**strs;

	strs = ft_split(line, ' ');
	count = 0;
	while (strs[count])
		count++;
	free_all(strs);
	return (count);
}

t_map	check_file_map(char *filename)
{
	t_map	map;
	int		fd;
	int		pre_column;
	char	*line;

	map.matrix = NULL;
	map.row = 0;
	map.column = 0;
	fd = open(filename, O_RDONLY);
	line = get_next_line(fd);
	if (fd == -1 || line == NULL)
		error("Error Map or file doesn't exist\n");
	while (line)
	{
		map.column = numbers_in_line(line);
		if (map.row && pre_column != map.column)
			error("Map formula invalid!\n");
		pre_column = map.column;
		free(line);
		map.row++;
		line = get_next_line(fd);
	}
	close(fd);
	return (map);
}

void	set_point(t_map *map, int i, int j, char **strs)
{
	map->matrix[i][j].z = ft_atoi(strs[j]);
	map->matrix[i][j].x = (float)j * ((HEIGHT
				/ (float)my_max(map->row, map->column)));
	map->matrix[i][j].y = (float)i * ((HEIGHT
				/ (float)my_max(map->row, map->column)));
}

void	get_map(char *filename, t_fdf *fdf)
{
	char	*line;
	char	**strs;
	int		fd;
	int		i;
	int		j;

	fdf->map = check_file_map(filename);
	fd = open(filename, O_RDONLY);
	if (fd < 0)
		error("Map doesn't exist\n");
	fdf->map.matrix = (t_point **)malloc(sizeof(t_point *)
			* (fdf->map.row + 1));
	i = -1;
	while (++i < fdf->map.row)
	{
		fdf->map.matrix[i] = (t_point *)malloc(sizeof(t_point)
				* (fdf->map.column + 1));
		line = get_next_line(fd);
		strs = ft_split(line, ' ');
		free(line);
		j = -1;
		_help(j, i, fdf, strs);
	}
	fdf->map.matrix[i] = NULL;
	close(fd);
}
