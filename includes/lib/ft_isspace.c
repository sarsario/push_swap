/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isspace.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: osarsari <osarsari@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/01 15:12:06 by osarsari          #+#    #+#             */
/*   Updated: 2023/08/01 15:14:16 by osarsari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** Tests whether c is a space character.
**
** c: The character to be tested.
**
** Returns:
** Non-zero value if the character is a space character, 0 otherwise.
*/

int	ft_isspace(int c)
{
	return ((c >= 9 && c <= 13) || c == 32);
}
