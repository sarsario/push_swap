/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   efficient_move2.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: osarsari <osarsari@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/19 17:21:19 by osarsari          #+#    #+#             */
/*   Updated: 2023/06/19 17:33:11 by osarsari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

t_bool	can_rr(int ra, int rb, int rra, int rrb)
{
	if (ft_max(ra, rb) <= ft_max(rra, rrb)
		&& ft_max(ra, rb) <= (ft_min(ra, rra) + ft_min(rb, rrb)))
		return (true);
	return (false);
}

t_bool	can_rrr(int ra, int rb, int rra, int rrb)
{
	if (ft_max(rra, rrb) <= ft_max(ra, rb)
		&& ft_max(rra, rrb) <= (ft_min(ra, rra) + ft_min(rb, rrb)))
		return (true);
	return (false);
}

void	exec_rr_pa(t_stack *stack_a, t_stack *stack_b, int ra, int rb)
{
	if (ra > rb)
	{
		ft_rr(stack_a, stack_b, rb);
		ft_ra(stack_a, ra - rb);
	}
	else
	{
		ft_rr(stack_a, stack_b, ra);
		ft_rb(stack_b, rb - ra);
	}
	ft_pa(stack_a, stack_b);
}

void	exec_rrr_pa(t_stack *stack_a, t_stack *stack_b, int rra, int rrb)
{
	if (rra > rrb)
	{
		ft_rrr(stack_a, stack_b, rrb);
		ft_rra(stack_a, rra - rrb);
	}
	else
	{
		ft_rrr(stack_a, stack_b, rra);
		ft_rrb(stack_b, rrb - rra);
	}
	ft_pa(stack_a, stack_b);
}
