/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_plate.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: osarsari <osarsari@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/10 20:45:54 by osarsari          #+#    #+#             */
/*   Updated: 2023/05/10 22:42:48 by osarsari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*
** Allocates (with malloc(3)) and returns a new plate with the given value and
** next plate pointer. The previous plate pointer is always initialized to NULL
** as new plates are always placed at the top of a stack.
**
** next: The next plate pointer.
** value: The value to store in the new plate.
**
** Returns:
** The new plate if successful, NULL otherwise.
*/

t_plate	*ft_plate_new(t_plate *next, int value)
{
	t_plate	*new_plate;

	new_plate = malloc(sizeof(t_plate));
	if (!new_plate)
		return (NULL);
	new_plate->prev = NULL;
	if (!next)
		new_plate->next = NULL;
	else
		new_plate->next = next;
	new_plate->value = value;
	return (new_plate);
}
