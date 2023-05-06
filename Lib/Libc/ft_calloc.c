/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: osarsari <osarsari@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/05 08:48:43 by osarsari          #+#    #+#             */
/*   Updated: 2023/05/06 12:04:45 by osarsari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

/*
** Allocates memory for an array of `count` elements of `size` bytes each and
** returns a pointer to the allocated memory. The memory is set to zero.
**
** count:	The number of elements to allocate memory for.
** size:	The size of each element to allocate memory for.
**
** returns:
** A void pointer to the allocated memory if successful, NULL otherwise.
*/

void	*ft_calloc(size_t count, size_t size)
{
	void	*ptr;
	size_t	total;

	total = count * size;
	ptr = malloc(total);
	if (!ptr)
		return (NULL);
	ft_bzero(ptr, total);
	return (ptr);
}
