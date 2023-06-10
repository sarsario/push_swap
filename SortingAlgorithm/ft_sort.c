/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: osarsari <osarsari@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/25 14:57:27 by osarsari          #+#    #+#             */
/*   Updated: 2023/06/10 09:59:37 by osarsari         ###   ########.fr       */
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
	if (stack_is_asc(stack_a))
	{
		put_plate_top(stack_a, stack_b, get_biggest_plate(stack_b), 1);
		ft_pa(stack_a, stack_b);
	}
	if (!stack_is_asc(stack_a) && stack_a->size > 3)
		lower_half_pb(stack_a, stack_b);
	if (!stack_is_asc(stack_a) && stack_a->size < 4)
		sort_three(stack_a, stack_b);
	return (quick_sort(stack_a, stack_b));
}

void	cost_sort(t_stack *stack_a, t_stack *stack_b)
{
	t_plate	*to_pb;
	t_plate	*staying;
	int		staying_value;

	to_pb = stack_a->top;
	staying = get_biggest_plate(stack_a);
	staying = get_smaller_plate(stack_a, staying);
	staying = get_smaller_plate(stack_a, staying);
	staying_value = staying->value;
	while (stack_a->size > 3)
	{
		to_pb = best_plate_pb(stack_a, stack_b, staying_value);
		align_stacks(stack_a, stack_b, to_pb);
		ft_pb(stack_a, stack_b);
	}
	sort_three(stack_a, stack_b);
	while (stack_b->size > 0)
	{
		put_plate_top(stack_a, stack_b, get_biggest_plate(stack_b), 1);
		ft_pa(stack_a, stack_b);
	}
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
		// cost_sort(stack_a, stack_b);
	free_stack(stack_a);
	free_stack(stack_b);
}
