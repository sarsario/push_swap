/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   compute_dist.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: osarsari <osarsari@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/16 13:59:51 by osarsari          #+#    #+#             */
/*   Updated: 2023/05/16 14:04:56 by osarsari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	dist_from_top(t_stack *stack, t_plate *plate)
{
	int		dist;
	t_plate	*top;

	if (!stack || !plate)
		return (-1);
	dist = 0;
	top = stack->top;
	while (top != plate)
	{
		dist++;
		top = top->next;
	}
	return (dist);
}

int	dist_from_bot(t_stack *stack, t_plate *plate)
{
	t_plate	*bot;
	int		dist;

	if (!stack || !plate)
		return (-1);
	dist = 0;
	bot = stack->bottom;
	while (bot != plate)
	{
		dist++;
		bot = bot->prev;
	}
	return (dist);
}
