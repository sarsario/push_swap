/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cost.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: osarsari <osarsari@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/07 15:13:25 by osarsari          #+#    #+#             */
/*   Updated: 2023/08/07 15:29:33 by osarsari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int	cost_rotate(t_stack *stack, int n)
{
	int	res;
	int	i;

	res = 0;
	i = stack->size - 1;
	while (stack->stack[i] != n)
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
	while (res < stack->size && stack->stack[res] != n)
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

int	lowest_rotate_cost_pa(t_stack *a, t_stack *b)
{
	int	i;
	int	cost;
	int	min_cost;
	int	best_pa;
	int	range;

	i = b->size;
	range = i;
	min_cost = INT_MAX;
	while (i-- && range--)
	{
		cost = estimated_cost(a, b, b->stack[i]);
		if (cost < min_cost)
		{
			min_cost = cost;
			best_pa = b->stack[i];
			if (range > min_cost)
				range = min_cost;
		}
	}
	return (best_pa);
}

int	lowest_reverse_rotate_cost_pa(t_stack *a, t_stack *b)
{
	int	i;
	int	cost;
	int	min_cost;
	int	best_pa;
	int	range;

	i = -1;
	range = INT_MAX;
	min_cost = INT_MAX;
	while (++i < b->size && range--)
	{
		cost = estimated_cost(a, b, b->stack[i]);
		if (cost < min_cost)
		{
			min_cost = cost;
			best_pa = b->stack[i];
			if (range > min_cost)
				range = min_cost;
		}
	}
	return (best_pa);
}
