/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isdigit.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: osarsari <osarsari@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/03 13:13:28 by osarsari          #+#    #+#             */
/*   Updated: 2023/04/10 11:24:59 by osarsari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

/*
** Checks if the given character is a digit.
** A digit is a character that represents a number from 0 to 9.
**
** c:	The character to be checked.
**
** Returns:
** 1 if the character is a digit, 0 otherwise.
*/

int	ft_isdigit(int c)
{
	return (c >= '0' && c <= '9');
}
