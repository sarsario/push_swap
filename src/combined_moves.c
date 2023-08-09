/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   combined_moves.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: osarsari <osarsari@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/02 11:19:23 by osarsari          #+#    #+#             */
/*   Updated: 2023/08/07 16:05:38 by osarsari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	combined_r(t_stack *a, t_stack *b)
{
	int	m;
	int	n;

	m = a->size - 1;
	n = b->size - 1;
	if (ft_max_value(a) == a->stack[m] && ft_min_value(b) == b->stack[n])
		return (ft_rr(a, b));
	if (ft_max_value(a) == a->stack[m])
		return (ft_ra(a));
	if (ft_min_value(b) == b->stack[n])
		return (ft_rb(b));
}

void	combined_rr(t_stack *a, t_stack *b)
{
	if (ft_max_value(a) != a->stack[0] && ft_min_value(b) != b->stack[0])
		return (ft_rrr(a, b));
	if (ft_max_value(a) != a->stack[0])
		return (ft_rra(a));
	if (ft_min_value(b) != b->stack[0])
		return (ft_rrb(b));
}

void	combined_s(t_stack *a, t_stack *b)
{
	int	m;
	int	n;

	m = a->size - 1;
	n = b->size - 1;
	if (ft_min_value(a) != a->stack[m] && ft_max_value(b) != b->stack[n])
		return (ft_ss(a, b));
	if (ft_min_value(a) != a->stack[m])
		return (ft_sa(a));
	if (ft_max_value(b) != b->stack[n])
		return (ft_sb(b));
}

int	get_smallest_bigger(t_stack *stack, int n)
{
	int	res;

	res = ft_min_value(stack);
	if (n < res || n > ft_max_value(stack))
		return (res);
	while (res < n)
		res = ft_bigger_value(stack, res);
	return (res);
}
