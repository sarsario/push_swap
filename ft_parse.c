/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parse.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: osarsari <osarsari@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/07 10:00:29 by osarsari          #+#    #+#             */
/*   Updated: 2023/05/09 12:33:18 by osarsari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*
** Check if a character is a whitespace character.
**
** c: The character to be checked.
**
** Returns:
** true if c is a whitespace character, false otherwise.
*/

t_bool	ft_isspace(int c)
{
	if (c == 32)
		return (true);
	if (c >= 9 && c <= 13)
		return (true);
	return (false);
}

/*
** Check if the integer represented by the string at argv[i] is unique among
** the integers represented by the strings at argv[1] to argv[i-1].
**
** argv: An array of strings representing integers.
** i: The index of the string in argv to check.
**
** Returns:
** true if the integer at argv[i] is unique, false otherwise.
*/

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

/*
** Validates command line arguments for the program.
**
** argc: The number of arguments passed to the program.
** argv: An array of strings containing the arguments.
**
** Returns:
** true if all arguments are integers and unique, false otherwise.
*/

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
