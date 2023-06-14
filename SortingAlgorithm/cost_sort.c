/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cost_sort.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: osarsari <osarsari@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/14 13:17:55 by osarsari          #+#    #+#             */
/*   Updated: 2023/06/14 20:46:40 by osarsari         ###   ########.fr       */
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
	while (top_a->value >= value)
	{
		ra++;
		top_a = top_a->next;
	}
	rra = 1;
	bot_a = stack_a->bot;
	while (bot_a->value >= value)
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

int	cost_r(t_stack *stack, t_plate *to_move)
{
	int		res;
	t_plate	*plate;

	plate = stack->top;
	res = 0;
	while (plate->value != to_move->value)
	{
		res++;
		plate = plate->next;
	}
	return (res);
}

int	cost_rr(t_stack *stack, t_plate *to_move)
{
	int		res;
	t_plate	*plate;

	res = 1;
	plate = stack->bot;
	while (plate->value != to_move->value)
	{
		res++;
		plate = plate->prev;
	}
	return (res);
}

int	ft_max(int a, int b)
{
	if (a > b)
		return (a);
	return (b);
}

int	ft_min(int a, int b)
{
	if (a > b)
		return (b);
	return (a);
}

int	cost_logic(int ra, int rb, int rra, int rrb)
{
	int	rr;
	int	rrr;
	int	rab;

	rr = ft_max(ra, rb);
	rrr = ft_max(rra, rrb);
	rab = ft_min(ra, rra) + ft_min(rb, rrb);
	return (ft_min(ft_min(rr, rrr), rab));
}

int	lowest_cost_pb(t_stack *stack_a, t_stack *stack_b, t_plate *to_move)
{
	t_plate	*biggest_smaller;
	int	ra;
	int	rb;
	int	rra;
	int	rrb;

	if (to_move->value > get_biggest_plate(stack_b)->value
		|| to_move->value < get_smallest_plate(stack_b)->value)
		biggest_smaller = get_biggest_plate(stack_b);
	else
		biggest_smaller = get_biggest_smaller(stack_b, to_move);
	ra = cost_r(stack_a, to_move);
	rb = cost_r(stack_b, biggest_smaller);
	rra = cost_rr(stack_a, to_move);
	rrb = cost_rr(stack_b, biggest_smaller);
	return (cost_logic(ra, rb, rra, rrb));
}

t_plate	*find_best_pb(t_stack *stack_a, t_stack *stack_b, int value)
{
	t_plate	*top_candidate;
	t_plate	*bot_candidate;
	t_plate	*to_move;
	int		min_cost;
	int		cost;
	int		i;

	top_candidate = stack_a->top;
	while (top_candidate->value >= value)
		top_candidate = top_candidate->next;
	to_move = top_candidate;
	min_cost = lowest_cost_pb(stack_a, stack_b, top_candidate);
	i = min_cost;
	bot_candidate = stack_a->bot;
	while (bot_candidate->value >= value)
		bot_candidate = bot_candidate->prev;
	while (i-- > 0 && top_candidate->next && bot_candidate)
	{
		top_candidate = top_candidate->next;
		if (top_candidate->value >= value)
			cost = INT_MAX;
		else
			cost = lowest_cost_pb(stack_a, stack_b, top_candidate);
		if (cost < min_cost)
		{
			min_cost = cost;
			i = min_cost;
			to_move = top_candidate;
		}
		if (bot_candidate->value >= value)
			cost = INT_MAX;
		else
			cost = lowest_cost_pb(stack_a, stack_b, bot_candidate);
		if (cost < min_cost)
		{
			min_cost = cost;
			i = min_cost;
			to_move = bot_candidate;
		}
		bot_candidate = bot_candidate->prev;
	}
	return (to_move);
}

void	exec_rr_pb(t_stack *stack_a, t_stack *stack_b, int ra, int rb)
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
	ft_pb(stack_a, stack_b);
}

void	exec_rrr_pb(t_stack *stack_a, t_stack *stack_b, int rra, int rrb)
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
	ft_pb(stack_a, stack_b);
}

void	exec_best_pb(t_stack *stack_a, t_stack *stack_b, t_plate *to_move)
{
	t_plate *to_top_b;
	int		ra;
	int		rb;
	int		rra;
	int		rrb;

	if (to_move->value > get_biggest_plate(stack_b)->value
		|| to_move->value < get_smallest_plate(stack_b)->value)
		to_top_b = get_biggest_plate(stack_b);
	else
		to_top_b = get_biggest_smaller(stack_b, to_move);
	ra = cost_r(stack_a, to_move);
	rb = cost_r(stack_b, to_top_b);
	rra = cost_rr(stack_a, to_move);
	rrb = cost_rr(stack_b, to_top_b);
	if (ft_max(ra, rb) <= ft_max(rra, rrb)
		&& ft_max(ra, rb) <= (ft_min(ra, rra) + ft_min(rb, rrb)))
		return (exec_rr_pb(stack_a, stack_b, ra, rb));
	if (ft_max(rra, rrb) < ft_max(ra, rb)
		&& ft_max(rra, rrb) <= (ft_min(ra, rra) + ft_min(rb, rrb)))
		return (exec_rrr_pb(stack_a, stack_b, rra, rrb));
	if (ra > rra)
		ft_rra(stack_a, rra);
	else
		ft_ra(stack_a, ra);
	if (rb > rrb)
		ft_rrb(stack_b, rrb);
	else
		ft_rb(stack_b, rb);
	ft_pb(stack_a, stack_b);
}

void	push_lower_b(t_stack *stack_a, t_stack *stack_b, int value)
{
	t_plate	*to_move;

	if (stack_b->size < 2)
		return (closest_top_pb(stack_a, stack_b, value));
	to_move = find_best_pb(stack_a, stack_b, value);
	exec_best_pb(stack_a, stack_b, to_move);
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
