/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_value.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: osarsari <osarsari@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/02 10:46:15 by osarsari          #+#    #+#             */
/*   Updated: 2023/08/07 16:07:45 by osarsari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int	ft_bigger_value(t_stack *stack, int value)
{
	int	i;
	int	bigger;

	i = -1;
	bigger = ft_max_value(stack);
	while (++i < stack->size)
		if (stack->stack[i] > value && stack->stack[i] < bigger)
			bigger = stack->stack[i];
	return (bigger);
}

int	ft_smaller_value(t_stack *stack, int value)
{
	int	i;
	int	smaller;

	i = -1;
	smaller = ft_min_value(stack);
	while (++i < stack->size)
		if (stack->stack[i] < value && stack->stack[i] > smaller)
			smaller = stack->stack[i];
	return (smaller);
}
