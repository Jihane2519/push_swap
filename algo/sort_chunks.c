/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_chunks.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbounou <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/27 21:12:39 by jbounou           #+#    #+#             */
/*   Updated: 2026/01/28 21:40:26 by jbounou          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

static int	find_max_pos(t_stack *b)
{
	t_stack	*tmp;
	int		max;
	int		i;
	int		max_pos;

	if (!b)
		return (0);
	tmp = b;
	max = b->value;
	i = 0;
	max_pos = 0;
	while (tmp)
	{
		if (tmp->value > max)
		{
			max = tmp->value;
			max_pos = i;
		}
		tmp = tmp->next;
		i++;
	}
	return (max_pos);
}

static void	push_back_biggest(t_stack **a, t_stack **b)
{
	int		size;
	int		biggest;

	size = stack_size(*b);
	while (size > 0)
	{
		biggest = find_max_pos(*b);
		if (biggest <= size / 2)
		{
			while (biggest-- > 0)
				rb(b, 1);
		}
		else
		{
			while (biggest++ < size)
				rrb(b, 1);
		}
		pa(a, b, 1);
		size--;
	}
}

static void	push_to_chunk(t_stack **a, t_stack **b, t_chunks *c)
{
	while (c->size > 0)
	{
		if ((*a)->value <= c->tab[c->start])
		{
			pb(a, b, 1);
			rb(b, 1);
			c->start++;
			c->end++;
			c->size--;
		}
		else if ((*a)->value <= c->tab[c->end])
		{
			pb(a, b, 1);
			if ((*b)->next && (*b)->value < (*b)->next->value)
				sb(b, 1);
			c->start++;
			c->end++;
			c->size--;
		}
		else
			ra(a, 1);
	}
}

void	sort_chunks(t_stack **a, t_stack **b)
{
	t_chunks	c;

	c.size = stack_size(*a);
	c.tab = stack_to_array(*a);
	if (!(c.tab))
		return ;
	sort_array(c.tab, c.size);
	c.start = 0;
	if (c.size <= 100)
		c.end = c.size / 6;
	else
		c.end = c.size / 14;
	push_to_chunk(a, b, &c);
	push_back_biggest(a, b);
	free(c.tab);
}
