/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_reverse_rotate.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: osarsari <osarsari@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/06 18:29:27 by osarsari          #+#    #+#             */
/*   Updated: 2023/05/18 15:54:32 by osarsari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*
** Rotate down all plates of a stack by one, so the bottom element becomes
** the top element.
**
** stack: The stack to reverse rotate.
**
** Returns:
** true if the reverse rotation was successful, false otherwise.
*/

t_bool	ft_reverse_rotate(t_stack *stack)
{
	t_plate	*current;
	t_plate	*prev;

	if (!stack || stack->size < 2)
		return (false);
	current = stack->bottom;
	prev = current->prev;
	while (prev)
	{
		current->value ^= prev->value;
		prev->value ^= current->value;
		current->value ^= prev->value;
		current->position ^= prev->position;
		prev->position ^= current->position;
		current->position ^= prev->position;
		current->sorted_position ^= prev->sorted_position;
		prev->sorted_position ^= current->sorted_position;
		current->sorted_position ^= prev->sorted_position;
		current = prev;
		prev = prev->prev;
	}
	return (true);
}

void	run_reverse_rotate(t_stack *stack, char name)
{
	if (ft_reverse_rotate(stack))
		ft_printf("rr%c\n", name);
}

void	repeat_reverse_rotate(t_stack *stack, int nb, char name)
{
	if (!stack)
		return ;
	while (nb-- > 0)
		run_reverse_rotate(stack, name);
}
