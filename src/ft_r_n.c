/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_r_n.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: osarsari <osarsari@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/07 15:42:46 by osarsari          #+#    #+#             */
/*   Updated: 2023/08/07 16:16:02 by osarsari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	ft_ra_n(t_stack *a, int n)
{
	while (n--)
		ft_ra(a);
}

void	ft_rra_n(t_stack *a, int n)
{
	while (n--)
		ft_rra(a);
}

void	ft_rb_n(t_stack *b, int n)
{
	while (n--)
		ft_rb(b);
}

void	ft_rrb_n(t_stack *b, int n)
{
	while (n--)
		ft_rrb(b);
}
