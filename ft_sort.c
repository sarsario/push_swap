/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: osarsari <osarsari@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/08 11:47:23 by osarsari          #+#    #+#             */
/*   Updated: 2023/05/11 11:19:52 by osarsari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*
** Checks whether the plates in the given stack are sorted in ascending order.
**
** stack: The stack to check.
**
** Returns:
** true if the plates are sorted, false otherwise.
*/

t_bool	stack_is_asc(t_stack *stack)
{
	t_plate	*current;

	if (!stack)
		return (false);
	if (stack->size < 2)
		return (true);
	current = stack->top->next;
	while (current)
	{
		if (current->prev->value > current->value)
			return (false);
		current = current->next;
	}
	return (true);
}

/*
** Checks whether the plates in the given stack are sorted in descending order.
**
** stack: The stack to check.
**
** Returns:
** true if the plates are sorted, false otherwise.
*/

t_bool	stack_is_dsc(t_stack *stack)
{
	t_plate	*current;

	if (!stack)
		return (false);
	if (stack->size < 2)
		return (true);
	current = stack->top->next;
	while (current)
	{
		if (current->prev->value < current->value)
			return (false);
		current = current->next;
	}
	return (true);
}

void	ft_sort(t_stack *stack_a, t_stack *stack_b)
{
	if (!stack_a || !stack_b)
		return ft_putstr_fd("Error\n", 1);
	if(stack_b->size == 0 && stack_is_asc(stack_a))
		return ft_putstr_fd("Sorted\n", 1);

	return ;
}
