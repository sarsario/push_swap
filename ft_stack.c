/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_stack.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: osarsari <osarsari@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/06 23:33:27 by osarsari          #+#    #+#             */
/*   Updated: 2023/05/08 13:34:48 by osarsari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_stack	*create_stack(int argc, char **argv)
{
	t_stack	*stack_a;

	stack_a = malloc(sizeof(t_stack));
	if (!stack_a)
		return (NULL);
	return (stack_a);
}

t_stack	*ft_stacknew(int value)
{
	t_stack	*stack_new;

	stack_new = malloc(sizeof(t_stack));
	if (!stack_new)
		return (NULL);
	stack_new->value = value;
	stack_new->left = NULL;
	stack_new->right = NULL;
	return (stack_new);
}