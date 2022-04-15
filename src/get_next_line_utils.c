/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zezzine <zezzine@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/15 16:57:21 by zezzine           #+#    #+#             */
/*   Updated: 2022/04/15 16:57:24 by zezzine          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_strchr(const char *s, int c)
{
	int		i;
	char	c_chr;

	i = 0;
	c_chr = (char)c;
	while (s[i])
	{
		if (s[i] == c_chr)
			return ((char *)&s[i]);
		i++;
	}
	if (s[i] == c_chr)
	{
		return ((char *)&s[i]);
	}
	return (NULL);
}

char	*ft_strdup(const char *s1)
{
	char	*buffer;
	size_t	i;
	size_t	len;

	if (!s1)
		len = 0;
	else
		len = ft_strlen(s1);
	buffer = (char *)malloc(len + 1);
	if (!buffer)
		return (NULL);
	i = 0;
	while (i < len)
	{
		buffer[i] = s1[i];
		i++;
	}
	buffer[i] = '\0';
	return ((void *)buffer);
}

void	*ft_calloc(size_t count, size_t size)
{
	char	*buffer;
	size_t	b_size;
	size_t	i;

	b_size = count * size;
	buffer = (char *)malloc(b_size);
	if (!buffer)
		return (NULL);
	i = 0;
	while (i < b_size)
	{
		buffer[i] = 0;
		i++;
	}
	return ((void *)buffer);
}

size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	size_t	d_len;
	size_t	s_len;
	size_t	i;
	size_t	j;

	if (!dstsize)
		return (ft_strlen(src));
	d_len = ft_strlen(dst);
	s_len = ft_strlen(src);
	i = d_len;
	j = 0;
	if (dstsize < d_len)
		return (s_len + dstsize);
	while (i < dstsize - 1 && src[j])
	{
		dst[i] = src[j];
		i++;
		j++;
	}
	dst[i] = '\0';
	return (d_len + s_len);
}

size_t	ft_strlen(const char *s)
{
	size_t	i;

	i = 0;
	while (*s)
	{
		i++;
		s++;
	}
	return (i);
}
