/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.h                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llethuil <llethuil@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/02 15:42:40 by llethuil          #+#    #+#             */
/*   Updated: 2021/12/02 15:55:27 by llethuil         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_BONUS_H
# define GET_NEXT_LINE_BONUS_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 1024
# endif

/* ************************************************************************** */
/*                                                                            */
/*                                  INCLUDES                                  */
/*                                                                            */
/* ************************************************************************** */

# include <fcntl.h>
# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include <limits.h>

/* ************************************************************************** */
/*                                                                            */
/*                                  PROTOTYPES                                */
/*                                                                            */
/* ************************************************************************** */

/* get_next_line_bonus.c */
char	*get_next_line(int fd);
char	*ft_get_line(char *line, char *buff, int fd);
void	*ft_save_rest(char *buff, char *shifted_buff);

/* get_next_line_utils_bonus.c */
int		ft_strlen(char *str);
int		ft_position_nl(char *str);
char	*ft_strjoin(char *line, char *buff);
int		ft_len_malloc(char *line, char *buff);
char	*ft_fill_joined(char *line, char *buff, char *joined);

#endif
