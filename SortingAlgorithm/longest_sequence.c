/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   longest_sequence.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: osarsari <osarsari@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/27 12:08:39 by osarsari          #+#    #+#             */
/*   Updated: 2023/05/29 21:08:08 by osarsari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

t_stack	*longest_sequence(t_stack *stack)
{
	t_stack	*new_stack;
	t_plate	*start;
	t_plate	*plate;

	if (!stack)
		return (NULL);
	new_stack = ft_stack_new();
	start = get_smallest_plate(stack);
	ft_push(new_stack, start->value);
	plate = start->next;
	while (plate != start)
	{
		if (plate == NULL)
			plate = stack->top;
		if (new_stack->size == 0 || plate->value > new_stack->top->value)
			ft_push(new_stack, plate->value);
		else
		{
			ft_pop(new_stack, &(int){0});
			ft_push(new_stack, plate->value);
		}
		plate = plate->next;
	}
	return (new_stack);
}

// #include "push_swap.h"

// int	main(int argc, char **argv)
// {
// 	t_stack	*stack_a;
// 	t_stack	*stack_b;

// 	if (argc < 2)
// 		return (0);
// 	if (!valid_args(argc, argv))
// 		ft_printf("Error\n");
// 	else
// 	{
// 		stack_a = fill_stack(argc, argv);
// 		stack_b = ft_stack_new();
// 		if (!stack_a || !stack_b)
// 			ft_printf("Error\n");
// 		else
// 		{
			// int	sequence_length;
			// t_plate	**sequence = longest_sequence(stack_a, &sequence_length);
			// ft_printf("Longest ascending sequence length: %d\n", sequence_length);
			// ft_printf("Plates in sequence: ");
			// for (int i = 0; i < sequence_length; i++)
			// {
			// 	ft_printf("%d ", sequence[i]->value);
			// }
			// ft_printf("\n");
			// free(sequence);
// 			ft_sort(stack_a, stack_b);
// 		}
// 	}
// 	return (0);
// }

// system("leaks push_swap");