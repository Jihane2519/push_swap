/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_rotate.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbounou <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/27 19:30:22 by jbounou           #+#    #+#             */
/*   Updated: 2026/01/28 18:22:20 by jbounou          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

static void	helper_rrr(t_stack **s)
{
	t_stack	*tmp;
	t_stack	*prev;

	tmp = *s;
	prev = NULL;
	while (tmp->next)
	{
		prev = tmp;
		tmp = tmp->next;
	}
	prev->next = NULL;
	tmp->next = *s;
	*s = tmp;
}

void	rra(t_stack **a, int print)
{
	if (!a || !*a || !(*a)->next)
		return ;
	helper_rrr(a);
	if (print)
		write(1, "rra\n", 4);
}

void	rrb(t_stack **b, int print)
{
	if (!b || !*b || !(*b)->next)
		return ;
	helper_rrr(b);
	if (print)
		write(1, "rrb\n", 4);
}

void	rrr(t_stack **a, t_stack **b, int print)
{
	if (a && *a && (*a)->next)
		helper_rrr(a);
	if (b && *b && (*b)->next)
		helper_rrr(b);
	if (print)
		write(1, "rrr\n", 4);
}
