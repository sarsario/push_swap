/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_min_max.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: osarsari <osarsari@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/07 15:20:39 by osarsari          #+#    #+#             */
/*   Updated: 2023/08/07 16:08:05 by osarsari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int	ft_min(int a, int b)
{
	if (a <= b)
		return (a);
	return (b);
}

int	ft_max(int a, int b)
{
	if (a >= b)
		return (a);
	return (b);
}

int	ft_min_value(t_stack *stack)
{
	int	i;
	int	min;

	i = -1;
	min = INT_MAX;
	while (++i < stack->size)
		if (stack->stack[i] < min)
			min = stack->stack[i];
	return (min);
}

int	ft_max_value(t_stack *stack)
{
	int	i;
	int	max;

	i = -1;
	max = INT_MIN;
	while (++i < stack->size)
		if (stack->stack[i] > max)
			max = stack->stack[i];
	return (max);
}
