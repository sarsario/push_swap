/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_find.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: osarsari <osarsari@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/18 17:14:01 by osarsari          #+#    #+#             */
/*   Updated: 2023/06/19 13:58:51 by osarsari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int	get_smallest_int(t_stack *stack)
{
	int	res;
	int	i;

	i = 0;
	res = stack->numbers[i];
	while (++i < stack->size)
	{
		if (stack->numbers[i] < res)
			res = stack->numbers[i];
	}
	return (res);
}

int	get_biggest_int(t_stack *stack)
{
	int	res;
	int	i;

	i = 0;
	res = stack->numbers[i];
	while (++i < stack->size)
	{
		if (res < stack->numbers[i])
			res = stack->numbers[i];
	}
	return (res);
}

int	get_smaller_int(t_stack *stack, int n)
{
	int	res;
	int	i;

	res = INT_MIN;
	i = -1;
	while (++i < stack->size)
	{
		if (stack->numbers[i] < n && stack->numbers[i] > res)
			res = stack->numbers[i];
	}
	return (res);
}

int	get_bigger_int(t_stack *stack, int n)
{
	int	res;
	int	i;

	res = INT_MAX;
	i = -1;
	while (++i < stack->size)
	{
		if (stack->numbers[i] > n && stack->numbers[i] < res)
			res = stack->numbers[i];
	}
	return (res);
}

int	get_smallest_bigger(t_stack *stack, int n)
{

}
