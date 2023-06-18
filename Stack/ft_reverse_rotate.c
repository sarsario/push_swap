/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_reverse_rotate.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: osarsari <osarsari@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/18 16:20:13 by osarsari          #+#    #+#             */
/*   Updated: 2023/06/18 16:25:41 by osarsari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

t_bool	ft_reverse_rotate(t_stack *stack)
{
	int	i;

	if (!stack || stack->size < 2)
		return (false);
	i = 0;
	while (++i < stack->size)
	{
		stack->numbers[i] ^= stack->numbers[i - 1];
		stack->numbers[i - 1] ^= stack->numbers[i];
		stack->numbers[i] ^= stack->numbers[i - 1];
	}
	return (true);
}

void	ft_rra(t_stack *stack_a, int nb)
{
	while (nb-- > 0)
	{
		if (ft_reverse_rotate(stack_a))
			ft_printf("rra\n");
	}
}

void	ft_rrb(t_stack *stack_b, int nb)
{
	while (nb-- > 0)
	{
		if (ft_reverse_rotate(stack_b))
			ft_printf("rrb\n");
	}
}

void	ft_rrr(t_stack *stack_a, t_stack *stack_b, int nb)
{
	t_bool	rra;
	t_bool	rrb;

	while (nb-- > 0)
	{
		rra = ft_reverse_rotate(stack_a);
		rrb = ft_reverse_rotate(stack_b);
		if (rra && rrb)
			ft_printf("rrr\n");
		else if (rra)
			ft_printf("rra\n");
		else if (rrb)
			ft_printf("rrb\n");
	}
}
