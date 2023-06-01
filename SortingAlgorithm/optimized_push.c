/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   optimized_push.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: osarsari <osarsari@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/25 15:22:28 by osarsari          #+#    #+#             */
/*   Updated: 2023/06/01 16:39:18 by osarsari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	pre_sort_pb(t_stack *stack_a, t_stack *stack_b, int pivot)
{
	if (!stack_a || !stack_b)
		return (ft_putstr_fd("Error in pre_sort_pb\n", 1));
	if (pivot > stack_a->top->sorted_position
		|| pivot > stack_a->top->next->sorted_position
		|| pivot > stack_a->bot->sorted_position)
	{
		if (stack_a->top->next->sorted_position < stack_a->top->sorted_position)
			try_ss_before_sa(stack_a, stack_b);
		if (stack_a->bot->sorted_position < stack_a->top->sorted_position)
			try_rrr_before_rra(stack_a, stack_b, 1);
		if (!stack_is_asc(stack_a))
			return (ft_pb(stack_a, stack_b));
	}
	else
		return (try_rr_before_ra(stack_a, stack_b, 2));
}

int	distance_top_rotate(t_stack *stack, t_plate *plate)
{
	t_plate	*top;
	int		distance;

	if (!stack || !plate || stack->size < 1)
		return (-1);
	distance = 0;
	top = stack->top;
	while (top != plate)
	{
		distance++;
		top = top->next;
	}
	return (distance);
}

int	distance_top_reverse_rotate(t_stack *stack, t_plate *plate)
{
	t_plate	*bot;
	int		distance;

	if (!stack || !plate || stack->size < 1)
		return (-1);
	distance = 1;
	bot = stack->bot;
	while (bot != plate)
	{
		distance++;
		bot = bot->prev;
	}
	return (distance);
}

void	put_plate_top(t_stack *stack_a, t_stack *stack_b, t_plate *plate, int i)
{
	int	r_needed;
	int	rr_needed;

	if (!stack_a || !stack_b || !plate)
		return (ft_putstr_fd("Error in send_plate_top\n", 1));
	if (i == 0)
		r_needed = distance_top_rotate(stack_a, plate);
	else
		r_needed = distance_top_rotate(stack_b, plate);
	if (i == 0)
		rr_needed = distance_top_reverse_rotate(stack_a, plate);
	else
		rr_needed = distance_top_reverse_rotate(stack_b, plate);
	if (r_needed == -1 || rr_needed == -1)
		return (ft_putstr_fd("Error in distance_top\n", 1));
	if (i == 0 && rr_needed < r_needed)
		try_rrr_before_rra(stack_a, stack_b, rr_needed);
	else if (rr_needed < r_needed)
		try_rrr_before_rrb(stack_a, stack_b, rr_needed);
	else if (i == 0)
		try_rr_before_ra(stack_a, stack_b, r_needed);
	else
		try_rr_before_rb(stack_a, stack_b, r_needed);
}
