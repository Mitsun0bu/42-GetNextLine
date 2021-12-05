/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llethuil <llethuil@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/02 15:42:24 by llethuil          #+#    #+#             */
/*   Updated: 2021/12/05 11:23:58 by llethuil         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	if (!str)
		return (0);
	while (str[i])
		i++;
	return (i);
}

int	ft_position_nl(char *str)
{
	int	i;

	i = 0;
	if (!str)
		return (-1);
	while (str[i])
	{
		if (str[i] == '\n')
			return (i);
		i++;
	}
	return (-1);
}

char	*ft_strjoin(char *line, char *buff)
{
	char	*joined;
	int		buff_size;
	int		i_l;
	int		i_b;

	if (ft_position_nl(buff) != -1)
		buff_size = ft_position_nl(buff) + 1;
	else
		buff_size = ft_strlen(buff);
	joined = malloc(sizeof(char) * (ft_strlen(line) + buff_size + 1));
	if (!joined)
		return (NULL);
	i_l = -1;
	while (line[++i_l])
		joined[i_l] = line[i_l];
	free(line);
	i_b = 0;
	while (buff[i_b])
	{
		joined[i_l++] = buff[i_b++];
		if (buff[i_b - 1] == '\n')
			break ;
	}
	joined[i_l] = '\0';
	return (joined);
}
