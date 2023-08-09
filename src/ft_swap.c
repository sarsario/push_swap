/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_swap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: osarsari <osarsari@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/02 10:07:33 by osarsari          #+#    #+#             */
/*   Updated: 2023/08/02 10:12:34 by osarsari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int	ft_swap(t_stack *stack)
{
	if (!stack || !stack->stack || stack->size < 2)
		return (0);
	stack->stack[stack->size - 1] ^= stack->stack[stack->size -2];
	stack->stack[stack->size - 2] ^= stack->stack[stack->size -1];
	stack->stack[stack->size - 1] ^= stack->stack[stack->size -2];
	return (1);
}

void	ft_sa(t_stack *a)
{
	if (ft_swap(a))
		ft_printf("sa\n");
}

void	ft_sb(t_stack *b)
{
	if (ft_swap(b))
		ft_printf("sb\n");
}

void	ft_ss(t_stack *a, t_stack *b)
{
	int		sa;
	int		sb;

	sa = ft_swap(a);
	sb = ft_swap(b);
	if (sa && sb)
		ft_printf("ss\n");
	else if (sa)
		ft_printf("sa\n");
	else if (sb)
		ft_printf("sb\n");
	else
		ft_putstr_fd("Error\nCould not perform any swap.\n", 2);
}
