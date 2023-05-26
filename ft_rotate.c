/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rotate.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: osarsari <osarsari@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/06 18:29:57 by osarsari          #+#    #+#             */
/*   Updated: 2023/05/26 11:31:14 by osarsari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "push_swap.h"

/*
** Rotate the stack, i.e., move the top element to the bottom.
**
** stack: The stack to rotate.
**
** Returns:
** true if the rotation was successful, false otherwise.
*/

t_bool	ft_rotate(t_stack *stack)
{
	t_plate	*current;
	t_plate	*next;

	if (!stack || stack->size < 2)
		return (false);
	current = stack->top;
	next = stack->top->next;
	while (next)
	{
		current->value ^= next->value;
		next->value ^= current->value;
		current->value ^= next->value;
		current->position ^= next->position;
		next->position ^= current->position;
		current->position ^= next->position;
		current->sorted_position ^= next->sorted_position;
		next->sorted_position ^= current->sorted_position;
		current->sorted_position ^= next->sorted_position;
		current = next;
		next = next->next;
	}
	return (true);
}

void	run_rotate(t_stack *stack, char name)
{
	if (ft_rotate(stack))
		ft_printf("r%c\n", name);
}
