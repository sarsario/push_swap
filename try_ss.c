/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   try_ss.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: osarsari <osarsari@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/20 20:00:43 by osarsari          #+#    #+#             */
/*   Updated: 2023/05/20 20:02:16 by osarsari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	try_ss_before_sa(t_stack *stack_a, t_stack *stack_b)
{
	if (!stack_a || !stack_b)
		return ;
	if (stack_b->size > 1
		&& stack_b->top->value < stack_b->top->next->value)
		ft_ss(stack_a, stack_b);
	else
		ft_sa(stack_a);
}

void	try_ss_before_sb(t_stack *stack_a, t_stack *stack_b)
{
	if (!stack_a || !stack_b)
		return ;
	if (stack_a->size > 1
		&& stack_a->top->value > stack_a->top->next->value)
		ft_ss(stack_a, stack_b);
	else
		ft_sb(stack_b);
}
