/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_stack.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: osarsari <osarsari@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/06 23:33:27 by osarsari          #+#    #+#             */
/*   Updated: 2023/05/17 14:58:16 by osarsari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*
** Remove the top plate from the given stack and return its value.
**
** stack: The stack to pop from.
** value: A pointer to the variable where the popped value will be stored.
**
** Returns:
** true if the pop was successful, false otherwise (e.g. if the stack is empty).
*/

t_bool	ft_pop(t_stack *stack, int *value)
{
	t_plate	*plate_to_remove;

	if (!stack || stack->size < 1)
		return (false);
	*value = stack->top->value;
	plate_to_remove = stack->top;
	if (stack->size > 1)
		stack->top = plate_to_remove->next;
	else
		stack->top = NULL;
	if (stack->size > 1)
		stack->top->prev = NULL;
	else
		stack->bottom = NULL;
	stack->size--;
	free(plate_to_remove);
	return (true);
}

/*
** Allocates (with malloc(3)) and returns a new stack with empty top and bottom
** plates. The size is initialized to 0.
**
** Returns:
** The new stack or NULL if the allocation fails.
*/

t_stack	*ft_stack_new(void)
{
	t_stack	*new_stack;

	new_stack = malloc(sizeof(t_stack));
	if (!new_stack)
		return (NULL);
	new_stack->top = NULL;
	new_stack->bottom = NULL;
	new_stack->size = 0;
	return (new_stack);
}

/*
** Create a stack with plates initialized with values from the given arguments.
** The first argument is ignored.
**
** argc: The number of arguments.
** argv: The arguments array.
**
** Returns:
** A pointer to the new stack if successful, NULL otherwise.
*/

t_stack	*fill_stack(int argc, char **argv)
{
	t_stack	*stack;

	stack = ft_stack_new();
	if (!stack)
		return (NULL);
	while (--argc > 0)
	{
		if (!ft_push(stack, ft_atoi(argv[argc])))
		{
			while (ft_pop(stack, &(int){0}))
				;
			free(stack);
			return (NULL);
		}
	}
	return (stack);
}
