/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   optimized_push.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: osarsari <osarsari@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/25 15:22:28 by osarsari          #+#    #+#             */
/*   Updated: 2023/06/03 13:02:34 by osarsari         ###   ########.fr       */
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

void	optimal_half_pa(t_stack *stack_a, t_stack *stack_b, int value)
{
	t_plate	*closest_from_top;
	t_plate	*closest_from_bot;
	int		nb_rb;
	int		nb_rrb;

	if (!stack_a || !stack_b || stack_b->size < 1)
		return (ft_putstr_fd("Error in optimal_half_pa.\n", 1));
	closest_from_top = stack_b->top;
	nb_rb = 0;
	while (closest_from_top->value <= value && nb_rb++ > -1)
		closest_from_top = closest_from_top->next;
	nb_rrb = 1;
	closest_from_bot = stack_b->bot;
	while (closest_from_bot->value <= value && nb_rrb++ > -1)
		closest_from_bot = closest_from_bot->prev;
	if (nb_rb > nb_rrb)
		try_rrr_before_rrb(stack_a, stack_b, nb_rrb);
	else if (nb_rrb > nb_rb)
		try_rr_before_rb(stack_a, stack_b, nb_rb);
	else if (closest_from_top->value > closest_from_bot->value)
		try_rr_before_rb(stack_a, stack_b, nb_rb);
	else
		try_rrr_before_rrb(stack_a, stack_b, nb_rrb);
	ft_pa(stack_a, stack_b);
}

void	top_half_pa(t_stack *stack_a, t_stack *stack_b)
{
	t_plate	*biggest_staying;
	t_plate	*plate;
	int		midpoint;
	int		i;

	if (!stack_a || !stack_b)
		return (ft_putstr_fd("Error in top_half_pa.\n", 1));
	if (stack_b->size < 2)
		return (ft_pa(stack_a, stack_b));
	biggest_staying = get_smallest_plate(stack_b);
	plate = stack_b->bot;
	i = 0;
	while (plate == biggest_staying && i++ > -1)
	{
		plate = plate->prev;
		biggest_staying = get_bigger_plate(stack_b, biggest_staying);
	}
	// midpoint = (stack_b->size / 2) + i;
	midpoint = (stack_b->size - i) / 2;
	i = midpoint;
	while (--i > 0)
		biggest_staying = get_bigger_plate(stack_b, biggest_staying);
	i = biggest_staying->value;
	while (!stack_is_dsc(stack_b) && stack_b->bot->position >= midpoint)
		optimal_half_pa(stack_a, stack_b, i);
}

void	optimal_half_pb(t_stack *stack_a, t_stack *stack_b, int value)
{
	t_plate	*closest_from_top;
	t_plate	*closest_from_bot;
	int		nb_ra;
	int		nb_rra;

	if (!stack_a || !stack_b || stack_a->size < 1)
		return (ft_putstr_fd("Error in optimal_half_pb.\n", 1));
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

void	lower_half_pb(t_stack *stack_a, t_stack *stack_b)
{
	t_plate	*smallest_staying_plate;
	t_plate	*plate;
	int		midpoint;
	int		i;

	if (!stack_a || !stack_b)
		return (ft_putstr_fd("Error in lower_half_pb.\n", 1));
	smallest_staying_plate = get_biggest_plate(stack_a);
	plate = stack_a->bot;
	i = 0;
	while (plate == smallest_staying_plate)
	{
		i++;
		plate = plate->prev;
		smallest_staying_plate = get_smaller_plate(stack_a,
				smallest_staying_plate);
	}
	// midpoint = (stack_a->size / 2) + i;
	midpoint = (stack_a->size - i) / 2;
	i = midpoint;
	while (--i > 0)
		smallest_staying_plate = get_smaller_plate(
				stack_a, smallest_staying_plate);
	i = smallest_staying_plate->value;
	while (!stack_is_asc(stack_a) && stack_a->bot->position >= midpoint)
		optimal_half_pb(stack_a, stack_b, i);
}
