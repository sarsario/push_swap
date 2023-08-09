/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_valid_args.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: osarsari <osarsari@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/01 17:26:50 by osarsari          #+#    #+#             */
/*   Updated: 2023/08/02 07:49:33 by osarsari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

static int	ft_int_overflow(char *s, char sign)
{
	long long	l;

	l = 0;
	while (*s)
	{
		if (*s < '0' || *s > '9')
			return (0);
		l = l * 10 + (*s - '0');
		if (l - 1 > INT_MAX)
			return (0);
		s++;
	}
	if (sign == '-')
		l = -l;
	if (l > INT_MAX || l < INT_MIN)
		return (0);
	return (1);
}

static int	ft_is_int(char *str)
{
	char	sign;

	if (!str)
		return (0);
	sign = 0;
	while (ft_isspace(*str))
		str++;
	if (*str == '-')
		sign = *str++;
	if (!*str)
		return (0);
	return (ft_int_overflow(str, sign));
}

static int	ft_unique_atoi(char **args, int i)
{
	int	j;
	int	current;

	j = -1;
	current = ft_atoi(args[i]);
	while (++j < i)
	{
		if (ft_atoi(args[j]) == current)
			return (0);
	}
	return (1);
}

int	ft_valid_args(char **args)
{
	int	i;

	i = -1;
	while (args[++i])
	{
		if (!ft_is_int(args[i]))
			return (0);
		if (!ft_unique_atoi(args, i))
			return (0);
	}
	return (1);
}
