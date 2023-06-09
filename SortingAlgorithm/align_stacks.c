/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   align_stacks.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: osarsari <osarsari@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/09 18:32:11 by osarsari          #+#    #+#             */
/*   Updated: 2023/06/09 21:19:18 by osarsari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	best_move_top_a(t_stack *stack_a, t_plate *to_top)
{
	int		nb_ra;
	int		nb_rra;

	nb_ra = cost_rotate_top(stack_a, to_top);
	nb_rra = cost_reverse_top(stack_a, to_top);
	if (nb_rra < nb_ra)
		return (ft_rra(stack_a, nb_rra));
	ft_ra(stack_a, nb_ra);
}

void	smart_align(t_stack *stack_a, t_stack *stack_b, t_plate *to_move,
	t_plate *to_top_b)
{
	int		nb_ra;
	int		nb_rra;
	int		nb_rb;
	int		nb_rrb;

	nb_ra = cost_rotate_top(stack_a, to_move);
	nb_rra = cost_reverse_top(stack_a, to_move);
	nb_rb = cost_rotate_top(stack_b, to_top_b);
	nb_rrb = cost_reverse_top(stack_b, to_top_b);
	if (nb_rb > nb_ra && (nb_rb < nb_rra || nb_rb < nb_rrb))
	{
		ft_rr(stack_a, stack_b, nb_ra);
		ft_rb(stack_b, nb_rb - nb_ra);
	}
	else if (nb_ra >= nb_rb && (nb_ra < nb_rra || nb_ra < nb_rrb))
	{
		ft_rr(stack_a, stack_b, nb_rb);
		ft_ra(stack_a, nb_ra - nb_rb);
	}
	else if (nb_rrb > nb_rra && (nb_rrb < nb_ra || nb_rrb < nb_rb))
	{
		ft_rrr(stack_a, stack_b, nb_rra);
		ft_rrb(stack_b, nb_rrb - nb_rra);
	}
	else
	{
		ft_rrr(stack_a, stack_b, nb_rrb);
		ft_rra(stack_a, nb_rra - nb_rrb);
	}
}

void	align_stacks(t_stack *stack_a, t_stack *stack_b, t_plate *to_move)
{
	t_plate	*top_plate_b;
	int		nb_ra;
	int		nb_rb;
	int		nb_rra;
	int		nb_rrb;

	if (stack_b->size == 0)
		return (best_move_top_a(stack_a, to_move));
	top_plate_b = find_biggest_smaller(stack_b, to_move);
	nb_ra = cost_rotate_top(stack_a, to_move);
	nb_rra = cost_reverse_top(stack_a, to_move);
	nb_rb = cost_rotate_top(stack_b, top_plate_b);
	nb_rrb = cost_reverse_top(stack_b, top_plate_b);
	if (get_cost_comb(nb_ra, nb_rb, nb_rra, nb_rrb)
		> get_cost_indiv(nb_ra, nb_rb, nb_rra, nb_rrb))
	{
		if (nb_ra > nb_rra)
			ft_rra(stack_a, nb_rra);
		else
			ft_ra(stack_a, nb_ra);
		if (nb_rb > nb_rrb)
			ft_rrb(stack_b, nb_rrb);
		else
			ft_rb(stack_b, nb_rb);
	}
	else
		smart_align(stack_a, stack_b, to_move, top_plate_b);
}
