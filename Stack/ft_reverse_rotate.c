/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_reverse_rotate.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: osarsari <osarsari@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/25 17:42:55 by osarsari          #+#    #+#             */
/*   Updated: 2023/05/25 18:10:14 by osarsari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

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
	current = stack->bot;
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

void	ft_rra(t_stack *stack_a, int nb)
{
	while (nb-- > 0)
	{
		if (ft_reverse_rotate(stack_a))
			ft_printf("rra\n");
	}
}

void	ft_rrb(t_stack *stack_b, int nb)
{
	while (nb-- > 0)
	{
		if (ft_reverse_rotate(stack_b))
			ft_printf("rrb\n");
	}
}

void	ft_rrr(t_stack *stack_a, t_stack *stack_b, int nb)
{
	while (nb-- > 0)
	{
		if (ft_reverse_rotate(stack_a) && ft_reverse_rotate(stack_b))
			ft_printf("rrr\n");
	}
}
