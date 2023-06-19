/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   efficient_move.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: osarsari <osarsari@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/19 12:55:03 by osarsari          #+#    #+#             */
/*   Updated: 2023/06/19 17:30:27 by osarsari         ###   ########.fr       */
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

	to_top = get_smallest_bigger(stack_a, to_push);
	ra = cost_rotate(stack_a, to_top);
	rb = cost_rotate(stack_b, to_push);
	rra = cost_reverse_rotate(stack_a, to_top);
	rrb = cost_reverse_rotate(stack_b, to_push);
	if (can_rr(ra, rb, rra, rrb))
		return (exec_rr_pa(stack_a, stack_b, ra, rb));
	if (can_rrr(ra, rb, rra, rrb))
		return (exec_rrr_pa(stack_a, stack_b, rra, rrb));
	if (ra > rra)
		ft_rra(stack_a, rra);
	else
		ft_ra(stack_a, ra);
	if (rb > rrb)
		ft_rrb(stack_b, rrb);
	else
		ft_rb(stack_b, rb);
	ft_pa(stack_a, stack_b);
}
