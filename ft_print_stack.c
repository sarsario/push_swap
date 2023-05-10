/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_stack.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: osarsari <osarsari@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/09 20:24:39 by osarsari          #+#    #+#             */
/*   Updated: 2023/05/10 22:51:50 by osarsari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_print_stack(t_stack *stack)
{
	t_plate	*current;

	if (!stack)
		return (ft_putstr_fd("stack doesn't exist\n", 1));
	if (stack->size < 1)
		return (ft_putstr_fd("Empty stack.\n", 1));
	current = stack->top;
	while (current)
	{
		ft_printf("%i\n", current->value);
		current = current->next;
	}
}
