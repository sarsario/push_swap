/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cost2.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: osarsari <osarsari@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/19 13:44:55 by osarsari          #+#    #+#             */
/*   Updated: 2023/06/19 13:46:29 by osarsari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int	cost_rotate(t_stack *stack, int n)
{
	int	res;
	int	i;

	res = 0;
	i = stack->size - 1;
	while (stack->numbers[i] != n)
	{
		i--;
		res++;
	}
	return (res);
}

int	cost_reverse_rotate(t_stack *stack, int n)
{
	int	res;

	res = 0;
	while (res < stack->size && stack->numbers[res] != n)
		res++;
	return (res + 1);
}

int	cost_logic(int ra, int rb, int rra, int rrb)
{
	int	rr;
	int	rrr;
	int	rab;

	rr = ft_max(ra, rb);
	rrr = ft_max(rra, rrb);
	rab = ft_min(ra, rra) + ft_min(rb, rrb);
	return (ft_min(ft_min(rr, rrr), rab));
}

int	estimated_cost(t_stack *stack_a, t_stack *stack_b, int n)
{
	int	to_top;
	int	ra;
	int	rb;
	int	rra;
	int	rrb;

	to_top = get_smallest_bigger(stack_a, n);
	ra = cost_rotate(stack_a, to_top);
	rb = cost_rotate(stack_b, n);
	rra = cost_reverse_rotate(stack_a, to_top);
	rrb = cost_reverse_rotate(stack_b, n);
	return (cost_logic(ra, rb, rra, rrb));
}
