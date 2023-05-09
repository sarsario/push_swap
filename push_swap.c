/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: osarsari <osarsari@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/02 08:25:16 by osarsari          #+#    #+#             */
/*   Updated: 2023/05/09 11:53:57 by osarsari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int argc, char **argv)
{
	stack_t	*stack;

	if (argc < 2)
		return (0);
	if (!valid_args(argc, argv))
		ft_putstr_fd("Error\n", 1);
	else
	{
		stack = pile_stack(argc, argv);
		if (!stack)
			ft_putstr_fd("Error\n", 1);
		else
			ft_sort(stack);
	}
	return (0);
}
