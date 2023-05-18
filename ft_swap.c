/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_swap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: osarsari <osarsari@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/06 18:30:13 by osarsari          #+#    #+#             */
/*   Updated: 2023/05/18 16:32:33 by osarsari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*
** Swap the two top plates of the stack.
**
** stack: The stack to swap the plates.
**
** Returns:
** true if the swap was successful, false otherwise.
*/

t_bool	ft_swap(t_stack *stack)
{
	if (!stack || stack->size < 2)
		return (false);
	stack->top->value ^= stack->top->next->value;
	stack->top->next->value ^= stack->top->value;
	stack->top->value ^= stack->top->next->value;
	stack->top->position ^= stack->top->next->position;
	stack->top->next->position ^= stack->top->position;
	stack->top->position ^= stack->top->next->position;
	stack->top->sorted_position ^= stack->top->next->sorted_position;
	stack->top->next->sorted_position ^= stack->top->sorted_position;
	stack->top->sorted_position ^= stack->top->next->sorted_position;
	return (true);
}

void	ft_sa(t_stack *stack_a)
{
	if (ft_swap(stack_a))
		ft_printf("sa\n");
}

void	ft_sb(t_stack *stack_b)
{
	if (ft_swap(stack_b))
		ft_printf("sb\n");
}

void	ft_ss(t_stack *stack_a, t_stack *stack_b)
{
	if (ft_swap(stack_a) && ft_swap(stack_b))
		ft_printf("ss\n");
}
