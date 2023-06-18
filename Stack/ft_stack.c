/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_stack.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: osarsari <osarsari@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/18 15:18:35 by osarsari          #+#    #+#             */
/*   Updated: 2023/06/18 20:20:38 by osarsari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

t_stack	*ft_stack_new(int argc)
{
	t_stack	*new_stack;

	new_stack = malloc(sizeof(t_stack));
	if (!new_stack)
		return (NULL);
	new_stack->numbers = malloc(sizeof(int) * (argc - 1));
	if (!new_stack->numbers)
	{
		free(new_stack);
		return (NULL);
	}
	new_stack->size = 0;
	return (new_stack);
}

t_stack	*fill_stack(int argc, char **argv)
{
	t_stack	*stack;

	stack = ft_stack_new(argc);
	if (!stack)
		return (NULL);
	while (--argc > 0)
		ft_push(stack, ft_atoi(argv[argc]));
	return (stack);
}

void	free_stack(t_stack *stack)
{
	if (stack && stack->numbers)
		free(stack->numbers);
	if (stack)
		free(stack);
}
