/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quick_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: osarsari <osarsari@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/13 18:13:28 by osarsari          #+#    #+#             */
/*   Updated: 2023/06/13 19:29:21 by osarsari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	quick_sort(t_stack *stack_a, t_stack *stack_b)
{
	int	count_pb;

	count_pb = 0;
	while (stack_a->size > 3 && count_pb++ > -1)
		lower_half_pb(stack_a, stack_b);
	sort_three(stack_a, stack_b);
}

int	quick_sort_a(t_stack *stack_a, t_stack *stack_b, int pivot)
{
	int		smallest_staying;
	int		starting_pivot;
	t_plate	*plate;

	plate = get_biggest_plate(stack_a);
	if (stack_a->size == 4)
		pivot = 1;
	starting_pivot = pivot;
	smallest_staying = stack_a->size - starting_pivot;
	while (--smallest_staying > 0)
		plate = get_smaller_plate(stack_a, plate);
	smallest_staying = plate->value;
	while (starting_pivot--)
		optimal_half_pb(stack_a, stack_b, smallest_staying);
	return (pivot);
}

int	quick_sort_b(t_stack *stack_a, t_stack *stack_b, int pivot)
{
	int		biggest_staying;
	int		starting_pivot;
	t_plate	*plate;

	plate = get_smallest_plate(stack_b);

}
