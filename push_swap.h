/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbounou <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/28 21:11:28 by jbounou           #+#    #+#             */
/*   Updated: 2026/01/28 21:24:34 by jbounou          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdlib.h>
# include <unistd.h>
# include <limits.h>
# include <stdio.h>

typedef struct s_stack
{
	int				value;
	struct s_stack	*next;
}	t_stack;

typedef struct s_chunks
{
	int		start;
	int		end;
	int		size;
	int		*tab;
}	t_chunks;

/* parsing */
void	parse_args(int argc, char **argv, t_stack **a);
void	error_exit(void);
void	free_stack(t_stack **a);

/* parsing utils */
long	ft_atol(char *str);
int		is_valid_number(char *str);
void	stack_add_back(t_stack **a, int nb);
int		has_duplicate(t_stack *a, int nb);
void	free_split(char **tab);

/* parsing other utils */
char	**ft_split(char const *s, char c);
char	*fstrjoin(char *s1, char *s2);
size_t	fstrlen(const char *s);
char	*fstrdup(const char *str);

/* algo */
void	sort_three(t_stack **a);
int		is_sorted(t_stack *a);
void	sort_five(t_stack **a, t_stack **b);
int		stack_size(t_stack *a);
void	sort_chunks(t_stack **a, t_stack **b);
int		*stack_to_array(t_stack *a);
void	sort_array(int *tab, int size);

/* operations */
/* swap */
void	sa(t_stack **a, int print);
void	sb(t_stack **b, int print);
void	ss(t_stack **a, t_stack **b, int print);

/* push */
void	pa(t_stack **a, t_stack **b, int print);
void	pb(t_stack **a, t_stack **b, int print);

/* rotate */
void	ra(t_stack **a, int print);
void	rb(t_stack **b, int print);
void	rr(t_stack **a, t_stack **b, int print);

/* reverse rotate */
void	rra(t_stack **a, int print);
void	rrb(t_stack **b, int print);
void	rrr(t_stack **a, t_stack **b, int print);

/* bonus*/
void	apply_instruction(char *line, t_stack **a, t_stack **b);
void	free_stack(t_stack **a);

#endif
