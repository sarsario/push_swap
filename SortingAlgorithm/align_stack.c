/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   align_stack.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: osarsari <osarsari@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/14 12:58:37 by osarsari          #+#    #+#             */
/*   Updated: 2023/06/14 13:07:16 by osarsari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

t_plate	*get_biggest_smaller(t_stack *stack, t_plate *to_compare)
{
	t_plate	*plate;

	plate = get_biggest_plate(stack);
	while (plate->value > to_compare->value)
		plate = get_smaller_plate(stack, plate);
	return (plate);
}

int	cost_r(t_stack *stack, t_plate *to_top)
{
	int		cost;
	t_plate	*current;

	cost = 0;
	current = stack->top;
	while (current->value != to_top->value)
	{
		cost++;
		current = current->next;
	}
	return (cost);
}

int	cost_rr(t_stack *stack, t_plate *to_top)
{
	int		cost;
	t_plate	*current;

	cost = 1;
	current = stack->bot;
	while (current->value != to_top->value)
	{
		cost++;
		current = current->prev;
	}
	return (cost);
}

void	aligned_pb_ra(t_stack *stack_a, t_stack *stack_b, t_plate *to_move,
	int nb_ra)
{
	t_plate	*biggest_smaller;
	int		rb_count;
	int		rrb_count;

	if (to_move->value > get_biggest_plate(stack_b)->value
		|| to_move->value < get_smallest_plate(stack_b)->value)
		biggest_smaller = get_biggest_plate(stack_b);
	else
		biggest_smaller = get_biggest_smaller(stack_b, to_move);
	rb_count = cost_r(stack_b, biggest_smaller);
	rrb_count = cost_rr(stack_b, biggest_smaller);
	if (ft_absolute(rb_count - nb_ra) > rrb_count)
		ft_ra(stack_a, nb_ra);
	if (ft_absolute(rb_count - nb_ra) > rrb_count)
		return (ft_rrb(stack_b, rrb_count));
	if (rb_count > nb_ra)
		ft_rr(stack_a, stack_b, nb_ra);
	if (rb_count > nb_ra)
		return (ft_rb(stack_b, rb_count - nb_ra));
	ft_rr(stack_a, stack_b, rb_count);
	ft_ra(stack_a, nb_ra - rb_count);
}

void	aligned_pb_rra(t_stack *stack_a, t_stack *stack_b, t_plate *to_move,
	int nb_rra)
{
	t_plate	*biggest_smaller;
	int		rb_count;
	int		rrb_count;

	if (to_move->value > get_biggest_plate(stack_b)->value
		|| to_move->value < get_smallest_plate(stack_b)->value)
		biggest_smaller = get_biggest_plate(stack_b);
	else
		biggest_smaller = get_biggest_smaller(stack_b, to_move);
	rb_count = cost_r(stack_b, biggest_smaller);
	rrb_count = cost_rr(stack_b, biggest_smaller);
	if (ft_absolute(rrb_count - nb_rra) > rb_count)
		ft_rra(stack_a, nb_rra);
	if (ft_absolute(rrb_count - nb_rra) > rb_count)
		return (ft_rb(stack_b, rb_count));
	if (rrb_count > nb_rra)
		ft_rrr(stack_a, stack_b, nb_rra);
	if (rrb_count > nb_rra)
		return (ft_rrb(stack_b, rrb_count - nb_rra));
	ft_rrr(stack_a, stack_b, rrb_count);
	ft_rra(stack_a, nb_rra - rrb_count);
}
