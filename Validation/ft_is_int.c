/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_is_int.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: osarsari <osarsari@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/25 13:26:37 by osarsari          #+#    #+#             */
/*   Updated: 2023/06/17 12:38:38 by osarsari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

t_bool	ft_int_overflow(const char *s, const char sign)
{
	long long	l;

	l = 0;
	while (*s)
	{
		if (*s < '0' || *s > '9')
			return (false);
		l = l * 10 + (*s - '0');
		if (l - 1 > INT_MAX)
			return (false);
		s++;
	}
	if (sign == '-')
		l = -l;
	if (l > INT_MAX || l < INT_MIN)
		return (false);
	return (true);
}

t_bool	ft_is_int(const char *s)
{
	char	sign;

	if (!s)
		return (false);
	sign = 0;
	while (ft_is_space(*s))
		s++;
	if (*s == '-')
		sign = *s++;
	if (!*s)
		return (false);
	return (ft_int_overflow(s, sign));
}

int	ft_max(int a, int b)
{
	if (a > b)
		return (a);
	return (b);
}

int	ft_min(int a, int b)
{
	if (a > b)
		return (b);
	return (a);
}
