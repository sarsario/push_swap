/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cost_sort.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: osarsari <osarsari@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/14 13:17:55 by osarsari          #+#    #+#             */
/*   Updated: 2023/06/14 13:53:53 by osarsari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	closest_top_pb(t_stack *stack_a, t_stack *stack_b, int value)
{
	t_plate	*top_a;
	int		ra;
	t_plate	*bot_a;
	int		rra;

	top_a = stack_a->top;
	ra = 0;
	while (top_a->value > value)
	{
		ra++;
		top_a = top_a->next;
	}
	rra = 1;
	bot_a = stack_a->bot;
	while (bot_a->value > value)
	{
		rra++;
		bot_a = bot_a->prev;
	}
	if (ra > rra)
		ft_rra(stack_a, rra);
	else
		ft_ra(stack_a, ra);
	ft_pb(stack_a, stack_b);
}

t_plate	*get_biggest_smaller(t_stack *stack, t_plate *to_move)
{
	t_plate	*biggest_smaller;

	biggest_smaller = get_biggest_plate(stack);
	while (biggest_smaller->value > to_move->value)
		biggest_smaller = get_smaller_plate(stack, biggest_smaller);
	return (biggest_smaller);
}

int	lowest_cost_pb(t_stack *stack_a, t_stack *stack_b, t_plate *to_move)
{
	t_plate	*biggest_smaller;

	if (to_move->value > get_biggest_plate(stack_b)
		|| to_move->value < get_smallest_plate(stack_b))
		biggest_smaller = get_biggest_plate(stack_b);
	else
		biggest_smaller = get_biggest_smaller(stack_b, to_move);
	
}

void	push_lower_b(t_stack *stack_a, t_stack *stack_b, int value)
{
	t_plate	*candidate_pb;
	int		min_cost;
	int		cost;
	int		i;

	if (stack_b->size < 2)
		return (closest_top_pb(stack_a, stack_b, value));
	candidate_pb = stack_a->top;
	min_cost = lowest_cost_pb(stack_a, stack_b, candidate_pb);
	i = min_cost;
	// while (i--)
}

void	cost_sort(t_stack *stack_a, t_stack *stack_b)
{
	int		ref_value;

	ref_value = get_smaller_plate(
		stack_a, get_smaller_plate(stack_a, get_biggest_plate(stack_a)))->value;
	while (stack_a->size > 3)
		push_lower_b(stack_a, stack_b, ref_value);
	sort_three(stack_a, stack_b);
	while (stack_b->size > 0)
	{
		put_plate_top(stack_a, stack_b, get_biggest_plate(stack_b), 1);
		ft_pa(stack_a, stack_b);
	}
}
