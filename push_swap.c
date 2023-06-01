/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: osarsari <osarsari@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/25 13:18:59 by osarsari          #+#    #+#             */
/*   Updated: 2023/06/01 17:00:49 by osarsari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>

#include "push_swap.h"

int	main(int argc, char **argv)
{
	t_stack	*stack_a;
	t_stack	*stack_b;

	if (argc < 2)
		return (0);
	if (!valid_args(argc, argv))
		ft_printf("Error\n");
	else
	{
		stack_a = fill_stack(argc, argv);
		stack_b = ft_stack_new();
		if (!stack_a || !stack_b)
			ft_printf("Error\n");
		else
			ft_sort(stack_a, stack_b);
	}
	return (0);
}

// system("leaks push_swap");
