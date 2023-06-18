/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   combined_logic.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: osarsari <osarsari@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/18 19:07:59 by osarsari          #+#    #+#             */
/*   Updated: 2023/06/18 19:48:38 by osarsari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	combined_r(t_stack *stack_a, t_stack *stack_b)
{
	int	m;
	int	n;

	m = stack_a->size - 1;
	n = stack_b->size - 1;
	if (get_biggest_int(stack_a) == stack_a->numbers[m]
		&& get_smallest_int(stack_b) == stack_b->numbers[n])
		return (ft_rr(stack_a, stack_b, 1));
	if (get_biggest_int(stack_a) == stack_a->numbers[m])
		return (ft_ra(stack_a, 1));
	if (get_smallest_int(stack_b) == stack_b->numbers[n])
		return (ft_rb(stack_b, 1));
}

void	combined_rr(t_stack *stack_a, t_stack *stack_b)
{
	int	m;
	int	n;

	m = stack_a->size - 1;
	n = stack_b->size - 1;
	if (get_biggest_int(stack_a) != stack_a->numbers[0]
		&& get_smallest_int(stack_b) != stack_b->numbers[0])
		return (ft_rrr(stack_a, stack_b, 1));
	if (get_biggest_int(stack_a) != stack_a->numbers[0])
		return (ft_rra(stack_a, 1));
	if (get_smallest_int(stack_b) != stack_b->numbers[0])
		return (ft_rrb(stack_b, 1));
}

void	combined_s(t_stack *stack_a, t_stack *stack_b)
{
	int	m;
	int	n;

	m = stack_a->size - 1;
	n = stack_b->size - 1;
	if (get_smallest_int(stack_a) != stack_a->numbers[m]
		&& get_biggest_int(stack_b) != stack_b->numbers[n])
		return (ft_ss(stack_a, stack_b));
	if (get_smallest_int(stack_a) != stack_a->numbers[m])
		return (ft_sa(stack_a));
	if (get_biggest_int(stack_b) != stack_b->numbers[n])
		return (ft_sb(stack_b));
}
