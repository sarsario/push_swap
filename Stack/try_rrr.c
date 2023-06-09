/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   try_rrr.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: osarsari <osarsari@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/25 17:32:26 by osarsari          #+#    #+#             */
/*   Updated: 2023/06/09 23:39:14 by osarsari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	try_rrr_before_rra(t_stack *stack_a, t_stack *stack_b, int nb)
{
	if (!stack_a || !stack_b)
		return ;
	while (nb-- > 0)
	{
		if (stack_b->size > 1
			&& stack_b->bot->value > stack_b->top->value)
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
			&& stack_a->bot->value < stack_a->top->value)
			ft_rrr(stack_a, stack_b, 1);
		else
			ft_rrb(stack_b, 1);
	}
}
