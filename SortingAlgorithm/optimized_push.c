/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   optimized_push.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: osarsari <osarsari@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/25 15:22:28 by osarsari          #+#    #+#             */
/*   Updated: 2023/06/10 11:51:16 by osarsari         ###   ########.fr       */
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

// void	top_half_pa(t_stack *stack_a, t_stack *stack_b)
// {
// 	int	midpoint;

// 	if (!stack_a || !stack_b)
// 		return (ft_putstr_fd("Error in top_half_pa.\n", 1));
// 	if (stack_b->size < 2)
// 		return (ft_pa(stack_a, stack_b));
// 	if (stack_b->size < 3 && stack_b->top->value < stack_b->bot->value)
// 		try_ss_before_sb(stack_a, stack_b);
// 	while (stack_b->size < 3 && stack_b->size > 0)
// 		ft_pa(stack_a, stack_b);
// 	midpoint = stack_b->size / 2;
// }

void	optimal_half_pb(t_stack *stack_a, t_stack *stack_b,
	int value)
{
	t_plate	*closest_from_top;
	t_plate	*closest_from_bot;
	int		nb_ra;
	int		nb_rra;

	if (!stack_a || !stack_b || stack_a->size < 1)
		return (ft_putstr_fd("Error in optimal_half_pb.\n", 2));
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

void	optimal_pa(t_stack *stack_a, t_stack *stack_b)
{
	t_plate	*best_plate;

	best_plate = best_plate_pa(stack_a, stack_b);
	align_stacks_pa(stack_a, stack_b, best_plate);
	ft_pa(stack_a, stack_b);
}

// void	optimal_half_pb(t_stack *stack_a, t_stack *stack_b, int staying_value)
// {
// 	t_plate	*to_pb;

// 	to_pb = best_plate_pb(stack_a, stack_b, staying_value);
// 	align_stacks(stack_a, stack_b, to_pb);
// 	ft_pb(stack_a, stack_b);
// }

void	optimal_half_pa(t_stack *stack_a, t_stack *stack_b, int staying_value)
{
	t_plate	*to_pa;

	to_pa = best_plate_pa_half(stack_a, stack_b, staying_value);
	align_stacks_pa(stack_a, stack_b, to_pa);
	ft_pa(stack_a, stack_b);
}

void	upper_half_pa(t_stack *stack_a, t_stack *stack_b)
{
	t_plate	*biggest_staying_plate;
	int		midpoint;
	int		i;

	if (!stack_a || !stack_b)
		return (ft_putstr_fd("Error in upper_half_pb.\n", 2));
	if (stack_b->size >= 100)
		midpoint = stack_b->size / 8;
	else if (stack_b->size >= 66)
		midpoint = stack_b->size / 6;
	else if (stack_b->size >= 33)
		midpoint = stack_b->size / 4;
	else
		midpoint = stack_b->size / 2;
	biggest_staying_plate = get_smallest_plate(stack_b);
	i = stack_b->size - midpoint;
	while (--i > 0)
		biggest_staying_plate = get_bigger_plate(stack_b,
				biggest_staying_plate);
	i = biggest_staying_plate->value;
	while (midpoint--)
		optimal_half_pa(stack_a, stack_b, i);
}

void	lower_half_pb(t_stack *stack_a, t_stack *stack_b)
{
	t_plate	*smallest_staying_plate;
	int		midpoint;
	int		i;

	if (!stack_a || !stack_b)
		return (ft_putstr_fd("Error in lower_half_pb.\n", 2));
	if (stack_a->size > 500)
		midpoint = stack_a->size / 12;
	// else if (stack_a->size > 250)
	// 	midpoint = stack_a->size / 10;
	else if (stack_a->size >= 100)
		midpoint = stack_a->size / 8;
	else if (stack_a->size >= 66)
		midpoint = stack_a->size / 6;
	else if (stack_a->size >= 33)
		midpoint = stack_a->size / 4;
	else if (stack_a->size >= 6)
		midpoint = stack_a->size / 2;
	else if (stack_a->size == 5)
		midpoint = 2;
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
