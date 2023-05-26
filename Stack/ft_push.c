/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_push.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: osarsari <osarsari@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/25 14:00:02 by osarsari          #+#    #+#             */
/*   Updated: 2023/05/25 18:09:59 by osarsari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

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
	t_plate	*next_plate;

	if (!stack)
		return (false);
	if (stack->size > 0)
		next_plate = stack->top;
	else
		next_plate = NULL;
	new_plate = ft_plate_new(next_plate, value);
	if (!new_plate)
		return (false);
	if (stack->size > 0)
		stack->top->prev = new_plate;
	else
		stack->bot = new_plate;
	stack->top = new_plate;
	stack->size++;
	return (true);
}

/*
** Moves the top plate from the `src` stack to the top of the `dst` stack.
**
** src: The source stack to pop from.
** dst: The destination stack to push to.
**
** Returns:
** true if the push was successful, false otherwise
** (e.g. if the source stack is empty).
*/

t_bool	ft_push_stack(t_stack *src, t_stack *dst)
{
	t_plate	*top;

	if (!src || !dst || src->size < 1)
		return (false);
	top = src->top;
	if (src->size > 1)
		src->top = top->next;
	else
		src->top = NULL;
	if (src->size > 1)
		src->top->prev = NULL;
	else
		src->bot = NULL;
	src->size--;
	if (dst->size > 0)
		dst->top->prev = top;
	else
		dst->bot = top;
	if (dst->size > 0)
		top->next = dst->top;
	else
		top->next = NULL;
	dst->top = top;
	dst->size++;
	return (true);
}

void	ft_pa(t_stack *stack_a, t_stack *stack_b)
{
	if (!ft_push_stack(stack_b, stack_a))
		return ;
	ft_printf("pa\n");
	update_position(stack_a);
	update_position(stack_b);
}

void	ft_pb(t_stack *stack_a, t_stack *stack_b)
{
	if (!ft_push_stack(stack_a, stack_b))
		return ;
	ft_printf("pb\n");
	update_position(stack_a);
	update_position(stack_b);
}
