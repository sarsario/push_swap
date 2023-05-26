/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_stack.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: osarsari <osarsari@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/25 19:29:09 by osarsari          #+#    #+#             */
/*   Updated: 2023/05/25 19:31:18 by osarsari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_print_stack(t_stack *stack)
{
	t_plate	*current;

	if (!stack)
		return (ft_putstr_fd("stack doesn't exist\n", 1));
	if (stack->size < 1)
		return (ft_putstr_fd("Empty stack.\n", 1));
	current = stack->top;
	while (current)
	{
		ft_printf("value = %i ; pos = %i ; sorted_pos = %i\n", current->value,
			current->position, current->sorted_position);
		current = current->next;
	}
}

void	ft_print_stacks(t_stack *stack_a, t_stack *stack_b)
{
	ft_printf("\nStack_a:\n");
	ft_print_stack(stack_a);
	ft_printf("\nStack_b:\n");
	ft_print_stack(stack_b);
	ft_printf("=======\n");
}
