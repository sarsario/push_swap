/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_stacknew.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: osarsari <osarsari@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/06 23:33:27 by osarsari          #+#    #+#             */
/*   Updated: 2023/05/08 12:17:27 by osarsari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_stack	*ft_stacknew(int i)
{
	t_stack	*stack_new;

	stack_new = malloc(sizeof(t_stack));
	if (!stack_new)
		return (NULL);
}
