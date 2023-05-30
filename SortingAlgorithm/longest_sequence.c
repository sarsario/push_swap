/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   longest_sequence.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: osarsari <osarsari@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/27 12:08:39 by osarsari          #+#    #+#             */
/*   Updated: 2023/05/30 16:40:28 by osarsari         ###   ########.fr       */
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

// Function to find the maximum of two integers
int	ft_max(int a, int b)
{
	if (a > b)
		return (a);
	return (b);
}

// Function to build the LCS array
void	build_lcs(int array1[], int array2[], int m, int n, int lcs[][n + 1])
{
	int	i;
	int	j;

	i = 0;
	while (i <= m)
	{
		j = 0;
		while (j <= n)
		{
			if (i == 0 || j == 0)
				lcs[i][j] = 0;
			else if (array1[i - 1] == array2[j - 1])
				lcs[i][j] = lcs[i - 1][j - 1] + 1;
			else
				lcs[i][j] = ft_max(lcs[i - 1][j], lcs[i][j - 1]);
			j++;
		}
		i++;
	}
}

// Function to extract the LCS
int	*extract_lcs(int array1[], int array2[], int m, int n, int lcs[][n + 1])
{
	int	index;
	int	*result;
	int	i;
	int	j;

	index = lcs[m][n];
	i = m;
	j = n;
	result = malloc(sizeof(int) * index);
	if (!result)
		return (NULL);
	while (i > 0 && j > 0)
	{
		if (array1[i - 1] == array2[j - 1])
		{
			result[index - 1] = array1[i - 1];
			i--;
			j--;
			index--;
		}
		else if (lcs[i - 1][j] > lcs[i][j - 1])
			i--;
		else
			j--;
	}
	return (result);
}

// Function to find the LCS between two arrays

void	find_lcs(int array1[], int array2[])
{
	int	lcs[7][6];
	int	*sequence;
	int	m;
	int	n;
	int	i;

	m = 6;
	n = 5;
	build_lcs(array1, array2, m, n, lcs);
	sequence = extract_lcs(array1, array2, m, n, lcs);
	if (!sequence)
		printf("Empty sequence\n");
	else
	{
		i = 0;
		printf("LCS: ");
		while (i < lcs[m][n])
			printf("%d ", sequence[i++]);
	}
}

int	main()
{
	int	array1[] = {3, 9, 2, 1, 5, 7};
	int	array2[] = {1, 3, 5, 7, 9};
	int			m;
	int			n;

	m = 6;
	n = 5;
	find_lcs(array1, array2);
	return (0);
}
