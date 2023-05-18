/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rotate.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: osarsari <osarsari@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/06 18:29:57 by osarsari          #+#    #+#             */
/*   Updated: 2023/05/18 16:45:14 by osarsari         ###   ########.fr       */
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

void	ft_ra(t_stack *stack_a, int nb)
{
	while (nb-- > 0)
	{
		if (ft_rotate(stack_a))
			ft_printf("ra\n");
	}
}

void	ft_rb(t_stack *stack_b, int nb)
{
	while (nb-- > 0)
	{
		if (ft_rotate(stack_b))
			ft_printf("rb\n");
	}
}

void	ft_rr(t_stack *stack_a, t_stack *stack_b, int nb)
{
	while (nb-- > 0)
	{
		if (ft_rotate(stack_a) && ft_rotate(stack_b))
			ft_printf("rr\n");
	}
}
