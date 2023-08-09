/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_hundred.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: osarsari <osarsari@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/07 12:24:45 by osarsari          #+#    #+#             */
/*   Updated: 2023/08/07 15:34:05 by osarsari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int	ft_pivot(t_stack *stack)
{
	int	j;
	int	pivot;

	if (stack->size == 4)
		j = 0;
	else if (stack->size == 5)
		j = 1;
	else if (stack->size == 6)
		j = 2;
	else if (stack->size < 66)
		j = stack->size / 2;
	else if (stack->size < 101)
		j = stack->size / 3;
	else
		j = stack->size / 4;
	pivot = ft_min_value(stack);
	while (j--)
		pivot = ft_bigger_value(stack, pivot);
	return (pivot);
}

int	estimated_cost(t_stack *a, t_stack *b, int n)
{
	int	to_top;
	int	ra;
	int	rb;
	int	rra;
	int	rrb;

	to_top = get_smallest_bigger(a, n);
	ra = cost_rotate(a, to_top);
	rb = cost_rotate(b, n);
	rra = cost_reverse_rotate(a, to_top);
	rrb = cost_reverse_rotate(b, n);
	return (cost_logic(ra, rb, rra, rrb));
}

int	lowest_cost_pa(t_stack *a, t_stack *b)
{
	int	r;
	int	rr;

	r = lowest_rotate_cost_pa(a, b);
	rr = lowest_reverse_rotate_cost_pa(a, b);
	if (r == rr || (estimated_cost(a, b, rr)
			>= estimated_cost(a, b, r)))
		return (r);
	return (rr);
}

void	ft_best_pa(t_stack *a, t_stack *b, int to_push)
{
	int	ra;
	int	rb;
	int	rra;
	int	rrb;
	int	to_top;

	to_top = get_smallest_bigger(a, to_push);
	ra = cost_rotate(a, to_top);
	rb = cost_rotate(b, to_push);
	rra = cost_reverse_rotate(a, to_top);
	rrb = cost_reverse_rotate(b, to_push);
	if (can_rr(ra, rb, rra, rrb))
		return (exec_rr_pa(a, b, ra, rb));
	if (can_rrr(ra, rb, rra, rrb))
		return (exec_rrr_pa(a, b, rra, rrb));
	if (ra > rra)
		ft_rra_n(a, rra);
	else
		ft_ra_n(a, ra);
	if (rb > rrb)
		ft_rrb_n(b, rrb);
	else
		ft_rb_n(b, rb);
	ft_pa(a, b);
}

void	ft_sort_hundred(t_stack *a, t_stack *b)
{
	int	pivot;

	while (a->size > 3)
	{
		pivot = ft_pivot(a);
		while (ft_min_value(a) <= pivot)
		{
			if (a->stack[a->size - 1] <= pivot)
				ft_pb(a, b);
			else
				ft_ra(a);
		}
	}
	ft_sort_three(a);
	while (b->size)
		ft_best_pa(a, b, lowest_cost_pa(a, b));
	ft_best_rotate(a);
}
