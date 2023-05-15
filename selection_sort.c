/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   selection_sort.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: osarsari <osarsari@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/15 18:55:12 by osarsari          #+#    #+#             */
/*   Updated: 2023/05/15 20:23:19 by osarsari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	selection_sort(t_stack *stack_a, t_stack *stack_b)
{
	t_plate	*smallest;
	t_plate *biggest;

	if (!stack_a || !stack_b)
		return ft_putstr_fd("Error\n", 1);
	smallest = get_smallest_plate(stack_a);
	biggest = get_biggest_plate(stack_a);
	while (!stack_is_asc(stack_a) || stack_b->size > 0)
	{
		// int avg = biggest->value + smallest->value;
		// avg = avg / 2;
		// ft_printf("top = %i\nbiggest + smallest / 2 = %i + %i / 2 = %i\n",
		// 	stack_a->top->value, biggest->value, smallest->value, avg);
		sleep(1);
		if (stack_is_asc(stack_a) && stack_b->size > 0 && stack_is_dsc(stack_b))
		{
			ft_push_stack(stack_b, stack_a);
			ft_printf("pa\n");
		}
		else if (stack_is_asc(stack_a) && stack_b->size > 0)
		{
			while (get_biggest_plate(stack_b) != stack_b->top)
			{
				ft_rotate(stack_b);
				ft_printf("rb\n");
			}
			ft_push_stack(stack_b, stack_a);
			ft_printf("pa\n");
		}
		else if (stack_a->top->value > (biggest->value + smallest->value) / 2)
		{
			ft_rotate(stack_a);
			ft_printf("ra\n");
		}
		else
		{
			ft_push_stack(stack_a, stack_b);
			ft_printf("pb\n");
		}
	}
}
