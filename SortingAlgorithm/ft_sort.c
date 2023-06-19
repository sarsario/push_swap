/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: osarsari <osarsari@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/18 16:59:53 by osarsari          #+#    #+#             */
/*   Updated: 2023/06/19 18:50:58 by osarsari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

t_bool	stack_is_asc(t_stack *stack)
{
	int	i;

	i = stack->size - 1;
	while (i--)
	{
		if (stack->numbers[i] < stack->numbers[i + 1])
			return (false);
	}
	return (true);
}

t_stack	*get_best_lis(t_stack *stack)
{
	t_stack	*lis;
	t_stack	*temp;
	int		i;

	i = stack->size;
	lis = get_lis(stack->numbers, stack->size);
	if (!lis)
		return (NULL);
	while (i--)
	{
		ft_rotate(stack);
		temp = get_lis(stack->numbers, stack->size);
		if (!temp)
			return (lis);
		if (lis->size < temp->size)
			lis_copy(lis, temp);
		free_stack(temp);
	}
	return (lis);
}

void	ft_sort(t_stack *stack_a, t_stack *stack_b)
{
	if (!stack_a || !stack_b)
		return (ft_putstr_fd("Error\n", 2));
	if (!stack_is_asc(stack_a) && stack_a->size < 4)
		sort_three(stack_a);
	else if (!stack_is_asc(stack_a) && stack_a->size < 7)
		sort_under_seven(stack_a, stack_b);
	else if (!stack_is_asc(stack_a))
		lis_sort(stack_a, stack_b);
	free_stack(stack_a);
	free_stack(stack_b);
}
