/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_reverse_rotate.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: osarsari <osarsari@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/06 18:29:27 by osarsari          #+#    #+#             */
/*   Updated: 2023/05/09 12:34:22 by osarsari         ###   ########.fr       */
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

	if (stack->size < 2)
		return (false);
	current = stack->bottom;
	prev = current->prev;
	while (prev)
	{
		current->value ^= prev->value;
		prev->value ^= current->value;
		current->value ^= prev->value;
		current = prev;
		prev = prev->prev;
	}
	return (true);
}
