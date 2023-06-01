/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_five.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: osarsari <osarsari@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/25 15:02:00 by osarsari          #+#    #+#             */
/*   Updated: 2023/06/01 16:58:56 by osarsari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	sort_two(t_stack *stack_a, t_stack *stack_b)
{
	if (!stack_a || !stack_b)
		return (ft_putstr_fd("Error in sort_two.\n", 1));
	if (stack_a->size < 2)
		return ;
	if (stack_a->top->value > stack_a->top->next->value)
		try_ss_before_sa(stack_a, stack_b);
}

void	sort_three(t_stack *stack_a, t_stack *stack_b)
{
	if (!stack_a || !stack_b)
		return (ft_putstr_fd("Error in sort_three.\n", 1));
	if (stack_a->size < 3)
		return (sort_two(stack_a, stack_b));
	if (stack_is_dsc(stack_a)
		|| (stack_a->top->value > stack_a->bot->value
			&& stack_a->bot->value > stack_a->top->next->value))
		try_rr_before_ra(stack_a, stack_b, 1);
	if ((stack_a->top->value < stack_a->bot->value
			&& stack_a->bot->value < stack_a->top->next->value)
		|| (stack_a->top->value > stack_a->bot->value
			&& stack_a->top->value < stack_a->top->next->value))
		try_rrr_before_rra(stack_a, stack_b, 1);
	if (stack_a->top->value > stack_a->top->next->value
		&& stack_a->top->value < stack_a->bot->value)
		return (sort_two(stack_a, stack_b));
}

	// t_plate	*biggest_plate;

void	sort_five(t_stack *stack_a, t_stack *stack_b)
{
	if (!stack_a || !stack_b)
		return (ft_putstr_fd("Error in sort_five\n", 1));
	if (stack_is_asc(stack_a) && stack_b->size < 1)
		return ;
	while (stack_a->size > 3 && !stack_is_asc(stack_a))
		pre_sort_pb(stack_a, stack_b, stack_a->size - 3 + stack_b->size);
	sort_three(stack_a, stack_b);
	while (stack_b->size > 0)
	{
		if (stack_b->size > 1
			&& stack_b->top->sorted_position < stack_b->bot->sorted_position)
			try_ss_before_sb(stack_a, stack_b);
		ft_pa(stack_a, stack_b);
	}
}

// biggest_plate = get_biggest_plate(stack_b);
// if (stack_b->top != biggest_plate)
// 	put_plate_top(stack_a, stack_b, biggest_plate, 1);

void	sort_small_stack(t_stack *stack_a, t_stack *stack_b)
{
	if (!stack_a || !stack_b)
		return (ft_putstr_fd("Error in sort_small_stack\n", 1));
	if (stack_a->size < 2)
		return ;
	sort_five(stack_a, stack_b);
}
