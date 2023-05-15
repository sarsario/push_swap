/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: osarsari <osarsari@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/02 08:25:16 by osarsari          #+#    #+#             */
/*   Updated: 2023/05/15 16:23:39 by osarsari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int argc, char **argv)
{
	t_stack	*stack_a;
	t_stack	*stack_b;

	if (argc < 2)
		return (0);
	if (!valid_args(argc, argv))
		ft_putstr_fd("Error\n", 1);
	else
	{
		stack_a = fill_stack(argc, argv);
		stack_b = ft_stack_new(0);
		if (!stack_a || !stack_b)
			ft_putstr_fd("Error\n", 1);
		else
			ft_sort(stack_a, stack_b);
	}
	return (0);
}

// system("leaks push_swap");
