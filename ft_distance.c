/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_distance.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: osarsari <osarsari@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/16 22:56:14 by osarsari          #+#    #+#             */
/*   Updated: 2023/05/16 23:00:57 by osarsari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	distance_top(t_stack *stack, t_plate *plate)
{
	t_plate	*top;
	int		distance;

	if (!stack || !plate || stack->size < 1)
		return (-1);
	distance = 0;
	top = stack->top;
	while (top != plate)
	{
		distance++;
		top = top->next;
	}
	return (distance);
}

int	distance_bot(t_stack *stack, t_plate *plate)
{
	t_plate	*bot;
	int		distance;

	if (!stack || !plate || stack->size < 1)
		return (-1);
	distance = 0;
	bot = stack->bottom;
	while (bot != plate)
	{
		distance++;
		bot = bot->prev;
	}
	return (distance);
}