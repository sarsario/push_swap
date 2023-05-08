/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_stack.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: osarsari <osarsari@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/06 23:33:27 by osarsari          #+#    #+#             */
/*   Updated: 2023/05/09 00:15:12 by osarsari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_bool	ft_pop(t_stack *stack_a, int *value)
{
	t_plate	*plate_to_remove;

	if (!stack_a->top)
		return (false);
	*value = stack_a->top->value;
	plate_to_remove = stack_a->top;
	stack_a->top = plate_to_remove->next;
	if (stack_a->top)
		stack_a->top->prev = NULL;
	else
		stack_a->bottom = NULL;
	free(plate_to_remove);
	stack_a->size--;
	return (true);
}

t_stack	*pile_stack(int argc, char **argv)
{
	t_stack	*stack_a;
	int		i;

	stack_a = malloc(sizeof(t_stack));
	if (!stack_a)
		return (NULL);
	i = argc;
	stack_a->size = 0;
	while (--i > 0)
	{
		if (!ft_push(stack_a, ft_atoi(argv[i])))
		{
			while (ft_pop(stack_a, &(int){0}))
				;
			free(stack_a);
			return (NULL);
		}
	}
	return (stack_a);
}
