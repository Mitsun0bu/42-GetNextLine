/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llethuil <llethuil@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/02 15:42:24 by llethuil          #+#    #+#             */
/*   Updated: 2021/12/02 15:55:02 by llethuil         ###   ########lyon.fr   */
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

	if (!line || !buff)
		return (NULL);
	joined = malloc(sizeof(char) * (ft_len_malloc(line, buff) + 1));
	if (!joined)
		return (NULL);
	joined = ft_fill_joined(line, buff, joined);
	return (joined);
}

int	ft_len_malloc(char *line, char *buff)
{
	int		i_l;
	int		i_b;
	int		len;

	i_l = 0;
	while (line && line[i_l])
		i_l++;
	i_b = 0;
	while (buff && buff[i_b])
	{
		i_b++;
		if (buff[i_b] == '\n')
		{
			i_b++;
			break ;
		}
	}
	len = i_l + i_b;
	return (len);
}

char	*ft_fill_joined(char *line, char *buff, char *joined)
{
	int		j;
	int		i_l;
	int		i_b;

	i_l = 0;
	j = 0;
	while (line && line[i_l])
			joined[j++] = line[i_l++];
	if (line)
		free(line);
	i_b = 0;
	while (buff && buff[i_b])
	{
		joined[j] = buff[i_b];
		if (buff[i_b] == '\n')
		{
			joined[j++] = '\n';
			break ;
		}
		j++;
		i_b++;
	}
	joined[j] = '\0';
	return (joined);
}
