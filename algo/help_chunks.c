/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   help_chunks.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbounou <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/28 16:44:02 by jbounou           #+#    #+#             */
/*   Updated: 2026/01/28 20:35:06 by jbounou          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int	*stack_to_array(t_stack *a)
{
	t_stack	*tmp;
	int		*tab;
	int		size;
	int		i;

	size = stack_size(a);
	tab = malloc(sizeof(int) * size);
	if (!tab)
		return (NULL);
	i = 0;
	tmp = a;
	while (i < size)
	{
		tab[i] = tmp->value;
		tmp = tmp->next;
		i++;
	}
	return (tab);
}

void	sort_array(int *tab, int size)
{
	int	tmp;
	int	i;
	int	j;

	i = 0;
	while (i < size - 1)
	{
		j = i + 1;
		while (j < size)
		{
			if (tab[j] < tab[i])
			{
				tmp = tab[i];
				tab[i] = tab[j];
				tab[j] = tmp;
			}
			j++;
		}
		i++;
	}
}
