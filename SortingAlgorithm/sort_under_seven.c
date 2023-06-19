/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_under_seven.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: osarsari <osarsari@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/18 16:34:10 by osarsari          #+#    #+#             */
/*   Updated: 2023/06/19 19:51:45 by osarsari         ###   ########.fr       */
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

void	best_pb_size_five(t_stack *stack_a, int smallest)
{
	int	second_smallest;
	int	ra1;
	int	ra2;
	int	rra1;
	int	rra2;

	second_smallest = get_bigger_int(stack_a, smallest);
	ra1 = cost_rotate(stack_a, smallest);
	ra2 = cost_rotate(stack_a, second_smallest);
	rra1 = cost_reverse_rotate(stack_a, smallest);
	rra2 = cost_reverse_rotate(stack_a, second_smallest);
	if (ra1 == ft_min(ft_min(ft_min(rra1, rra2), ra2), ra1))
		ft_ra(stack_a, ra1);
	else if (ra2 == ft_min(ft_min(ft_min(rra1, rra2), ra2), ra1))
		ft_ra(stack_a, ra2);
	else if (rra1 == ft_min(ft_min(ft_min(rra1, rra2), ra2), ra1))
		ft_rra(stack_a, rra1);
	else
		ft_rra(stack_a, rra2);
}

void	sort_under_seven(t_stack *stack_a, t_stack *stack_b)
{
	while (stack_a->size > 3)
	{
		if (stack_a->size > 4)
			best_pb_size_five(stack_a, get_smallest_int(stack_a));
		else
			rotate_top(stack_a, get_smallest_int(stack_a), 'a');
		ft_pb(stack_a, stack_b);
	}
	if (stack_b->size > 1)
		sort_six(stack_a, stack_b);
	while (stack_b->size > 0)
		ft_pa(stack_a, stack_b);
}
