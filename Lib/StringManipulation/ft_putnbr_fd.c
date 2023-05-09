/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: osarsari <osarsari@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/11 18:12:38 by osarsari          #+#    #+#             */
/*   Updated: 2023/05/06 12:05:55 by osarsari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

/*
** Outputs the integer `n` to the given file descriptor `fd`.
**
** n:	The integer to output.
** fd:	The file descriptor on which to write.
*/

void	ft_putnbr_fd(int n, int fd)
{
	char	c;
	long	l;

	l = (long)n;
	if (l < 0)
	{
		ft_putchar_fd('-', fd);
		l = -l;
	}
	if (l >= 10)
		ft_putnbr_fd((int)(l / 10), fd);
	c = l % 10 + '0';
	ft_putchar_fd(c, fd);
}
