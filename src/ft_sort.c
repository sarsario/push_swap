/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: osarsari <osarsari@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/02 10:20:05 by osarsari          #+#    #+#             */
/*   Updated: 2023/08/07 11:48:21 by osarsari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int	ft_is_sorted(t_stack *stack)
{
	int	i;

	if (!stack || !stack->stack || stack->size < 1)
		return (0);
	i = stack->size;
	while (--i > 0)
		if (stack->stack[i] > stack->stack[i - 1])
			return (0);
	return (1);
}

void	ft_sort_three(t_stack *stack)
{
	if (stack->stack[2] > stack->stack[1] && stack->stack[2] > stack->stack[0])
		ft_ra(stack);
	if (stack->stack[0] < stack->stack[1] || stack->stack[0] < stack->stack[2])
		ft_rra(stack);
	if (stack->stack[2] > stack->stack[1])
		ft_sa(stack);
}

int	ft_pivot_six(t_stack *stack)
{
	int	pivot;

	pivot = ft_max_value(stack);
	pivot = ft_smaller_value(stack, pivot);
	pivot = ft_smaller_value(stack, pivot);
	return (pivot);
}

void	ft_sort_six(t_stack *a, t_stack *b)
{
	int	pivot;

	pivot = ft_pivot_six(a);
	while ((!ft_is_sorted(a) && a->size > 3)
		|| (ft_is_sorted(a) && b->size && ft_min_value(a) < ft_max_value(b)))
		ft_pb_pivot(a, b, pivot);
	combined_r(a, b);
	combined_rr(a, b);
	combined_s(a, b);
	while (b->size)
		ft_pa(a, b);
}

int	ft_sort(t_stack *a, t_stack *b)
{
	if (!a || !b || !a->stack || !b->stack)
		return (0);
	if (ft_is_sorted(a) && !b->size)
		return (1);
	if (a->size == 2)
		ft_sa(a);
	else if (a->size == 3)
		ft_sort_three(a);
	else if (a->size <= 6)
		ft_sort_six(a, b);
	else
		ft_sort_hundred(a, b);
	return (1);
}
