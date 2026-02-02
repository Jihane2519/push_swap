/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbounou <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/29 15:39:39 by jbounou           #+#    #+#             */
/*   Updated: 2026/01/29 15:51:08 by jbounou          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	free_stack(t_stack **a)
{
	t_stack	*tmp;

	while (*a)
	{
		tmp = (*a)->next;
		free(*a);
		*a = tmp;
	}
}

/*int	main(int argc, char **argv)
{
	t_stack	*a;
	t_stack	*tmp;
	t_stack	*a;
	t_stack	*b;

	a = NULL;
	if (argc == 1)
		return (0);
	(void)argv;
	parse_args(argc, argv, &a);
	tmp = a;
	while (tmp)
	{
		printf("%d\n", tmp->value);
		tmp = tmp->next;
	}
	free_stack(&a);
	return (0);
}*/
int	main(int argc, char **argv)
{
	t_stack	*a;
	t_stack	*b;

	a = NULL;
	b = NULL;
	if (argc < 2)
		return (0);
	parse_args(argc, argv, &a);
	if (is_sorted(a))
		return (free_stack(&a), free_stack(&b), 0);
	if (stack_size(a) == 2)
		sa(&a, 1);
	if (stack_size(a) == 3)
		sort_three(&a);
	else if (stack_size(a) <= 5)
		sort_five(&a, &b);
	else
	{
		sort_chunks(&a, &b);
	}
	free_stack(&a);
	free_stack(&b);
	return (0);
}
