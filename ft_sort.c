/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: osarsari <osarsari@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/08 11:47:23 by osarsari          #+#    #+#             */
/*   Updated: 2023/05/10 22:56:00 by osarsari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_sort(t_stack *stack_a, t_stack *stack_b)
{
	if (!stack_a || !stack_b)
		return (ft_putstr_fd("One of the stack (or both) is NULL\n", 1));
	ft_printf("Attempting to print stack_a\n");
	ft_print_stack(stack_a);
	ft_printf("Attempting to print stack_b\n");
	ft_print_stack(stack_b);
	ft_putchar_fd('\n', 1);
	ft_printf("Attempting to ft_swap\n");
	if (ft_swap(stack_a))
	{
		ft_putstr_fd("sa\n", 1);
		ft_print_stack(stack_a);
	}
	ft_printf("Attempting to ft_rotate\n");
	if (ft_rotate(stack_a))
	{
		ft_putstr_fd("ra\n", 1);
		ft_print_stack(stack_a);
	}
	ft_printf("Attempting to ft_push_stack\n");
	if (ft_push_stack(stack_a, stack_b))
	{
		ft_putstr_fd("pb\nstack_a:\n", 1);
		ft_printf("Attempting to print stack_a\n");
		ft_print_stack(stack_a);
		ft_putstr_fd("stack_b:\n", 1);
		ft_printf("Attempting to print stack_b\n");
		ft_print_stack(stack_b);
	}
	ft_printf("Attempting to print stack_a\n");
	ft_print_stack(stack_a);
	ft_printf("Attempting to pop stack_a\n");
	int	poped = 0;
	while (ft_pop(stack_a, &poped))
		ft_printf("Poped: %i\n", poped);
	free(stack_a);
	if (!stack_a)
		ft_printf("stack_a freed ?\n");
	while (ft_pop(stack_b, &(int){0}))
		;
	free(stack_b);
}
