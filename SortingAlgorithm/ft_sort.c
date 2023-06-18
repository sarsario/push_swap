/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: osarsari <osarsari@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/18 16:59:53 by osarsari          #+#    #+#             */
/*   Updated: 2023/06/18 19:56:17 by osarsari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	ft_sort(t_stack *stack_a, t_stack *stack_b)
{
	if (!stack_a || !stack_b)
		return (ft_putstr_fd("Error\n", 2));
	if (stack_a->size < 4)
		sort_three(stack_a);
	else if (stack_a->size < 7)
		sort_under_seven(stack_a, stack_b);
	else
		lis_sort(stack_a, stack_b);
	free_stack(stack_a);
	free_stack(stack_b);
}
