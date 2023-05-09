/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putchar_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: osarsari <osarsari@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/11 17:45:20 by osarsari          #+#    #+#             */
/*   Updated: 2023/05/06 12:05:45 by osarsari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

/*
** Outputs the character `c` to the given file descriptor `fd`.
**
** c:	The character to output.
** fd:	The file descriptor on which to write.
*/
void	ft_putchar_fd(char c, int fd)
{
	write(fd, &c, 1);
}
