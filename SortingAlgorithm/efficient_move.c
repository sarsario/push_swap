/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   efficient_move.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: osarsari <osarsari@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/19 12:55:03 by osarsari          #+#    #+#             */
/*   Updated: 2023/06/19 13:56:22 by osarsari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

t_bool	int_in_stack(int n, t_stack *stack)
{
	int	i;

	i = stack->size;
	while (i--)
	{
		if (n == stack->numbers[i])
			return (true);
	}
	return (false);
}

void	rotate_top(t_stack *stack, int n, char c)
{
	int	r;
	int	rr;

	r = cost_rotate(stack, n);
	rr = cost_reverse_rotate(stack, n);
	if (r > rr)
	{
		if (c == 'a')
			return (ft_rra(stack, rr));
		return (ft_rrb(stack, rr));
	}
	if (c == 'a')
		return (ft_ra(stack, r));
	return (ft_rb(stack, r));
}

void	efficient_pb(t_stack *stack_a, t_stack *stack_b, t_stack *lis)
{
	int	ra;
	int	rra;
	int	i;

	ra = 0;
	i = stack_a->size - 1;
	while (int_in_stack(stack_a->numbers[i - ra], lis))
		ra++;
	rra = 1;
	i = 0;
	while (int_in_stack(stack_a->numbers[i], lis))
	{
		i++;
		rra++;
	}
	if (ra > rra)
		ft_rra(stack_a, rra);
	else
		ft_ra(stack_a, ra);
	ft_pb(stack_a, stack_b);
}

void	efficient_pa(t_stack *stack_a, t_stack *stack_b, int to_push)
{
	int	ra;
	int	rb;
	int	rra;
	int	rrb;
	int	to_top;
}
