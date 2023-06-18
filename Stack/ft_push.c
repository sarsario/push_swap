/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_push.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: osarsari <osarsari@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/18 15:33:17 by osarsari          #+#    #+#             */
/*   Updated: 2023/06/18 15:43:43 by osarsari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

t_bool	ft_push(t_stack *stack, int value)
{
	if (!stack)
		return (false);
	stack->numbers[stack->size] = value;
	stack->size++;
	return (true);
}

t_bool	ft_push_stack(t_stack *dst, t_stack *src)
{
	if (!src || !dst || src->size < 1)
		return (false);
	dst->numbers[dst->size] = src->numbers[src->size - 1];
	dst->size++;
	src->size--;
	return (true);
}

void	ft_pa(t_stack *stack_a, t_stack *stack_b)
{
	if (ft_push_stack(stack_a, stack_b))
		ft_printf("pa\n");
}

void	ft_pb(t_stack *stack_a, t_stack *stack_b)
{
	if (ft_push_stack(stack_b, stack_a))
		ft_printf("pb\n");
}
