/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   selection_sort.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: osarsari <osarsari@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/15 18:55:12 by osarsari          #+#    #+#             */
/*   Updated: 2023/05/23 15:37:24 by osarsari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// void	smallest_to_top(t_stack *stack_a, t_stack *stack_b, int pivot)
// {
// 	if (!stack_a || !stack_b)
// 		return ;
// 	if (stack_a->bottom->sorted_position < pivot
// 		&& stack_a->top->sorted_position > stack_a->bottom->sorted_position)
// 		try_rrr_before_rra(stack_a, stack_b, 1);
// 	if (stack_a->size > 1
// 		&& stack_a->top->sorted_position > stack_a->top->next->sorted_position)
// 		try_ss_before_sa(stack_a, stack_b);
// }

// void	second_to_last(t_stack *stack_a, t_stack *stack_b)
// {
// 	if (!stack_a || !stack_b)
// 		return ;
// 	if (stack_b->size > 1
// 		&& stack_b->bottom->sorted_position > stack_b->top->sorted_position)
// 		ft_rrr(stack_a, stack_b, 1);
// 	else
// 		ft_rra(stack_a, 1);
// 	if (stack_b->size > 1
// 		&& stack_b->top->sorted_position < stack_b->top->next->sorted_position)
// 		ft_ss(stack_a, stack_b);
// 	else
// 		ft_sa(stack_a);
// 	if (stack_b->size > 1
// 		&& stack_b->top->sorted_position < stack_b->bottom->sorted_position)
// 		ft_rr(stack_a, stack_b, 1);
// 	else
// 		ft_ra(stack_a, 1);
// 	ft_ra(stack_a, 1);
// }

void	divide_conquer(t_stack *stack_a, t_stack *stack_b, int pivot)
{
	if (!stack_a || !stack_b)
		return ;
	pre_sort_pb(stack_a, stack_b, pivot);
	// smallest_to_top(stack_a, stack_b, pivot);
	// if (stack_a->top->sorted_position < pivot)
	// {
	// 	if (stack_b->size > 1
	// 		&& stack_b->top->value < stack_b->bottom->value)
	// 		try_rr_before_rb(stack_a, stack_b, 1);
	// 	else if (stack_b->size > 1
	// 		&& stack_b->top->value < stack_b->top->next->value)
	// 		try_ss_before_sb(stack_a, stack_b);
	// 	return (ft_pb(stack_a, stack_b));
	// }
	// else if (stack_a->top->sorted_position < stack_a->bottom->sorted_position)
	// 	pre_sort_pb(stack_a, stack_b, pivot);
	// else
	// 	ft_ra(stack_a, 1);
}
// Compare "pos" stack_b to "pos" stack_a and return cheapest push cost
// int	best_pos_push(t_stack *stack_a, t_stack *stack_b)
// {
// 	int		nb_ra;
// 	int		nb_rra;
// 	int		nb_rb;
// 	int		nb_rrb;
// 	t_plate	*plate_a;
// 	t_plate	*plate_b;

// 	if (!stack_a || !stack_b)
// 		return (-1);
// 	plate_a = stack_a->top;
// 	plate_b = stack_b->top;
// 	while (plate_a->sorted_position != (plate_b->sorted_position + 1))
// 	{
// 		nb_ra = distance_top_rotate(stack_a, plate_a);
// 		nb_rra = distance_top_reverse_rotate(stack_a, plate_a);
// 		plate_a = plate_a->next;
// 	}
// }

void	selection_sort(t_stack *stack_a, t_stack *stack_b)
{
	int	nb_plates;

	if (!stack_a || !stack_b)
		return (ft_putstr_fd("Error\n", 1));
	nb_plates = (int)(stack_a->size) + (int)(stack_b->size);
	ft_printf("stack_a->size = %u ; nb_plates = %i ; pivot = %i\n",
		stack_a->size, nb_plates, nb_plates / 2);
	ft_print_stacks(stack_a, stack_b);
	sleep(10);
	while (stack_a->size > stack_b->size + 1)
	{
		divide_conquer(stack_a, stack_b, nb_plates / 2);
		ft_print_stacks(stack_a, stack_b);
	}
}
