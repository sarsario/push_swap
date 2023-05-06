/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: osarsari <osarsari@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/03 14:51:06 by osarsari          #+#    #+#             */
/*   Updated: 2023/04/10 11:24:28 by osarsari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** Set `n` bytes of memory starting at address `s` to zero.
**
** s:	A pointer to the memory area to zero out.
** n:	The number of bytes to zero out.
*/

#include "../libft.h"

void	ft_bzero(void *s, size_t n)
{
	unsigned char	*ptr;

	if (n == 0)
		return ;
	ptr = (unsigned char *)s;
	while (n--)
		*ptr++ = 0;
}
