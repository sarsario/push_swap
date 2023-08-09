/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_push.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: osarsari <osarsari@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/02 09:21:48 by osarsari          #+#    #+#             */
/*   Updated: 2023/08/02 10:09:51 by osarsari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int	ft_push(t_stack *stack, int value)
{
	if (!stack || !stack->stack)
		return (0);
	stack->stack[stack->size] = value;
	stack->size++;
	return (1);
}

int	ft_push_stack(t_stack *src, t_stack *dst)
{
	if (!src || !dst || !src->stack || !dst->stack || !src->size)
		return (0);
	ft_push(dst, src->stack[src->size - 1]);
	src->size--;
	return (1);
}

void	ft_pa(t_stack *a, t_stack *b)
{
	if (ft_push_stack(b, a))
		ft_printf("pa\n");
}

void	ft_pb(t_stack *a, t_stack *b)
{
	if (ft_push_stack(a, b))
		ft_printf("pb\n");
}
