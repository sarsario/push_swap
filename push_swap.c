/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: osarsari <osarsari@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/25 11:11:00 by osarsari          #+#    #+#             */
/*   Updated: 2023/08/09 15:59:20 by osarsari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/push_swap.h"

static int	ft_error(void)
{
	ft_putstr_fd("Error\n", 2);
	return (1);
}

static int	ft_free_exit(t_stack *a, t_stack *b, int ret)
{
	if (a->stack)
		free(a->stack);
	if (b->stack)
		free(b->stack);
	return (ret);
}

int	main(int argc, char **argv)
{
	t_stack	a;
	t_stack	b;
	int		numbers_count;

	if (argc < 2)
		return (1);
	numbers_count = ft_init_stack(&a, argc, argv);
	if (!numbers_count)
		return (ft_error());
	if (!ft_stack_new(&b, numbers_count))
		return (ft_free_exit(&a, &b, 1));
	if (!ft_sort(&a, &b))
	{
		ft_free_exit(&a, &b, 0);
		return (ft_error());
	}
	return (ft_free_exit(&a, &b, 0));
}
