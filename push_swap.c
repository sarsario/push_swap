/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: osarsari <osarsari@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/02 08:25:16 by osarsari          #+#    #+#             */
/*   Updated: 2023/05/06 23:36:31 by osarsari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// static t_bool	valid_argv(int argc, char **argv)
// {
// 	 All arguments are actual numbers. White spaces allowed between numbers.
// 	int	i;
// 	i = 0;
// 	while (++i < argc)
// 	{
// 		if (!ft_isnbr(argv[i]))
// 			return (false);
// 		if (!ft_isint(argv[i]))
// 			return (false);
// 		if (!is_unique(argv, i))
// 			return (false);
// 	}
// 	return (true);
// }

int	main(int argc, char **argv)
{
	t_stack	*first;

	if (argc < 2)
		return (0);
	first = ft_stacknew(argv[1]);
	first->first = true;
	first->last = false;
	return (0);
}
