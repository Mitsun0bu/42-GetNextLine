/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llethuil <llethuil@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/02 15:41:51 by llethuil          #+#    #+#             */
/*   Updated: 2021/12/02 15:54:42 by llethuil         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

char	*get_next_line(int fd)
{
	static char	buff[OPEN_MAX][BUFFER_SIZE + 1] = {};
	char		*line;

	if (fd < 0 || fd > OPEN_MAX || BUFFER_SIZE <= 0)
		return (NULL);
	line = malloc(sizeof(char) * 1);
	if (!line)
		return (NULL);
	line[0] = 0;
	line = ft_get_line(line, buff[fd], fd);
	if (line && ft_strlen(line))
		return (line);
	free (line);
	return (NULL);
}

char	*ft_get_line(char *line, char *buff, int fd)
{
	int	read_ret;

	read_ret = 1;
	while (read_ret > 0)
	{
		line = ft_strjoin(line, buff);
		if (!line)
		{
			free (line);
			return (NULL);
		}
		if (ft_position_nl(buff) != -1)
		{
			ft_save_rest(buff, &buff[ft_position_nl(buff) + 1]);
			return (line);
		}
		read_ret = read(fd, buff, BUFFER_SIZE);
		buff[read_ret] = '\0';
		if (read_ret == -1)
		{
			free (line);
			return (NULL);
		}
	}
	return (line);
}

void	*ft_save_rest(char *buff, char *shifted_buff)
{
	int	i;

	i = 0;
	while (*shifted_buff)
		buff[i++] = *shifted_buff++;
	buff[i] = '\0';
	return (buff);
}
