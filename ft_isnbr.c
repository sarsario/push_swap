/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isnbr.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: osarsari <osarsari@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/06 22:41:29 by osarsari          #+#    #+#             */
/*   Updated: 2023/05/08 12:17:30 by osarsari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_bool	ft_isint(const char *s)
{
	long long	l;
	char		sign;

	if (!s)
		return (false);
	l = 0;
	sign = 0;
	while (ft_isspace(*s))
		s++;
	if (*s == '-')
		sign = *s++;
	while (*s)
	{
		if (*s < '0' || *s > '9')
			return (false);
		l = l * 10 + (*s - '0');
		if (l - 1 > INT_MAX)
			return (false);
	}
	if (sign == '-')
		l = -l;
	if (l > INT_MAX || l < INT_MIN)
		return (false);
	return (true);
}
