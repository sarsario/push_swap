/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_push.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: osarsari <osarsari@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/06 18:28:52 by osarsari          #+#    #+#             */
/*   Updated: 2023/05/09 12:27:25 by osarsari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*
** Pushes a new plate with the given value onto the top of the stack.
**
** stack: The stack to push the new plate onto.
** value: The value to be assigned to the new plate.
**
** Returns:
** true if the push was successful, false otherwise (in case of
** memory allocation failure).
*/

t_bool	ft_push(t_stack *stack, int value)
{
	t_plate	*new_plate;

	new_plate = malloc(sizeof(t_plate));
	if (!new_plate)
		return (false);
	new_plate->value = value;
	new_plate->prev = NULL;
	new_plate->next = stack->top;
	if (stack->top)
		stack->top->prev = new_plate;
	else
		stack->bottom = new_plate;
	stack->top = new_plate;
	stack->size++;
	return (true);
}

/*
** Move the top plate of a source stack to the top of a destination stack.
**
** src: The source stack.
** dst: The destination stack.
**
** Returns:
** true if the move was successful, false otherwise.
*/

t_bool	ft_move(t_stack *src, t_stack *dst)
{
	t_plate	*top;

	if (src->size < 1)
		return (false);
	top = src->top;
	src->top = top->next;
	src->top->prev = NULL;
	src->size--;
	top->next = dst->top;
	top->prev = NULL;
	if (dst->size == 0)
		dst->bottom = top;
	else
		dst->top->prev = top;
	dst->top = top;
	dst->size++;
	return (true);
}
