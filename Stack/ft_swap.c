/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_swap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: osarsari <osarsari@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/18 15:55:00 by osarsari          #+#    #+#             */
/*   Updated: 2023/06/18 16:06:29 by osarsari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

t_bool	ft_swap(t_stack *stack)
{
	if (!stack || stack->size < 2)
		return (false);
	stack->numbers[stack->size - 1] ^= stack->numbers[stack->size - 2];
	stack->numbers[stack->size - 2] ^= stack->numbers[stack->size - 1];
	stack->numbers[stack->size - 1] ^= stack->numbers[stack->size - 2];
	return (true);
}

void	ft_sa(t_stack *stack)
{
	if (ft_swap(stack))
		ft_printf("sa\n");
}

void	ft_sb(t_stack *stack)
{
	if (ft_swap(stack))
		ft_printf("sb\n");
}

void	ft_ss(t_stack *stack_a, t_stack *stack_b)
{
	t_bool	sa;
	t_bool	sb;

	sa = ft_swap(stack_a);
	sb = ft_swap(stack_b);
	if (sa && sb)
		return (ft_putstr_fd("ss\n", 1));
	if (sa)
		return (ft_putstr_fd("sa\n", 1));
	if (sb)
		return (ft_putstr_fd("sb\n", 1));
	ft_putstr_fd("Could not ss.\n", 2);
}
