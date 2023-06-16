/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quick_selection.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: osarsari <osarsari@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/16 23:52:53 by osarsari          #+#    #+#             */
/*   Updated: 2023/06/17 00:46:52 by osarsari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	lower_half_pb(t_stack *stack_a, t_stack *stack_b)
{
	t_plate	*smallest_staying_plate;
	int		midpoint;
	int		i;

	if (!stack_a || !stack_b)
		return (ft_putstr_fd("Error in lower_half_pb.\n", 2));
	// else if (stack_a->size >= 100)
	// 	midpoint = stack_a->size / 8;
	// else if (stack_a->size >= 66)
	// 	midpoint = stack_a->size / 6;
	// else if (stack_a->size >= 33)
	// 	midpoint = stack_a->size / 4;
	// else if (stack_a->size >= 6)
	// 	midpoint = stack_a->size / 2;
	else if (stack_a->size >= 5)
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

t_plate	*get_smallest_bigger(t_stack *stack, t_plate *to_move)
{
	t_plate	*smallest_bigger;

	smallest_bigger = get_smallest_plate(stack);
	while (to_move->value > smallest_bigger->value)
		smallest_bigger = get_bigger_plate(stack, smallest_bigger);
	return (smallest_bigger);
}
// int	cost_r(t_stack *stack, t_plate *to_move)
// {
// 	int		res;
// 	t_plate	*plate;

// 	plate = stack->top;
// 	res = 0;
// 	while (plate->value != to_move->value)
// 	{
// 		res++;
// 		plate = plate->next;
// 	}
// 	return (res);
// }

// int	cost_rr(t_stack *stack, t_plate *to_move)
// {
// 	int		res;
// 	t_plate	*plate;

// 	res = 1;
// 	plate = stack->bot;
// 	while (plate->value != to_move->value)
// 	{
// 		res++;
// 		plate = plate->prev;
// 	}
// 	return (res);
// }

// int	ft_max(int a, int b)
// {
// 	if (a > b)
// 		return (a);
// 	return (b);
// }

// int	ft_min(int a, int b)
// {
// 	if (a > b)
// 		return (b);
// 	return (a);
// }

// int	cost_logic(int ra, int rb, int rra, int rrb)
// {
// 	int	rr;
// 	int	rrr;
// 	int rab;

// 	rr = ft_max(ra, rb);
// 	rrr = ft_max(rra, rrb);
// 	rab = ft_min(ra, rra) + ft_min(rb, rrb);
// 	return (ft_min(ft_min(rr, rrr), rab));
// }

int	lowest_cost_pa(t_stack *stack_a, t_stack *stack_b, t_plate *to_move)
{
	t_plate	*smallest_bigger;
	int		ra;
	int		rb;
	int		rra;
	int		rrb;

	smallest_bigger = get_smallest_bigger(stack_a, to_move);
	ra = cost_r(stack_a, smallest_bigger);
	rb = cost_r(stack_b, to_move);
	rra = cost_rr(stack_a, smallest_bigger);
	rrb = cost_rr(stack_b, to_move);
	return (cost_logic(ra, rb, rra, rrb));
}

t_plate	*find_best_pa(t_stack *stack_a, t_stack *stack_b)
{
	t_plate	*top_candidate;
	t_plate	*bot_candidate;
	t_plate	*best;
	int		min_cost;
	int		cost;
	int		i;

	top_candidate = stack_b->top;
	bot_candidate = stack_b->bot;
	best = top_candidate;
	if (bot_candidate == top_candidate)
		return (best);
	min_cost = lowest_cost_pa(stack_a, stack_b, top_candidate);
	i = min_cost;
	while (i-- > 0 && top_candidate->next && bot_candidate)
	{
		top_candidate = top_candidate->next;
		cost = lowest_cost_pa(stack_a, stack_b, top_candidate);
		if (cost < min_cost)
		{
			min_cost = cost;
			best = top_candidate;
			if (i > min_cost)
				i = min_cost;
		}
		cost = lowest_cost_pa(stack_a, stack_b, bot_candidate);
		if (cost < min_cost)
		{
			min_cost = cost;
			best = top_candidate;
			if (i > min_cost)
				i = min_cost;
		}
		bot_candidate = bot_candidate->prev;
	}
	return (best);
}

void	exec_rr_pa(t_stack *stack_a, t_stack *stack_b, int ra, int rb)
{
	if (ra > rb)
	{
		ft_rr(stack_a, stack_b, rb);
		ft_ra(stack_a, ra - rb);
	}
	else
	{
		ft_rr(stack_a, stack_b, ra);
		ft_rb(stack_b, rb - ra);
	}
	ft_pa(stack_a, stack_b);
}

void	exec_rrr_pa(t_stack *stack_a, t_stack *stack_b, int rra, int rrb)
{
	if (rra > rrb)
	{
		ft_rrr(stack_a, stack_b, rrb);
		ft_rra(stack_a, rra - rrb);
	}
	else
	{
		ft_rrr(stack_a, stack_b, rra);
		ft_rrb(stack_b, rrb - rra);
	}
	ft_pa(stack_a, stack_b);
}

void	exec_best_pa(t_stack *stack_a, t_stack *stack_b, t_plate *to_move)
{
	t_plate	*smallest_bigger;
	int		ra;
	int		rb;
	int		rra;
	int		rrb;

	smallest_bigger = get_smallest_bigger(stack_a, to_move);
	ra = cost_r(stack_a, smallest_bigger);
	rra = cost_rr(stack_a, smallest_bigger);
	rb = cost_r(stack_b, to_move);
	rrb = cost_rr(stack_b, to_move);
	if (ft_max(ra, rb) <= ft_max(rra, rrb)
		&& ft_max(ra, rb) <= (ft_min(ra, rra) + ft_min(rb, rrb)))
		return (exec_rr_pa(stack_a, stack_b, ra, rb));
	if (ft_max(rra, rrb) < ft_max(ra, rb)
		&& ft_max(rra, rrb) <= (ft_min(ra, rra) + ft_min(rb, rrb)))
		return (exec_rrr_pa(stack_a, stack_b, rra, rrb));
	if (ra > rra)
		ft_rra(stack_a, rra);
	else
		ft_ra(stack_a, ra);
	if (rb > rrb)
		ft_rrb(stack_b, rrb);
	else
		ft_rb(stack_b, rb);
	ft_pa(stack_a, stack_b);
}

void	cheap_pa(t_stack *stack_a, t_stack *stack_b)
{
	t_plate	*to_move;

	to_move = find_best_pa(stack_a, stack_b);
	exec_best_pa(stack_a, stack_b, to_move);
}

void	quick_selection(t_stack *stack_a, t_stack *stack_b)
{
	while (stack_a->size > 3)
		lower_half_pb(stack_a, stack_b);
	sort_three(stack_a, stack_b);
	while (stack_b->size > 0)
		cheap_pa(stack_a, stack_b);
	put_plate_top(stack_a, stack_b, get_smallest_plate(stack_a), 0);
}
