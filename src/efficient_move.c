/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   efficient_move.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: osarsari <osarsari@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/07 15:50:53 by osarsari          #+#    #+#             */
/*   Updated: 2023/08/07 15:57:47 by osarsari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int	can_rr(int ra, int rb, int rra, int rrb)
{
	if (ft_max(ra, rb) <= ft_max(rra, rrb)
		&& ft_max(ra, rb) <= (ft_min(ra, rra) + ft_min(rb, rrb)))
		return (1);
	return (0);
}

int	can_rrr(int ra, int rb, int rra, int rrb)
{
	if (ft_max(rra, rrb) <= ft_max(ra, rb)
		&& ft_max(rra, rrb) <= (ft_min(ra, rra) + ft_min(rb, rrb)))
		return (1);
	return (0);
}

void	exec_rr_pa(t_stack *a, t_stack *b, int ra, int rb)
{
	if (ra > rb)
	{
		ft_rr_n(a, b, rb);
		ft_ra_n(a, ra - rb);
	}
	else
	{
		ft_rr_n(a, b, ra);
		ft_rb_n(b, rb - ra);
	}
	ft_pa(a, b);
}

void	exec_rrr_pa(t_stack *a, t_stack *b, int rra, int rrb)
{
	if (rra > rrb)
	{
		ft_rrr_n(a, b, rrb);
		ft_rra_n(a, rra - rrb);
	}
	else
	{
		ft_rrr_n(a, b, rra);
		ft_rrb_n(b, rrb - rra);
	}
	ft_pa(a, b);
}

void	ft_best_rotate(t_stack *stack)
{
	int	top;
	int	r;
	int	rr;

	top = ft_min_value(stack);
	r = cost_rotate(stack, top);
	rr = cost_reverse_rotate(stack, top);
	if (r <= rr)
		ft_ra_n(stack, r);
	else
		ft_rra_n(stack, rr);
}
