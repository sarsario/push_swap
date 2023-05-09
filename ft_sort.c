/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: osarsari <osarsari@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/08 11:47:23 by osarsari          #+#    #+#             */
/*   Updated: 2023/05/09 13:03:51 by osarsari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_sort(t_stack *stack)
{
	t_plate	*plate;

	if (!stack)
		return ;
	plate = stack->top;
	ft_putstr_fd("stack:\n", 1);
	while (plate)
	{
		ft_putstr_fd(ft_itoa(plate->value), 1);
		ft_putchar_fd('\n', 1);
		plate = plate->next;
	}
}
