/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_push_pivot.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: osarsari <osarsari@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/02 10:56:30 by osarsari          #+#    #+#             */
/*   Updated: 2023/08/07 10:57:55 by osarsari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int	ft_cost_ra_pivot(t_stack *stack, int pivot)
{
	int	i;
	int	cost;

	i = stack->size;
	cost = 0;
	while (i > 0)
	{
		i--;
		if (stack->stack[i] < pivot)
			return (cost);
		cost++;
	}
	return (cost);
}

int	ft_cost_rra_pivot(t_stack *stack, int pivot)
{
	int	i;
	int	cost;

	i = -1;
	cost = 0;
	while (++i < stack->size && ++cost)
		if (stack->stack[i] < pivot)
			return (cost);
	return (cost);
}

void	ft_pb_pivot(t_stack *a, t_stack *b, int pivot)
{
	int	best_ra;
	int	best_rra;

	best_ra = ft_cost_ra_pivot(a, pivot);
	best_rra = ft_cost_rra_pivot(a, pivot);
	if (best_ra <= best_rra)
		while (best_ra--)
			ft_ra(a);
	else
		while (best_rra--)
			ft_rra(a);
	if (ft_is_sorted(a) && ft_min_value(a) > ft_max_value(b))
		return ;
	ft_pb(a, b);
}
