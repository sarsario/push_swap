/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_push.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: osarsari <osarsari@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/06 18:28:52 by osarsari          #+#    #+#             */
/*   Updated: 2023/05/17 16:30:18 by osarsari         ###   ########.fr       */
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
		stack->bottom = new_plate;
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
		src->bottom = NULL;
	src->size--;
	if (dst->size > 0)
		dst->top->prev = top;
	else
		dst->bottom = top;
	if (dst->size > 0)
		top->next = dst->top;
	else
		top->next = NULL;
	dst->top = top;
	dst->size++;
	return (true);
}

/*
** Attempts to push the top plate of src stack to the top of dst stack.
** If the move is successfull, print the move's name and update the
** positions of the plates in both stacks.
**
** src:		The source stack to pop from.
** dst:		The destination stack to push to.
** name:	The character identifiying the operation.
*/

void	run_push_stack(t_stack *src, t_stack *dst, char name)
{
	t_plate	*plate;
	int		i;

	if (ft_push_stack(src, dst))
	{
		ft_printf("p%c\n", name);
		plate = src->top;
		i = 0;
		while (plate)
		{
			plate->position = i++;
			plate = plate->next;
		}
		plate = dst->top;
		i = 0;
		while (plate)
		{
			plate->position = i++;
			plate = plate->next;
		}
	}
}

void	run_cheapest_push(t_stack *src, t_stack *dst, t_plate *plate)
{
	int		dist_from_top;
	int		dist_from_bot;

	if (!src || !dst || !plate)
		return ;
	dist_from_top = distance_top(src, plate);
	dist_from_bot = distance_bot(src, plate);
	if (dist_from_top == -1 || dist_from_bot == -1)
		return ;
	if (dist_from_bot > dist_from_top)
		repeat_rotate(src, dist_from_top, 'a');
}
