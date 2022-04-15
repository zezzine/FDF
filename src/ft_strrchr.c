/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zezzine <zezzine@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/15 16:57:14 by zezzine           #+#    #+#             */
/*   Updated: 2022/04/15 16:57:17 by zezzine          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

char	*ft_strrchr(const char *s, int c)
{
	int		i;
	char	*last_occurence;
	char	c_chr;

	i = 0;
	last_occurence = NULL;
	c_chr = (char)c;
	while (s[i])
	{
		if (s[i] == c_chr)
		{
			last_occurence = (char *)&s[i];
		}
		i++;
	}
	if (s[i] == c_chr)
		last_occurence = (char *)&s[i];
	return (last_occurence);
}
