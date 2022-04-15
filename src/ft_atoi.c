/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zezzine <zezzine@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/15 16:57:03 by zezzine           #+#    #+#             */
/*   Updated: 2022/04/15 16:57:09 by zezzine          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static int	ft_isspace(char c)
{
	if (c == '\t' || c == '\n'
		|| c == '\v' || c == '\f'
		|| c == '\r' || c == ' ')
		return (1);
	return (0);
}

int	ft_isdigit(int c)
{
	if (c >= '0' && c <= '9')
		return (1);
	return (0);
}

static int	fill_buffer(long num, const char *str, int sign, int i)
{
	while (ft_isdigit(str[i]))
	{
		if ((num * 10 + (str[i]) - '0') / 10 != num)
		{
			if (sign == -1)
				return (0);
			return (-1);
		}
		num = num * 10 + (str[i] - '0');
		i++;
	}
	return ((int)(num * sign));
}

int	ft_atoi(const char *str)
{
	long			num;
	size_t			i;
	int				sign;

	num = 0;
	i = 0;
	sign = 1;
	while (ft_isspace(str[i]))
		i++;
	if (str[i] == '-' || str[i] == '+')
	{
		sign *= '+' - str[i] + 1;
		i++;
	}
	return (fill_buffer(num, str, sign, i));
}
