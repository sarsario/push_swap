/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cost.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: osarsari <osarsari@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/09 17:11:11 by osarsari          #+#    #+#             */
/*   Updated: 2023/06/10 09:51:51 by osarsari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int	cost_rotate_top(t_stack *stack, t_plate *plate)
{
	int		nb_r;
	t_plate	*plate_i;

	nb_r = 0;
	plate_i = stack->top;
	while (plate_i != plate)
	{
		nb_r++;
		plate_i = plate_i->next;
	}
	return (nb_r);
}

int	cost_reverse_top(t_stack *stack, t_plate *plate)
{
	int		nb_rr;
	t_plate	*plate_i;

	nb_rr = 1;
	plate_i = stack->bot;
	while (plate_i != plate)
	{
		nb_rr++;
		plate_i = plate_i->prev;
	}
	return (nb_rr);
}

t_plate	*find_biggest_smaller(t_stack *stack, t_plate *plate)
{
	t_plate	*biggest_smaller;

	biggest_smaller = get_biggest_plate(stack);
	if (plate->value < get_smallest_plate(stack)->value)
		return (biggest_smaller);
	while (biggest_smaller->value > plate->value)
		biggest_smaller = get_smaller_plate(stack, biggest_smaller);
	return (biggest_smaller);
}

int	get_cost_indiv(int cost_ra, int cost_rb, int cost_rra, int cost_rrb)
{
	int	cost;

	cost = 0;
	if (cost_ra > cost_rra)
		cost += cost_rra;
	else
		cost += cost_ra;
	if (cost_rb > cost_rrb)
		cost += cost_rrb;
	else
		cost += cost_rb;
	return (cost);
}

int	get_cost_comb(int cost_ra, int cost_rb, int cost_rra, int cost_rrb)
{
	int	cost;

	if (cost_rb > cost_ra)
		cost = cost_rb;
	else
		cost = cost_ra;
	if (cost_rrb > cost_rra && cost > cost_rrb)
		cost = cost_rrb;
	else if (cost > cost_rra)
		cost = cost_rra;
	return (cost);
}

int	cost_trick(int cost_ra, int cost_rb, int cost_rra, int cost_rrb)
{
	int	cost_indiv;
	int	cost_comb;

	cost_indiv = get_cost_indiv(cost_ra, cost_rb, cost_rra, cost_rrb);
	cost_comb = get_cost_comb(cost_ra, cost_rb, cost_rra, cost_rrb);
	if (cost_comb > cost_indiv)
		return (cost_indiv);
	return (cost_comb);
}

int	ft_cost_pb(t_stack *stack_a, t_stack *stack_b, t_plate *to_move)
{
	t_plate	*should_be_top;
	int		cost_ra;
	int		cost_rb;
	int		cost_rra;
	int		cost_rrb;

	should_be_top = find_biggest_smaller(stack_b, to_move);
	cost_ra = cost_rotate_top(stack_a, to_move);
	cost_rb = cost_rotate_top(stack_b, should_be_top);
	cost_rra = cost_reverse_top(stack_a, to_move);
	cost_rrb = cost_reverse_top(stack_b, should_be_top);
	return (cost_trick(cost_ra, cost_rb, cost_rra, cost_rrb));
}

t_plate	*find_smallest_bigger(t_stack *stack, t_plate *to_move)
{
	t_plate	*smallest_bigger;

	smallest_bigger = get_smallest_plate(stack);
	while (to_move->value < smallest_bigger->value)
		smallest_bigger = get_bigger_plate(stack, smallest_bigger);
	return (smallest_bigger);
}

int	ft_cost_pa(t_stack *stack_a, t_stack *stack_b, t_plate *to_move)
{
	t_plate	*should_be_top;
	int		cost_ra;
	int		cost_rb;
	int		cost_rra;
	int		cost_rrb;

	should_be_top = find_smallest_bigger(stack_b, to_move);
	cost_ra = cost_rotate_top(stack_a, to_move);
	cost_rb = cost_rotate_top(stack_b, should_be_top);
	cost_rra = cost_reverse_top(stack_a, to_move);
	cost_rrb = cost_reverse_top(stack_b, should_be_top);
	return (cost_trick(cost_ra, cost_rb, cost_rra, cost_rrb));
}

t_plate	*best_plate_pb(t_stack *stack_a, t_stack *stack_b, int staying_value)
{
	t_plate	*plate;
	t_plate	*next;
	int		min_cost;
	int		cost;

	plate = stack_a->top;
	while (plate->value >= staying_value)
		plate = plate->next;
	if (stack_b->size == 0)
		return (plate);
	min_cost = ft_cost_pb(stack_a, stack_b, plate);
	next = plate->next;
	while (next)
	{
		cost = ft_cost_pb(stack_a, stack_b, next);
		if (next->value < staying_value && min_cost > cost)
		{
			min_cost = cost;
			plate = next;
		}
		next = next->next;
	}
	return (plate);
}
