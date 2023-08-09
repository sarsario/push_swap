/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_is_sorted.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: osarsari <osarsari@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/09 10:17:06 by osarsari          #+#    #+#             */
/*   Updated: 2023/08/09 10:17:14 by osarsari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/checker.h"

int	ft_is_sorted(t_stack *stack)
{
	int	i;

	if (!stack || !stack->stack || stack->size < 1)
		return (0);
	i = stack->size;
	while (--i > 0)
		if (stack->stack[i] > stack->stack[i - 1])
			return (0);
	return (1);
}
