/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rotate.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: osarsari <osarsari@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/02 10:13:08 by osarsari          #+#    #+#             */
/*   Updated: 2023/08/09 16:23:02 by osarsari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int	ft_rotate(t_stack *stack)
{
	int		i;

	if (!stack || !stack->stack || stack->size < 2)
		return (0);
	i = stack->size;
	while (--i > 0)
	{
		stack->stack[i] ^= stack->stack[i - 1];
		stack->stack[i - 1] ^= stack->stack[i];
		stack->stack[i] ^= stack->stack[i - 1];
	}
	return (1);
}

void	ft_ra(t_stack *a)
{
	if (a->size < 2 || ft_rotate(a))
		ft_printf("ra\n");
}

void	ft_rb(t_stack *b)
{
	if (b->size < 2 || ft_rotate(b))
		ft_printf("rb\n");
}

void	ft_rr(t_stack *a, t_stack *b)
{
	int		ra;
	int		rb;

	ra = ft_rotate(a);
	rb = ft_rotate(b);
	if (ra && rb)
		ft_printf("rr\n");
	else if (ra)
		ft_printf("ra\n");
	else if (rb)
		ft_printf("rb\n");
}
