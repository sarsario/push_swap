/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parse.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: osarsari <osarsari@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/07 10:00:29 by osarsari          #+#    #+#             */
/*   Updated: 2023/05/08 12:13:58 by osarsari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_bool	ft_isspace(int c)
{
	if (c == 32)
		return (true);
	if (c >= 9 && c <= 13)
		return (true);
	return (false);
}

t_bool	valid_stack(int argc, char **argv)
{
	int		i;
	t_stack	*stack_a;

	i = 1;
	if (!ft_isint(argv[i]))
		return (false);
	stack_a = ft_stacknew(ft_atoi(argv[i]));
	while (++i < argc)
	{
		if (!ft_isint(argv[i]))
			return (false);
		
	}
}
