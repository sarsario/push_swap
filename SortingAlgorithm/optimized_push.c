/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   optimized_push.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: osarsari <osarsari@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/25 15:22:28 by osarsari          #+#    #+#             */
/*   Updated: 2023/06/14 13:11:30 by osarsari         ###   ########.fr       */
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

// Pour push dans stack_b:
// Si plate < min_b || plate > max_b: placer le plus grand top.
// Sinon: placer le plus grand parmi les plus petit au top.

void	lower_pb(t_stack *stack_a, t_stack *stack_b, int value)
{
	t_plate	*closest_from_top;
	t_plate	*closest_from_bot;
	int		nb_ra;
	int		nb_rra;

	closest_from_top = stack_a->top;
	nb_ra = 0;
	while (closest_from_top->value >= value && nb_ra++ > -1)
		closest_from_top = closest_from_top->next;
	nb_rra = 1;
	closest_from_bot = stack_a->bot;
	while (closest_from_bot->value >= value && nb_rra++ > -1)
		closest_from_bot = closest_from_bot->prev;
	if (nb_ra > nb_rra)
		try_rrr_before_rra(stack_a, stack_b, nb_rra);
	else if (nb_rra > nb_ra)
		try_rr_before_ra(stack_a, stack_b, nb_ra);
	else if (closest_from_top->value < closest_from_bot->value)
		try_rr_before_ra(stack_a, stack_b, nb_ra);
	else
		try_rrr_before_rra(stack_a, stack_b, nb_rra);
	ft_pb(stack_a, stack_b);
}

void	optimal_half_pb(t_stack *stack_a, t_stack *stack_b, int value)
{
	t_plate	*closest_from_top;
	t_plate	*closest_from_bot;
	int		nb_ra;
	int		nb_rra;

	if (stack_b->size < 2)
		return (lower_pb(stack_a, stack_b, value));
	closest_from_top = stack_a->top;
	nb_ra = 0;
	while (closest_from_top->value >= value && nb_ra++ > -1)
		closest_from_top = closest_from_top->next;
	nb_rra = 1;
	closest_from_bot = stack_a->bot;
	while (closest_from_bot->value >= value && nb_rra++ > -1)
		closest_from_bot = closest_from_bot->prev;
	if (nb_ra > nb_rra)
		aligned_pb_rra(stack_a, stack_b, closest_from_bot, nb_rra);
	else if (nb_rra > nb_ra)
		aligned_pb_ra(stack_a, stack_b, closest_from_top, nb_ra);
	else if (closest_from_top->value < closest_from_bot->value)
		aligned_pb_ra(stack_a, stack_b, closest_from_top, nb_ra);
	else
		aligned_pb_rra(stack_a, stack_b, closest_from_bot, nb_rra);
	ft_pb(stack_a, stack_b);
}

void	lower_half_pb(t_stack *stack_a, t_stack *stack_b)
{
	t_plate	*smallest_staying_plate;
	int		midpoint;
	int		i;

	if (!stack_a || !stack_b)
		return (ft_putstr_fd("Error in lower_half_pb.\n", 1));
	else if (stack_a->size > 167)
		midpoint = stack_a->size / 5;
	else if (stack_a->size > 100)
		midpoint = stack_a->size / 4;
	else if (stack_a->size > 32)
		midpoint = stack_a->size / 3;
	else if (stack_a->size > 4)
		midpoint = stack_a->size / 2;
	else
		midpoint = 1;
	smallest_staying_plate = get_biggest_plate(stack_a);
	i = stack_a->size - midpoint;
	while (--i > 0)
		smallest_staying_plate = get_smaller_plate(
				stack_a, smallest_staying_plate);
	i = smallest_staying_plate->value;
	while (midpoint--)
		optimal_half_pb(stack_a, stack_b, i);
}
