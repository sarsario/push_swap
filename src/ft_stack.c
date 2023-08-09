/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_stack.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: osarsari <osarsari@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/25 12:12:16 by osarsari          #+#    #+#             */
/*   Updated: 2023/08/02 09:59:25 by osarsari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int	ft_stack_new(t_stack *stack, int size)
{
	stack->stack = ft_calloc(size, sizeof(int));
	if (!stack->stack)
		return (0);
	stack->size = 0;
	return (1);
}

static void	ft_fill_stack(t_stack *stack, char **args, int len)
{
	int	i;

	i = 0;
	while (len--)
	{
		stack->stack[i] = ft_atoi(args[len]);
		stack->size++;
		i++;
	}
}

int	ft_init_stack(t_stack *stack, int argc, char **argv)
{
	char	**args;
	int		args_len;

	args = ft_sanitize(argc, argv);
	if (!args)
		return (0);
	args_len = ft_array_len(args);
	if (!ft_stack_new(stack, args_len))
		return (ft_free_args(args, 0));
	if (!ft_valid_args(args))
	{
		free(stack->stack);
		return (ft_free_args(args, 0));
	}
	ft_fill_stack(stack, args, args_len);
	return (ft_free_args(args, stack->size));
}
