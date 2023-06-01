/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   longest_sequence.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: osarsari <osarsari@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/27 12:08:39 by osarsari          #+#    #+#             */
/*   Updated: 2023/06/01 17:12:56 by osarsari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int	bring_smallest_top(t_stack *stack)
{
	int		nb_rotation;
	t_plate	*smallest;

	if (!stack)
		return (-1);
	nb_rotation = 0;
	smallest = get_smallest_plate(stack);
	while (stack->top != smallest)
	{
		ft_rotate(stack);
		nb_rotation++;
	}
	return (nb_rotation);
}

void	cancel_rotation(t_stack *stack, int nb_rotation)
{
	if (!stack || nb_rotation < 0)
		return (ft_putstr_fd("Error in cancel_rotation.\n", 1));
	while (nb_rotation--)
		ft_reverse_rotate(stack);
}

// int	*longest_common_sequence(t_stack *stack)
// {
// 	int		nb_rotation;
// 	t_plate	*plate;
// 	t_plate	*next;
// 	t_stack	*ordered_stack;
// 	int		*sequence;
// 	int		i;

// 	if (!stack)
// 		return (NULL);
// 	sequence = malloc(sizeof(int) * stack->size);
// 	if (!sequence)
// 		return (NULL);
// 	nb_rotation = bring_smallest_top(stack);
// 	ordered_stack = sorted_stack(stack);
// 	plate = stack->top;
// 	next = ordered_stack->top;
// 	i = 0;
// 	while (plate && next)
// 	{
// 		while (next && next->value != plate->value)
// 			next = next->next;
// 		if (next && next->value == plate->value)
// 			sequence[i++] = plate->value;
// 		plate = plate->next;
// 	}
// 	return (sequence);
// }
