/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zezzine <zezzine@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/15 16:57:28 by zezzine           #+#    #+#             */
/*   Updated: 2022/04/15 16:57:31 by zezzine          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*buffer;
	size_t	i;

	if (!s)
		return (NULL);
	if (ft_strlen(s) <= start)
	{
		buffer = malloc(sizeof(char));
		buffer[0] = '\0';
		return (buffer);
	}
	if (ft_strlen(s) < len)
		len = ft_strlen(s);
	buffer = (char *)malloc(sizeof(char) * (len + 1));
	if (!buffer)
		return (NULL);
	i = 0;
	while (i < len && s[i + start])
	{
		buffer[i] = s[i + start];
		i++;
	}
	buffer[i] = '\0';
	return (buffer);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*buffer;
	size_t	size;

	if (!s1 || !s2)
		return (NULL);
	size = ft_strlen(s1) + ft_strlen(s2);
	buffer = ft_calloc(size + 1, sizeof(char));
	if (!buffer)
		return (NULL);
	ft_strlcat(buffer, (char *)s1, ft_strlen(s1) + 1);
	ft_strlcat(buffer, (char *)s2, size + 1);
	free((void *)s1);
	return (buffer);
}

char	*ft_line(int fd, char *backup)
{
	char	*line;
	char	*tmp;
	int		i;

	tmp = ft_calloc(BUFFER_SIZE + 1, sizeof(char));
	line = ft_strdup(backup);
	while (!ft_strchr(line, '\n'))
	{
		i = read(fd, tmp, BUFFER_SIZE);
		if (i < 0)
		{
			free(tmp);
			free(line);
			return (NULL);
		}
		if (i == 0)
			break ;
		tmp[i] = '\0';
		line = ft_strjoin(line, tmp);
	}
	free(tmp);
	return (line);
}

char	*handle_return(char **backup, char **line)
{
	char	*tmp;

	*backup = ft_substr(*line, ft_strchr(*line, '\n') - *line + 1, -1);
	if (!**backup)
	{
		free(*backup);
		*backup = NULL;
	}
	tmp = ft_substr(*line, 0, ft_strchr(*line, '\n') - *line + 1);
	free(*line);
	return (tmp);
}

char	*get_next_line(int fd)
{
	static char	*backup[OPEN_MAX];
	char		*line;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	line = ft_line(fd, backup[fd]);
	if (backup[fd] && *backup[fd])
	{
		free(backup[fd]);
		backup[fd] = NULL;
	}
	if (!line)
		return (NULL);
	if (!*line)
	{
		free(line);
		return (NULL);
	}
	if (ft_strchr(line, '\n') == NULL)
		return (line);
	return (handle_return(&backup[fd], &line));
}
