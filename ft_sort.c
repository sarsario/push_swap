/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: osarsari <osarsari@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/08 11:47:23 by osarsari          #+#    #+#             */
/*   Updated: 2023/05/15 20:04:15 by osarsari         ###   ########.fr       */
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

/*
** Sorts a stack of size 2 and prints the operation.
**
** stack: The stack to sort.
*/
void	sort_two(t_stack *stack)
{
	if (!stack)
		return (ft_putstr_fd("Error\n", 1));
	if (stack->size < 2)
		return ;
	if (stack->top->value > stack->top->next->value)
	{
		if (ft_swap(stack))
			return (ft_putstr_fd("sa\n", 1));
		else
			return (ft_putstr_fd("Error\n", 1));
	}
}

void	sort_three(t_stack *stack)
{
	if (!stack)
		return (ft_putstr_fd("Error\n", 1));
	if (stack->size < 2 || stack_is_asc(stack))
		return ;
	if (stack->size == 2)
		return (sort_two(stack));
	if (stack_is_dsc(stack)
		|| (stack->top->value > stack->bottom->value
			&& stack->bottom->value > stack->top->next->value))
	{
		if (ft_rotate(stack))
			ft_putstr_fd("ra\n", 1);
	}
	if ((stack->top->value < stack->bottom->value
			&& stack->bottom->value < stack->top->next->value)
		|| (stack->top->value > stack->bottom->value
			&& stack->top->value < stack->top->next->value))
	{
		if (ft_reverse_rotate(stack))
			ft_putstr_fd("rra\n", 1);
	}
	if (stack->top->value > stack->top->next->value
		&& stack->top->value < stack->bottom->value)
		return (sort_two(stack));
}

void	ft_sort(t_stack *stack_a, t_stack *stack_b)
{
	if (!stack_a || !stack_b)
		return (ft_putstr_fd("Error\n", 1));
	if (stack_b->size == 0 && stack_is_asc(stack_a))
		return ;
	if (stack_a->size < 4)
		return (sort_three(stack_a));
	return (selection_sort(stack_a, stack_b));
}
