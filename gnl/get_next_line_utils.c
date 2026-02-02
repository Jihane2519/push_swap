/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbounou <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/25 23:08:25 by jbounou           #+#    #+#             */
/*   Updated: 2025/12/26 13:00:43 by jbounou          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_strlen(const char *s)
{
	size_t	i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}

char	*ft_strdup(const char *copy)
{
	char	*dup;
	int		i;

	if (!copy)
		return (NULL);
	dup = (char *)malloc((ft_strlen(copy) + 1) * sizeof(char));
	if (!dup)
		return (NULL);
	i = 0;
	while (copy[i])
	{
		dup[i] = copy[i];
		i++;
	}
	dup[i] = '\0';
	return (dup);
}

char	*ft_strjoin(char *s, char *s1)
{
	int		i;
	char	*new;
	int		j;

	if (!s && !s1)
		return (NULL);
	if (!s)
		return (ft_strdup(s1));
	if (!s1)
		return (ft_strdup(s));
	new = (char *)malloc((ft_strlen(s) + ft_strlen(s1) + 1) * sizeof(char));
	if (!new)
		return (NULL);
	i = 0;
	while (s && s[i])
	{
		new[i] = s[i];
		i++;
	}
	j = 0;
	while (s1[j])
		new[i++] = s1[j++];
	new[i] = '\0';
	free(s);
	return (new);
}

char	*get_line(char *s)
{
	char	*content;
	int		i;

	if (!s)
		return (NULL);
	i = 0;
	while (s[i] && s[i] != '\n')
		i++;
	content = malloc((i + 2) * sizeof(char));
	if (!content)
		return (NULL);
	i = 0;
	while (s[i] && s[i] != '\n')
	{
		content[i] = s[i];
		i++;
	}
	if (s[i] == '\n')
		content[i++] = '\n';
	content[i] = '\0';
	return (content);
}

char	*free_s(char *box)
{
	char	*new;
	int		i;
	int		j;

	i = 0;
	while (box[i] && box[i] != '\n')
		i++;
	if (!box[i] || (box[i] == '\n' && box[i + 1] == '\0'))
	{
		free(box);
		return (NULL);
	}
	if (box[i] == '\n')
		i++;
	new = (char *)malloc(ft_strlen(box) - i + 1);
	if (!new)
		return (NULL);
	j = 0;
	while (box[i])
		new[j++] = box[i++];
	new[j] = '\0';
	free(box);
	return (new);
}
