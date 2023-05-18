/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   selection_sort.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: osarsari <osarsari@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/15 18:55:12 by osarsari          #+#    #+#             */
/*   Updated: 2023/05/17 10:57:05 by osarsari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	push_phase(t_stack *stack_a, t_stack *stack_b,
	t_plate *smallest, t_plate *biggest)
{
	if (!stack_a || !stack_b || !smallest || !biggest)
		return ;
	while (stack_a->size > 3 && stack_b->size < stack_a->size)
	{
		// stack_a->top < next < stack_a->bottom
		if (stack_a->top->value < stack_a->top->next->value
			&& stack_a->top->next->value < stack_a->bottom->value)
		{
			// top smaller than midpoint? Yes = push to b
			if (stack_a->top->value < ((smallest->value + biggest->value) / 2))
				run_push_stack(stack_a, stack_b, 'b');
			// No = leave a near top
			else
				run_swap(stack_a, 'a');
		}
		// p1 second smallest
		else if (stack_a->top->value < stack_a->bottom->value)
		{
			// p1 < midpoint ? push p2 first because p2 < p1
			if (stack_a->top->value < ((smallest->value + biggest->value) / 2))
			{
				run_swap(stack_a, 'a');
				run_push_stack(stack_a, stack_b, 'b');
			}
			else
				run_rotate(stack_a, 'a');
		}
		// p1 biggest. If p1 < midpoint, send p1 last.
		else if ()
	}
}

void	selection_sort(t_stack *stack_a, t_stack *stack_b)
{
	t_plate	*smallest;
	t_plate	*biggest;

	if (!stack_a || !stack_b)
		return (ft_putstr_fd("Error\n", 1));
	smallest = get_smallest_plate(stack_a);
	biggest = get_biggest_plate(stack_a);
	push_phase(stack_a, stack_b, smallest, biggest);
}
