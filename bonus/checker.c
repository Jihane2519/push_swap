/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbounou <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/29 18:11:28 by jbounou           #+#    #+#             */
/*   Updated: 2026/01/30 00:10:21 by jbounou          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"
#include "../gnl/get_next_line.h"

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

int	main(int argc, char **argv)
{
	t_stack		*a;
	t_stack		*b;
	char		*line;

	a = NULL;
	b = NULL;
	if (argc < 2)
		return (0);
	parse_args(argc, argv, &a);
	line = get_next_line(0);
	while (line)
	{
		apply_instruction(line, &a, &b);
		free(line);
		line = get_next_line(0);
	}
	if (is_sorted(a) && b == NULL)
		write(1, "OK\n", 3);
	else
		write (1, "KO\n", 3);
	free_stack(&a);
	free_stack(&b);
	free (line);
	return (0);
}
