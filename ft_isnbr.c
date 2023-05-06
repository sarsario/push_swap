/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isnbr.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: osarsari <osarsari@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/06 22:41:29 by osarsari          #+#    #+#             */
/*   Updated: 2023/05/06 23:25:15 by osarsari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static t_bool	ft_isspace(int c)
{
	if (c == 32)
		return (true);
	if (c >= 9 && c <= 13)
		return (true);
	return (false);
}

t_bool	ft_isnbr(const char *s)
{
	if (!s)
		return (false);
	while (ft_isspace(*s))
		s++;
	if (*s == '-')
		s++;
	while (*s)
	{
		if (!ft_isdigit(*s))
			return (false);
		s++;
	}
	return (true);
}

t_bool	ft_isint(const char *s)
{
	int		n;
	size_t	len_s;

	if (!s)
		return (false);
	n = 0;
	len_s = ft_strlen(s);
	while (len_s > 0)
		n = n * 10 + s[--len_s];
	return (true);
}
