/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_small_stack.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: osarsari <osarsari@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/16 11:25:24 by osarsari          #+#    #+#             */
/*   Updated: 2023/05/23 15:13:56 by osarsari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*
** Sorts a stack of size 2 and prints the operation.
**
** stack: The stack to sort.
*/
void	sort_two(t_stack *stack_a, t_stack *stack_b)
{
	if (!stack_a || !stack_b)
		return (ft_putstr_fd("Error\n", 1));
	if (stack_a->size < 2)
		return ;
	if (stack_a->top->value > stack_a->top->next->value)
		try_ss_before_sa(stack_a, stack_b);
}

/*
** Sorts a stack of size 3 with the least amount of operations and prints them.
**
** stack: The stack to sort.
*/

void	sort_three(t_stack *stack_a, t_stack *stack_b)
{
	if (!stack_a || !stack_b)
		return (ft_putstr_fd("Error\n", 1));
	if (stack_a->size < 2 || stack_is_asc(stack_a))
		return ;
	if (stack_a->size == 2)
		return (sort_two(stack_a, stack_b));
	if (stack_is_dsc(stack_a)
		|| (stack_a->top->value > stack_a->bottom->value
			&& stack_a->bottom->value > stack_a->top->next->value))
		try_rr_before_ra(stack_a, stack_b, 1);
	if ((stack_a->top->value < stack_a->bottom->value
			&& stack_a->bottom->value < stack_a->top->next->value)
		|| (stack_a->top->value > stack_a->bottom->value
			&& stack_a->top->value < stack_a->top->next->value))
		try_rrr_before_rra(stack_a, stack_b, 1);
	if (stack_a->top->value > stack_a->top->next->value
		&& stack_a->top->value < stack_a->bottom->value)
		return (sort_two(stack_a, stack_b));
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
	// t_plate	*smallest;
	// t_plate	*second_smallest;

	if (!stack_a || !stack_b)
		return (ft_putstr_fd("Error\n", 1));
	// smallest = get_smallest_plate(stack_a);
	// run_cheapest_push(stack_a, stack_b, smallest);
	// if (stack_a->size > 3)
	// 	second_smallest = get_smallest_plate(stack_a);
	// if (stack_a->size > 3)
	// 	run_cheapest_push(stack_a, stack_b, second_smallest);
	// ft_print_stacks(stack_a, stack_b);
	// smallest_to_top(stack_a, stack_b, 2);
	if (stack_is_asc(stack_a))
		return ;
	if (stack_a->size > 3)
		pre_sort_pb(stack_a, stack_b, 2);
	// ft_print_stacks(stack_a, stack_b);
	if (stack_a->size > 3)
		pre_sort_pb(stack_a, stack_b, 2);
	// ft_print_stacks(stack_a, stack_b);
	// if (stack_is_asc(stack_a))
	// 	ft_pa(stack_a, stack_b);
	// else
	// 	ft_pb(stack_a, stack_b);
	// ft_print_stacks(stack_a, stack_b);
	sort_three(stack_a, stack_b);
	if (stack_b->top->value < stack_b->bottom->value)
		try_ss_before_sb(stack_a, stack_b);
	ft_print_stacks(stack_a, stack_b);
	ft_pa(stack_a, stack_b);
	ft_print_stacks(stack_a, stack_b);
	ft_pa(stack_a, stack_b);
	ft_print_stacks(stack_a, stack_b);
	// return (ft_pa(stack_a, stack_b));
}

void	sort_small_stack(t_stack *stack_a, t_stack *stack_b)
{
	if (!stack_a || !stack_b)
		return (ft_putstr_fd("Error\n", 1));
	if (stack_a->size < 2)
		return ;
	// if (stack_a->size < 4)
	// 	return (sort_three(stack_a));
	return (sort_five(stack_a, stack_b));
}

void	pre_sort_pb(t_stack *stack_a, t_stack *stack_b, int pivot)
{
	if (!stack_a || !stack_b)
		return ;
	if (pivot > stack_a->top->sorted_position
		|| pivot > stack_a->top->next->sorted_position
		|| pivot > stack_a->bottom->sorted_position)
	{
		if (stack_a->top->sorted_position < stack_a->top->next->sorted_position
			&& stack_a->top->sorted_position < stack_a->bottom->sorted_position)
			 ;
		else if (stack_a->top->next->sorted_position
			< stack_a->bottom->sorted_position)
			try_ss_before_sa(stack_a, stack_b);
		else
			try_rrr_before_rra(stack_a, stack_b, 1);
		ft_pb(stack_a, stack_b);
	}
	else
	{
		if (stack_a->top->sorted_position < stack_a->top->next->sorted_position
			&& stack_a->top->sorted_position < stack_a->bottom->sorted_position)
		{
			try_rrr_before_rra(stack_a, stack_b, 1);
			try_ss_before_sa(stack_a, stack_b);
			try_rr_before_ra(stack_a, stack_b, 1);
		}
		else if (stack_a->top->next->sorted_position
			< stack_a->bottom->sorted_position)
		{
			try_ss_before_sa(stack_a, stack_b);
			try_rrr_before_rra(stack_a, stack_b, 1);
			try_ss_before_sa(stack_a, stack_b);
			try_rr_before_ra(stack_a, stack_b, 1);
		}
		if (stack_a->top->sorted_position > stack_a->top->next->sorted_position)
			try_ss_before_sa(stack_a, stack_b);
		return (try_rr_before_ra(stack_a, stack_b, 2));
	}
}
