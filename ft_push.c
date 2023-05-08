/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_push.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: osarsari <osarsari@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/06 18:28:52 by osarsari          #+#    #+#             */
/*   Updated: 2023/05/08 23:53:01 by osarsari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_bool	ft_push(t_stack *stack_a, int value)
{
	t_plate	*new_plate;

	new_plate = malloc(sizeof(t_plate));
	if (!new_plate)
		return (false);
	new_plate->value = value;
	new_plate->prev = NULL;
	new_plate->next = stack_a->top;
	if (stack_a->top)
		stack_a->top->prev = new_plate;
	else
		stack_a->bottom = new_plate;
	stack_a->top = new_plate;
	stack_a->size++;
	return (true);
}

t_bool	ft_push_from_to(t_stack *stack_a, t_stack *stack_b)
{
	int	value;

	if (!stack_a->bottom)
		return(true);
	value = 0;
	if (!ft_pop(stack_a, &value))
		return (false);
	if (!ft_push(stack_b, value))
		return (false);
	return (true);
}
