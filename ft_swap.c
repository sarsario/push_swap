/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_swap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: osarsari <osarsari@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/06 18:30:13 by osarsari          #+#    #+#             */
/*   Updated: 2023/05/18 15:50:45 by osarsari         ###   ########.fr       */
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

void	run_swap(t_stack *stack, char name)
{
	if (ft_swap(stack))
		ft_printf("s%c\n", name);
}
