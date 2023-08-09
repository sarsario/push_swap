/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rr_n.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: osarsari <osarsari@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/07 15:48:50 by osarsari          #+#    #+#             */
/*   Updated: 2023/08/07 16:16:05 by osarsari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	ft_rr_n(t_stack *a, t_stack *b, int n)
{
	while (n--)
		ft_rr(a, b);
}

void	ft_rrr_n(t_stack *a, t_stack *b, int n)
{
	while (n--)
		ft_rrr(a, b);
}
