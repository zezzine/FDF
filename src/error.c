/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zezzine <zezzine@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/22 08:02:39 by zezzine           #+#    #+#             */
/*   Updated: 2022/03/26 14:55:58 by zezzine          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	free_all(char **strs)
{
	int	i;

	i = 0;
	while (strs[i])
		free(strs[i++]);
	free(strs);
}

void	error(char *s)
{
	ft_putstr(s);
	exit(1);
}

void	extension_error(char *s)
{
	if (ft_strncmp(s + ft_strlen(s) - 4, ".fdf", 4) != 0)
		error("Map should be .fdf!\n");
}
