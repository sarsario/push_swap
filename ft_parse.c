/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parse.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: osarsari <osarsari@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/07 10:00:29 by osarsari          #+#    #+#             */
/*   Updated: 2023/05/08 12:37:58 by osarsari         ###   ########.fr       */
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

static t_bool	unique_atoi(char **argv, int i)
{
	int	j;

	if (i < 2)
		return (true);
	j = i;
	while (--j > 0)
	{
		if (ft_atoi(argv[j] == ft_atoi(argv[i])))
			return (false);
	}
	return (true);
}

t_bool	valid_args(int argc, char **argv)
{
	int		i;

	i = 0;
	while (++i < argc)
	{
		if (!ft_isint(argv[i]))
			return (false);
		if (!unique_atoi(argv, i))
			return (false);
	}
	return (true);
}
