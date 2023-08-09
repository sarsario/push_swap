/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_reverse_rotate.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: osarsari <osarsari@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/02 10:16:23 by osarsari          #+#    #+#             */
/*   Updated: 2023/08/02 10:18:01 by osarsari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int	ft_reverse_rotate(t_stack *stack)
{
	int	i;

	if (!stack || !stack->stack || stack->size < 2)
		return (0);
	i = 0;
	while (++i < stack->size)
	{
		stack->stack[i] ^= stack->stack[i - 1];
		stack->stack[i - 1] ^= stack->stack[i];
		stack->stack[i] ^= stack->stack[i - 1];
	}
	return (1);
}

void	ft_rra(t_stack *a)
{
	if (ft_reverse_rotate(a))
		ft_printf("rra\n");
}

void	ft_rrb(t_stack *b)
{
	if (ft_reverse_rotate(b))
		ft_printf("rrb\n");
}

void	ft_rrr(t_stack *a, t_stack *b)
{
	int		rra;
	int		rrb;

	rra = ft_reverse_rotate(a);
	rrb = ft_reverse_rotate(b);
	if (rra && rrb)
		ft_printf("rrr\n");
	else if (rra)
		ft_printf("rra\n");
	else if (rrb)
		ft_printf("rrb\n");
	else
		ft_putstr_fd("Error\nCould not perform any reverse rotation.\n", 2);
}
