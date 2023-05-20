/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   try_rr.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: osarsari <osarsari@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/20 19:59:50 by osarsari          #+#    #+#             */
/*   Updated: 2023/05/20 20:00:11 by osarsari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	try_rr_before_ra(t_stack *stack_a, t_stack *stack_b, int nb)
{
	if (!stack_a || !stack_b)
		return ;
	while (nb-- > 0)
	{
		if (stack_b->size > 1
			&& stack_b->top->value < stack_b->bottom->value)
			ft_rr(stack_a, stack_b, 1);
		else
			ft_ra(stack_a, stack_b, 1);
	}
}

void	try_rr_before_rb(t_stack *stack_a, t_stack *stack_b, int nb)
{
	if (!stack_a || !stack_b)
		return ;
	while (nb-- > 0)
	{
		if (stack_a->top->value > stack_a->bottom->value)
			ft_rr(stack_a, stack_b, 1);
		else
			ft_rb(stack_b, 1);
	}
}
