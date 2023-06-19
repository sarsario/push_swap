/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lis_sort.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: osarsari <osarsari@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/18 20:15:22 by osarsari          #+#    #+#             */
/*   Updated: 2023/06/19 13:17:53 by osarsari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

// void	print_stack(t_stack *stack)
// {
// 	int	i = stack->size;

// 	ft_printf("Stack:");
// 	while (i--)
// 		ft_printf(" %i", stack->numbers[i]);
// 	ft_printf("\n");
// }

t_stack	**stack_matrix(int row, int col)
{
	t_stack	**matrix;
	int		i;
	int		j;

	matrix = malloc(sizeof(t_stack *) * row);
	if (!matrix)
		return (NULL);
	i = -1;
	while (++i < row)
	{
		matrix[i] = ft_stack_new(col);
		if (!matrix[i])
		{
			while (i--)
				free_stack(matrix[i]);
			return (NULL);
		}
		j = -1;
	}
	return (matrix);
}

void	lis_copy(t_stack *dst, t_stack *src)
{
	int	i;

	i = 0;
	while (i < src->size)
	{
		dst->numbers[i] = src->numbers[i];
		i++;
	}
	dst->size = src->size;
}

void	compute_lis_matrix(t_stack **lis_matrix, int *sequence, int size)
{
	int	i;
	int	j;

	i = size - 1;
	ft_push(lis_matrix[i], sequence[i]);
	while (i--)
	{
		j = i;
		while (j++ < size - 1)
		{
			if (sequence[i] > sequence[j]
				&& lis_matrix[i]->size < lis_matrix[j]->size + 1)
				lis_copy(lis_matrix[i], lis_matrix[j]);
		}
		ft_push(lis_matrix[i], sequence[i]);
	}
}

t_stack	*get_lis(int *sequence, int size)
{
	t_stack	**lis_matrix;
	t_stack	*lis;
	int		i;

	lis_matrix = stack_matrix(size, size);
	if (!lis_matrix)
		return (NULL);
	lis = ft_stack_new(size);
	if (!lis)
		return (NULL);
	compute_lis_matrix(lis_matrix, sequence, size);
	i = 0;
	lis_copy(lis, lis_matrix[i]);
	while (i++ < size - 1)
	{
		if (lis->size < lis_matrix[i]->size)
			lis = lis_matrix[i];
	}
	while (size--)
		free_stack(lis_matrix[size]);
	free(lis_matrix);
	return (lis);
}

void	lis_sort(t_stack *stack_a, t_stack *stack_b)
{
	t_stack	*lis;
	int		i;
	int		rot;

	i = stack_a->size;
	rot = 0;
	while (stack_a->numbers[stack_a->size - 1] != get_smallest_int(stack_a))
	{
		ft_rotate(stack_a);
		rot++;
	}
	lis = get_lis(stack_a->numbers, stack_a->size);
	if (!lis)
		return (ft_putstr_fd("Error\n", 2));
	while (rot--)
		ft_reverse_rotate(stack_a);
	while (stack_a->size > lis->size)
		efficient_pb(stack_a, stack_b, lis);
	while (stack_b->size > 0)
		efficient_pa(stack_a, stack_b, lowest_cost_pa(stack_a, stack_b));
	rotate_top(stack_a, get_smallest_int(stack_a), 'a');
}

	// int j = lis->size;
	// ft_printf("\nLIS size: %i\nLIS:", lis->size);
	// while (j--)
	// 	ft_printf(" %i",lis->numbers[j]);
	// ft_printf("\nLis from print_stack:\n");
	// print_stack(lis);
	// ft_printf("\nStack_b size = %i\n", stack_b->size);
