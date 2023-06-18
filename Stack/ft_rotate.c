/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rotate.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: osarsari <osarsari@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/18 16:09:04 by osarsari          #+#    #+#             */
/*   Updated: 2023/06/18 20:13:33 by osarsari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

t_bool	ft_rotate(t_stack *stack)
{
	int	i;

	if (!stack || stack->size < 2)
		return (false);
	i = stack->size;
	while (i-- > 1)
	{
		stack->numbers[i] ^= stack->numbers[i - 1];
		stack->numbers[i - 1] ^= stack->numbers[i];
		stack->numbers[i] ^= stack->numbers[i - 1];
	}
	return (true);
}

void	ft_ra(t_stack *stack, int nb)
{
	while (nb-- > 0)
	{
		if (ft_rotate(stack))
			ft_printf("ra\n");
	}
}

void	ft_rb(t_stack *stack, int nb)
{
	while (nb-- > 0)
	{
		if (ft_rotate(stack))
			ft_printf("rb\n");
	}
}

void	ft_rr(t_stack *stack_a, t_stack *stack_b, int nb)
{
	t_bool	ra;
	t_bool	rb;

	while (nb-- > 0)
	{
		ra = ft_rotate(stack_a);
		rb = ft_rotate(stack_b);
		if (ra && rb)
			ft_printf("rr\n");
		else if (ra)
			ft_printf("ra\n");
		else if (rb)
			ft_printf("rb\n");
	}
}
