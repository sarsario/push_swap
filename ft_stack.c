/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_stack.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: osarsari <osarsari@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/06 23:33:27 by osarsari          #+#    #+#             */
/*   Updated: 2023/05/09 12:37:10 by osarsari         ###   ########.fr       */
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

	if (!stack->top)
		return (false);
	*value = stack->top->value;
	plate_to_remove = stack->top;
	stack->top = plate_to_remove->next;
	if (stack->top)
		stack->top->prev = NULL;
	else
		stack->bottom = NULL;
	free(plate_to_remove);
	stack->size--;
	return (true);
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

t_stack	*pile_stack(int argc, char **argv)
{
	t_stack	*stack;
	int		i;

	stack = malloc(sizeof(t_stack));
	if (!stack)
		return (NULL);
	i = argc;
	stack->size = 0;
	while (--i > 0)
	{
		if (!ft_push(stack, ft_atoi(argv[i])))
		{
			while (ft_pop(stack, &(int){0}))
				;
			free(stack);
			return (NULL);
		}
	}
	return (stack);
}
