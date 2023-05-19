/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_plate.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: osarsari <osarsari@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/10 20:45:54 by osarsari          #+#    #+#             */
/*   Updated: 2023/05/19 12:03:44 by osarsari         ###   ########.fr       */
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
	new_plate->position = 0;
	new_plate->sorted_position = 0;
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
** Retrieves the biggest plate that is smaller than the plate in the stack.
**
** stack: Pointer to the stack.
** plate: Pointer to the reference plate.
**
** Returns:
** Pointer to the biggest plate in the stack which is smaller than the plate.
** Null if the stack is empty or could not find a smaller plate.
*/

t_plate	*get_smaller_plate(t_stack *stack, t_plate *plate)
{
	t_plate	*smaller;
	t_plate	*next;

	if (!stack || stack->size < 2)
		return (NULL);
	smaller = get_smallest_plate(stack);
	next = stack->top;
	while (next)
	{
		if (next->value < plate->value && next->value > smaller->value)
			smaller = next;
		next = next->next;
	}
	if (smaller == plate)
		return (NULL);
	return (smaller);
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

/*
** Retrieves the smallest plate in the stack that is bigger than plate.
**
** stack: Pointer to the stack.
** plate: Pointer to the reference plate.
**
** Returns:
** Pointer to the plate with the lowest value bigger than plate.
** NULL if plate is the biggest;
*/

t_plate	*get_bigger_plate(t_stack *stack, t_plate *plate)
{
	t_plate	*bigger;
	t_plate	*next;

	if (!stack || stack->size < 2)
		return (NULL);
	bigger = get_biggest_plate(stack);
	next = stack->top;
	while (next)
	{
		if (next->value > plate->value && next->value < bigger->value)
			bigger = next;
		next = next->next;
	}
	if (bigger == plate)
		return (NULL);
	return (bigger);
}
