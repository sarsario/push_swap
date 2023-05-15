/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_plate.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: osarsari <osarsari@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/10 20:45:54 by osarsari          #+#    #+#             */
/*   Updated: 2023/05/15 19:13:15 by osarsari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*
** Allocates (with malloc(3)) and returns a new plate with the given value and
** next plate pointer. The previous plate pointer is always initialized to NULL
** as new plates are always placed at the top of a stack.
**
** next: The next plate pointer.
** value: The value to store in the new plate.
**
** Returns:
** The new plate if successful, NULL otherwise.
*/

t_plate	*ft_plate_new(t_plate *next, int value)
{
	t_plate	*new_plate;

	new_plate = malloc(sizeof(t_plate));
	if (!new_plate)
		return (NULL);
	new_plate->prev = NULL;
	if (!next)
		new_plate->next = NULL;
	else
		new_plate->next = next;
	new_plate->value = value;
	return (new_plate);
}

/*
** Retrieves the plate with the smallest value from the given stack.
**
** stack: Pointer to the stack.
**
** Returns:
** Pointer to the plate with the smallest value, or NULL if the stack is empty.
*/

t_plate	*get_smallest_plate(t_stack *stack)
{
	t_plate	*smallest;
	t_plate	*next;

	if (!stack || stack->size < 1)
		return (NULL);
	smallest = stack->top;
	if (stack->size < 2)
		return (smallest);
	next = smallest->next;
	while (next)
	{
		if (smallest->value > next->value)
			smallest = next;
		next = next->next;
	}
	return (smallest);
}

/*
** Retrieves the plate with the biggest value from the given stack.
**
** stack: Pointer to the stack.
**
** Returns:
** Pointer to the plate with the biggest value, or NULL if the stack is empty.
*/

t_plate	*get_biggest_plate(t_stack *stack)
{
	t_plate	*biggest;
	t_plate	*next;

	if (!stack || stack->size < 1)
		return (NULL);
	biggest = stack->top;
	if (stack->size < 2)
		return (biggest);
	next = biggest->next;
	while (next)
	{
		if (biggest->value < next->value)
			biggest = next;
		next = next->next;
	}
	return (biggest);
}
