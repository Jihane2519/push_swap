/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_size.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbounou <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/28 18:03:08 by jbounou           #+#    #+#             */
/*   Updated: 2026/01/28 18:03:11 by jbounou          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int	stack_size(t_stack *a)
{
	int		count;
	t_stack	*tmp;

	count = 0;
	tmp = a;
	while (tmp)
	{
		count++;
		tmp = tmp->next;
	}
	return (count);
}
