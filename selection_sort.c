/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   selection_sort.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: osarsari <osarsari@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/15 18:55:12 by osarsari          #+#    #+#             */
/*   Updated: 2023/05/20 01:35:35 by osarsari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	smallest_to_top(t_stack *stack_a, t_stack *stack_b, int pivot)
{
	if (!stack_a || !stack_b)
		return ;
	if (stack_a->top->sorted_position > stack_a->top->next->sorted_position)
	{
		if (stack_b->size > 1
			&& stack_b->top->value < stack_b->top->next->value)
			ft_ss(stack_a, stack_b);
		else
			ft_sa(stack_a);
	}
	if (stack_a->bottom->sorted_position < pivot
		&& stack_a->top->sorted_position > stack_a->bottom->sorted_position)
	{
		if (stack_b->size > 1
			&& stack_b->bottom->sorted_position > stack_b->top->sorted_position)
			ft_rrr(stack_a, stack_b, 1);
		else
			ft_rra(stack_a, 1);
	}
}

void	second_to_last(t_stack *stack_a, t_stack *stack_b)
{
	if (!stack_a || !stack_b)
		return ;
	if (stack_b->size > 1
		&& stack_b->bottom->sorted_position > stack_b->top->sorted_position)
		ft_rrr(stack_a, stack_b, 1);
	else
		ft_rra(stack_a, 1);
	if (stack_b->size > 1
		&& stack_b->top->sorted_position < stack_b->top->next->sorted_position)
		ft_ss(stack_a, stack_b);
	else
		ft_sa(stack_a);
	if (stack_b->size > 1
		&& stack_b->top->sorted_position < stack_b->bottom->sorted_position)
		ft_rr(stack_a, stack_b, 1);
	else
		ft_ra(stack_a, 1);
	ft_ra(stack_a, 1);
}

void	push_beginning(t_stack *stack_a, t_stack *stack_b, int pivot)
{
	if (!stack_a || !stack_b)
		return ;
	smallest_to_top(stack_a, stack_b, pivot);
	if (stack_a->top->sorted_position < pivot)
		return (ft_pb(stack_a, stack_b));
	else if (stack_a->top->sorted_position < stack_a->bottom->sorted_position)
		second_to_last(stack_a, stack_b);
	else
		ft_ra(stack_a, 1);
	// Top needs to be pushed to stack_b
	// if (stack_a->top->sorted_position < pivot)
	// {
	// 	if (stack_a->top->next->value < stack_a->top->value)
	// 	{
	// 		if (stack_a->top->next->value < stack_a->bottom->value)
	// 		{
	// 			if (stack_b->size > 1
	// 				&& stack_b->top->next->value > stack_b->top->value)
	// 				ft_ss(stack_a, stack_b);
	// 			else
	// 				ft_sa(stack_a);
	// 		}
	// 	}
	// 	else if (stack_a->bottom->value < stack_a->top->value)
	// 	{
	// 		if (stack_b->size > 1
	// 			&& stack_b->bottom->value > stack_b->top->value)
	// 			ft_rrr(stack_a, stack_b, 1);
	// 		else
	// 			ft_rra(stack_a, 1);
	// 	}
	// 	ft_pb(stack_a, stack_b);
	// }
	// Get biggest to the top, then send at bottom
	// else
	// {
		// between top, next and bot, who should be the first at bottom ?
		// the lowest or biggest ? the lowest I believe.
		// if next should stay in stack_a, is next lower than bottom ?
		// if yes, exchange their position
		// if (stack_a->top->next->value < stack_a->top->value
		// 	&& stack_a->top->next->sorted_position >= pivot)
		// {
		// 	if (stack_b->size > 1
		// 		&& stack_b->top->next->value > stack_b->top->value)
		// 		ft_ss(stack_a, stack_b);
		// 	else
		// 		ft_sa(stack_a);
		// }
		// if top smaller than bot and bot >= pivot. put top above bottom
	// 	if (stack_a->bottom->sorted_position >= pivot
	// 		&& stack_a->bottom->value < stack_a->top->value)
	// 	{
	// 		if (stack_b->size > 1
	// 			&& stack_b->bottom->value > stack_b->top->value)
	// 			ft_rrr(stack_a, stack_b, 1);
	// 		else
	// 			ft_rra(stack_a, 1);
	// 		if (stack_b->size > 1
	// 			&& stack_b->top->next->value > stack_b->top->value)
	// 			ft_ss(stack_a, stack_b);
	// 		else
	// 			ft_sa(stack_a);
	// 	}
	// 	if (stack_b->size > 1
	// 		&& stack_b->top->value < stack_b->bottom->value)
	// 		ft_rr(stack_a, stack_b, 1);
	// 	else
	// 		ft_ra(stack_a, 1);
	// }
}
void	selection_sort(t_stack *stack_a, t_stack *stack_b)
{
	int	nb_plates;

	if (!stack_a || !stack_b)
		return (ft_putstr_fd("Error\n", 1));
	nb_plates = (int)(stack_a->size) + (int)(stack_b->size);
	ft_printf("stack_a->size = %u ; nb_plates = %i ; pivot = %i\n",
		stack_a->size, nb_plates, nb_plates / 2);
	while (stack_a->size > stack_b->size + 1)
	{
		push_beginning(stack_a, stack_b, nb_plates / 2);
		ft_printf("\nStack_a:\n");
		ft_print_stack(stack_a);
		ft_printf("\nStack_b:\n");
		ft_print_stack(stack_b);
		ft_printf("=======\n");
		sleep(1);
	}
}
