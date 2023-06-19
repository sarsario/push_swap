/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cost.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: osarsari <osarsari@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/19 12:41:04 by osarsari          #+#    #+#             */
/*   Updated: 2023/06/19 13:56:32 by osarsari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int	lowest_rotate_cost_pa(t_stack *stack_a, t_stack *stack_b)
{
	int	i;
	int	cost;
	int	min_cost;
	int	best_pa;
	int	range;

	i = stack_b->size;
	range = i;
	min_cost = INT_MAX;
	while (i-- && range--)
	{
		cost = estimated_cost(stack_a, stack_b, stack_b->numbers[i]);
		if (cost < min_cost)
		{
			min_cost = cost;
			best_pa = stack_b->numbers[i];
			if (range > min_cost)
				range = min_cost;
		}
	}
	return (best_pa);
}

int	lowest_reverse_rotate_cost_pa(t_stack *stack_a, t_stack *stack_b)
{
	int	i;
	int	cost;
	int	min_cost;
	int	best_pa;
	int	range;

	i = -1;
	range = INT_MAX;
	min_cost = INT_MAX;
	while (++i < stack_b->size && range--)
	{
		cost = estimated_cost(stack_a, stack_b, stack_b->numbers[i]);
		if (cost < min_cost)
		{
			min_cost = cost;
			best_pa = stack_b->numbers[i];
			if (range > min_cost)
				range = min_cost;
		}
	}
	return (best_pa);
}

int	lowest_cost_pa(t_stack *stack_a, t_stack *stack_b)
{
	int	a;
	int	b;

	a = lowest_rotate_cost_pa(stack_a, stack_b);
	b = lowest_reverse_rotate_cost_pa(stack_a, stack_b);
	if (a == b || (estimated_cost(stack_a, stack_b, b)
			>= estimated_cost(stack_a, stack_b, a)))
		return (a);
	return (b);
}
