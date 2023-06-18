/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_under_seven.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: osarsari <osarsari@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/18 16:34:10 by osarsari          #+#    #+#             */
/*   Updated: 2023/06/18 19:46:57 by osarsari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	sort_two(t_stack *stack)
{
	if (!stack)
		return (ft_putstr_fd("Error in sort_two.\n", 2));
	if (stack->size == 2 && stack->numbers[0] < stack->numbers[1])
		ft_sa(stack);
}

void	sort_three(t_stack *stack)
{
	if (!stack)
		return (ft_putstr_fd("Error in sort_three.\n", 2));
	if (stack->size < 3)
		return (sort_two(stack));
	if (stack->numbers[2] > stack->numbers[1]
		&& stack->numbers[2] > stack->numbers[0])
		ft_ra(stack, 1);
	if (stack->numbers[0] < stack->numbers[1]
		|| stack->numbers[0] < stack->numbers[2])
		ft_rra(stack, 1);
	if (stack->numbers[2] > stack->numbers[1])
		ft_sa(stack);
}

void	sort_six(t_stack *stack_a, t_stack *stack_b)
{
	combined_r(stack_a, stack_b);
	combined_rr(stack_a, stack_b);
	combined_s(stack_a, stack_b);
}

void	sort_under_seven(t_stack *stack_a, t_stack *stack_b)
{
	int	pivot;
	int	i;

	if (stack_a->size > 4)
		i = stack_a->size / 2;
	else
		i = 1;
	pivot = get_smallest_int(stack_a);
	while (--i)
		pivot = get_bigger_int(stack_a, pivot);
	while (stack_a->size > 3)
	{
		if (stack_a->numbers[stack_a->size - 1] > pivot)
			ft_ra(stack_a, 1);
		else
			ft_pb(stack_a, stack_b);
	}
	if (stack_b->size > 1)
		sort_six(stack_a, stack_b);
	while (stack_b->size > 0)
		ft_pa(stack_a, stack_b);
}
