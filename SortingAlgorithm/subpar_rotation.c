/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   subpar_rotation.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: osarsari <osarsari@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/03 00:49:44 by osarsari          #+#    #+#             */
/*   Updated: 2023/06/13 20:48:22 by osarsari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

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

int	rb_needed(t_stack *stack_b, int top_value)
{
	t_plate	*current;
	int		res;

	current = stack_b->top;
	res = 0;
	while (current->value != top_value)
	{
		res++;
		current = current->next;
	}
	return (res);
}

int	rrb_needed(t_stack *stack_b, int top_value)
{
	t_plate	*current;
	int		res;

	current = stack_b->bot;
	res = 1;
	while (current->value != top_value)
	{
		res++;
		current = current->prev;
	}
	return (res);
}

void	top_rb(t_stack *stack_b, int top_value)
{
	t_plate	*current;

	current = stack_b->top;
	while (current->value != top_value)
	{
		if (current->value < current->next->value)
			ft_sb(stack_b);
		else
			ft_rb(stack_b, 1);
	}
}

void	top_rrb(t_stack *stack_b, int top_value)
{
	t_plate	*current;

	current = stack_b->top;
	while (current->value != top_value)
	{
		if (current->value < current->next->value)
			ft_sb(stack_b);
		else
			ft_rrb(stack_b, 1);
	}
}

void	top_b(t_stack *stack_b, int top_value)
{
	t_plate	*current;
	int		nb_rb;
	int		nb_rrb;

	current = stack_b->top;
	nb_rb = rb_needed(stack_b, top_value);
	nb_rrb = rrb_needed(stack_b, top_value);
	if (nb_rb > nb_rrb)
		top_rrb(stack_b, top_value);
	else
		top_rb(stack_b, top_value);
}
