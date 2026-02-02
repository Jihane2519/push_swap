/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbounou <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/27 19:06:36 by jbounou           #+#    #+#             */
/*   Updated: 2026/01/27 19:45:59 by jbounou          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	ra(t_stack **a, int print)
{
	t_stack	*first;
	t_stack	*tmp;

	if (!a || !*a || !(*a)->next)
		return ;
	first = *a;
	*a = first->next;
	tmp = *a;
	while (tmp->next)
		tmp = tmp->next;
	tmp->next = first;
	first->next = NULL;
	if (print)
		write (1, "ra\n", 3);
}

void	rb(t_stack **b, int print)
{
	t_stack	*first;
	t_stack	*tmp;

	if (!b ||!*b || !(*b)->next)
		return ;
	first = *b;
	*b = first->next;
	tmp = *b;
	while (tmp->next)
		tmp = tmp->next;
	tmp->next = first;
	first->next = NULL;
	if (print)
		write(1, "rb\n", 3);
}

void	rr(t_stack **a, t_stack **b, int print)
{
	t_stack	*first;
	t_stack	*tmp;

	if (a && *a && (*a)->next)
	{
		first = *a;
		*a = first->next;
		tmp = *a;
		while (tmp->next)
			tmp = tmp->next;
		tmp->next = first;
		first->next = NULL;
	}
	if (!b && !*b && !(*b)->next)
	{
		first = *b;
		*b = first->next;
		tmp = *b;
		while (tmp->next)
			tmp = tmp->next;
		tmp->next = first;
		first->next = NULL;
	}
	if (print)
		write(1, "rr\n", 3);
}
