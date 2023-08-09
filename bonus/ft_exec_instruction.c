/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_exec_instruction.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: osarsari <osarsari@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/09 09:53:13 by osarsari          #+#    #+#             */
/*   Updated: 2023/08/09 12:35:21 by osarsari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/checker.h"

int	ft_exec_swap(t_stack *a, t_stack *b, char *op)
{
	if (!ft_strncmp(op, "sa", 2))
		return (ft_swap(a));
	else if (!ft_strncmp(op, "sb", 2))
		return (ft_swap(b));
	else if (!ft_strncmp(op, "ss", 2))
		return (ft_swap(a) && ft_swap(b));
	return (0);
}

int	ft_exec_push(t_stack *a, t_stack *b, char *op)
{
	if (!ft_strncmp(op, "pa", 2))
		return (ft_push_stack(b, a));
	else if (!ft_strncmp(op, "pb", 2))
		return (ft_push_stack(a, b));
	return (0);
}

int	ft_exec_rotate(t_stack *a, t_stack *b, char *op)
{
	if (!ft_strncmp(op, "ra", 2))
		return (ft_rotate(a));
	else if (!ft_strncmp(op, "rb", 2))
		return (ft_rotate(b));
	else if (!ft_strncmp(op, "rra", 3))
		return (ft_reverse_rotate(a));
	else if (!ft_strncmp(op, "rrb", 3))
		return (ft_reverse_rotate(b));
	else if (!ft_strncmp(op, "rrr", 3))
		return (ft_reverse_rotate(a) && ft_reverse_rotate(b));
	else if (!ft_strncmp(op, "rr", 2))
		return (ft_rotate(a) && ft_rotate(b));
	return (0);
}
