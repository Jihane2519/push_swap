/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbounou <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/25 23:06:48 by jbounou           #+#    #+#             */
/*   Updated: 2025/12/25 23:07:04 by jbounou          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include "../push_swap.h"

char	*ft_strchr(const char *s, int c);
char	*ft_strjoin(char *s, char *s1);
char	*ft_strdup(const char *copy);
size_t	ft_strlen(const char *s);
char	*get_line(char *s);
char	*free_s(char *box);
char	*get_s(int fd, char *s);
char	*get_next_line(int fd);

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 42
# endif

#endif