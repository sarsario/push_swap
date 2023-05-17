/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   selection_sort.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: osarsari <osarsari@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/15 18:55:12 by osarsari          #+#    #+#             */
/*   Updated: 2023/05/16 13:57:13 by osarsari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	selection_sort(t_stack *stack_a, t_stack *stack_b)
{
	t_plate	*smallest;
	t_plate	*biggest;

	if (!stack_a || !stack_b)
		return (ft_putstr_fd("Error\n", 1));
	smallest = get_smallest_plate(stack_a);
	biggest = get_biggest_plate(stack_a);
	while (!stack_is_asc(stack_a) || stack_b->size > 0)
	{
		return ;
	}
}
