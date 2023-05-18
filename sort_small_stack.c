/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_small_stack.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: osarsari <osarsari@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/16 11:25:24 by osarsari          #+#    #+#             */
/*   Updated: 2023/05/18 17:13:02 by osarsari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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
		ft_sa(stack);
}

/*
** Sorts a stack of size 3 with the least amount of operations and prints them.
**
** stack: The stack to sort.
*/

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
		ft_ra(stack, 1);
	if ((stack->top->value < stack->bottom->value
			&& stack->bottom->value < stack->top->next->value)
		|| (stack->top->value > stack->bottom->value
			&& stack->top->value < stack->top->next->value))
		ft_rra(stack, 1);
	if (stack->top->value > stack->top->next->value
		&& stack->top->value < stack->bottom->value)
		return (sort_two(stack));
}

/*
** Sorts a stack of size 5 with the least amount of operations and prints them.
**
** stack_a: The stack to sort.
** stack_b: An empty stack that can hold some plates to help in the
** sorting process.
*/

void	sort_five(t_stack *stack_a, t_stack *stack_b)
{
	t_plate	*smallest;
	t_plate	*second_smallest;

	if (!stack_a || !stack_b)
		return (ft_putstr_fd("Error\n", 1));
	smallest = get_smallest_plate(stack_a);
	run_cheapest_push(stack_a, stack_b, smallest);
	if (stack_a->size > 3)
		second_smallest = get_smallest_plate(stack_a);
	if (stack_a->size > 3)
		run_cheapest_push(stack_a, stack_b, second_smallest);
	sort_three(stack_a);
	ft_pa(stack_a, stack_b);
	return (ft_pa(stack_a, stack_b));
}

void	sort_small_stack(t_stack *stack_a, t_stack *stack_b)
{
	if (!stack_a || !stack_b)
		return (ft_putstr_fd("Error\n", 1));
	if (stack_a->size < 2)
		return ;
	if (stack_a->size < 4)
		return (sort_three(stack_a));
	return (sort_five(stack_a, stack_b));
}
