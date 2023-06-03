/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: osarsari <osarsari@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/25 14:57:27 by osarsari          #+#    #+#             */
/*   Updated: 2023/06/03 12:23:25 by osarsari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

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
		if (current->prev->sorted_position != current->sorted_position - 1)
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
		if (current->prev->sorted_position != current->sorted_position + 1)
			return (false);
		current = current->next;
	}
	return (true);
}

void	quick_sort(t_stack *stack_a, t_stack *stack_b)
{
	if (stack_is_asc(stack_a) && stack_b->size == 0)
		return ;
	if (stack_is_asc(stack_a) && !stack_is_dsc(stack_b))
		top_half_pa(stack_a, stack_b);
	else if (stack_is_asc(stack_a))
		ft_pa(stack_a, stack_b);
	if (!stack_is_asc(stack_a) && stack_a->size > 3)
		lower_half_pb(stack_a, stack_b);
	if (!stack_is_asc(stack_a) && stack_a->size < 4)
		sort_three(stack_a, stack_b);
	return (quick_sort(stack_a, stack_b));
}

void	ft_sort(t_stack *stack_a, t_stack *stack_b)
{
	if (!stack_a || !stack_b)
		return (ft_putstr_fd("Error\n", 1));
	if (stack_b->size == 0 && stack_is_asc(stack_a))
		return ;
	if (stack_a->size < 6)
		sort_small_stack(stack_a, stack_b);
	else
		quick_sort(stack_a, stack_b);
	while (ft_pop(stack_a, &(int){0}))
		;
	while (ft_pop(stack_b, &(int){0}))
		;
	free(stack_a);
	free(stack_b);
}
