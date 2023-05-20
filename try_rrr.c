/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   try_rrr.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: osarsari <osarsari@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/20 19:58:43 by osarsari          #+#    #+#             */
/*   Updated: 2023/05/20 19:59:09 by osarsari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	try_rrr_before_rra(t_stack *stack_a, t_stack *stack_b, int nb)
{
	if (!stack_a || !stack_b)
		return ;
	while (nb-- > 0)
	{
		if (stack_b->size > 1
			&& stack_b->bottom->value > stack_b->top->value)
			ft_rrr(stack_a, stack_b, 1);
		else
			ft_rra(stack_a, 1);
	}
}

void	try_rrr_before_rrb(t_stack *stack_a, t_stack *stack_b, int nb)
{
	if (!stack_a || !stack_b)
		return ;
	while (nb-- > 0)
	{
		if (stack_a->size > 1
			&& stack_a->bottom->value < stack_a->top->value)
			ft_rrr(stack_a, stack_b, 1);
		else
			ft_rrb(stack_b, 1);
	}
}
