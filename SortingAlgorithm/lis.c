/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lis.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: osarsari <osarsari@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/17 09:49:06 by osarsari          #+#    #+#             */
/*   Updated: 2023/06/17 13:26:16 by osarsari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	lis_copy(t_lis *dst, t_lis *src)
{
	int	i = 0;

	while (i < src->size)
	{
		dst->lis_at_index[i] = src->lis_at_index[i];
		i++;
	}
	dst->size = src->size;
}

t_lis	*lis_construct(t_stack *stack_a, int n)
{
	t_lis	**lis_matrix;
	int		i;
	t_plate	*plate;
	int		j;
	t_plate	*prev_plate;
	t_lis	*lis;

	// Constructing the matrix
	int rot = 0;
	while (stack_a->top != get_smallest_plate(stack_a))
	{
		ft_rotate(stack_a);
		rot++;
	}
	lis_matrix = malloc(sizeof(t_lis *) * n);
	if (!lis_matrix)
		return (NULL);
	i = 0;
	while (i < n)
	{
		lis_matrix[i] = malloc(sizeof(t_lis));
		lis_matrix[i]->lis_at_index = malloc(sizeof(int) * n);
		lis_matrix[i]->size = 0;
		i++;
	}
	// Add first element of stack_a to matrix[0];
	plate = stack_a->top;
	lis_matrix[0]->lis_at_index[0] = plate->value;
	lis_matrix[0]->size++;
	i = 1;
	while (i < n)
	{
		j = i;
		// first loop will be going through stack_a.
		// nested loop will look at every preceding plate.
		plate = plate->next;
		prev_plate = plate->prev;
		while (--j)
		{
			if (plate->value > prev_plate->value
				&& lis_matrix[i]->size < lis_matrix[j]->size + 1)
				lis_copy(lis_matrix[i], lis_matrix[j]);
			prev_plate = prev_plate->prev;
		}
		lis_matrix[i]->lis_at_index[lis_matrix[i]->size] = plate->value;
		lis_matrix[i]->size++;
		// plate = plate->next;
		i++;
	}
	// look at all constructed lis and return the one with biggest size.
	i = 0;
	lis = lis_matrix[i];
	while (i < n)
	{
		if (lis_matrix[i]->size > lis->size)
			lis = lis_matrix[i];
		i++;
	}
	while (rot--)
		ft_reverse_rotate(stack_a);
	return (lis);
}

void	print_lis(t_lis *lis)
{
	int i = 0;

	ft_printf("LIS: ");
	while (i < lis->size)
	{
		ft_printf("%i ",lis->lis_at_index[i]);
		i++;
	}
	ft_printf("\n");
}

t_bool	lis_member(t_lis *lis, t_plate *plate)
{
	int	i;

	i = 0;
	while (i < lis->size)
	{
		if (plate->value == lis->lis_at_index[i])
			return (true);
		i++;
	}
	return (false);
}

void	efficient_pb(t_stack *stack_a, t_stack *stack_b, t_lis *lis)
{
	t_plate	*plate;
	int		ra;
	int		rra;

	plate = stack_a->top;
	ra = 0;
	while (lis_member(lis, plate))
	{
		ra++;
		plate = plate->next;
	}
	rra = 1;
	plate = stack_a->bot;
	while (lis_member(lis, plate))
	{
		rra++;
		plate = plate->prev;
	}
	if (ra > rra)
		ft_rra(stack_a, rra);
	else
		ft_ra(stack_a, ra);
	ft_pb(stack_a, stack_b);
}

t_plate	*get_smallest_bigger(t_stack *stack, t_plate *to_move)
{
	t_plate	*plate;

	plate = get_smallest_plate(stack);
	if (to_move->value > plate->value
		&& to_move->value < get_biggest_plate(stack)->value)
	{
		while (plate->value < to_move->value)
			plate = get_bigger_plate(stack, plate);
	}
	return (plate);
}

int	cost_logic(int ra, int rb, int rra, int rrb)
{
	int	rr;
	int	rrr;
	int	rab;

	rr = ft_max(ra, rb);
	rrr = ft_max(rra, rrb);
	rab = ft_min(ra, rra) + ft_min(rb, rrb);
	return (ft_min(ft_min(rr, rrr), rab));
}

int	estimated_cost(t_stack *stack_a, t_stack *stack_b, t_plate *to_move)
{
	t_plate	*to_top;
	int		ra;
	int		rb;
	int		rra;
	int		rrb;

	to_top = get_smallest_bigger(stack_a, to_move);
	ra = cost_rotate_top(stack_a, to_top);
	rb = cost_rotate_top(stack_b, to_move);
	rra = cost_reverse_top(stack_a, to_top);
	rrb = cost_reverse_top(stack_b, to_move);
	return (cost_logic(ra, rb, rra, rrb));
}

t_plate	*lowest_rotate_cost_pa(t_stack *stack_a, t_stack *stack_b)
{
	t_plate	*plate;
	t_plate	*best;
	int		min_cost;
	int		cost;
	int		i;

	plate = stack_b->top;
	best = plate;
	min_cost = estimated_cost(stack_a, stack_b, plate);
	i = min_cost;
	while (i-- > 0 && plate->next)
	{
		plate = plate->next;
		cost = estimated_cost(stack_a, stack_b, plate);
		if (cost < min_cost)
		{
			min_cost = cost;
			best = plate;
			if (i > min_cost)
				i = min_cost;
		}
	}
	return (best);
}

t_plate	*lowest_reverse_cost_pa(t_stack *stack_a, t_stack *stack_b)
{
	t_plate	*plate;
	t_plate	*best;
	int		min_cost;
	int		cost;
	int		i;

	plate = stack_b->bot;
	best = plate;
	min_cost = estimated_cost(stack_a, stack_b, plate);
	i = min_cost;
	while (i-- > 0 && plate->prev)
	{
		plate = plate->prev;
		cost = estimated_cost(stack_a, stack_b, plate);
		if (cost < min_cost)
		{
			min_cost = cost;
			best = plate;
			if (i > min_cost)
				i = min_cost;
		}
	}
	return (best);
}

t_plate	*lowest_cost_pa(t_stack *stack_a, t_stack *stack_b)
{
	t_plate	*plate_1;
	t_plate	*plate_2;

	plate_1 = lowest_rotate_cost_pa(stack_a, stack_b);
	plate_2 = lowest_reverse_cost_pa(stack_a, stack_b);
	if (plate_1 == plate_2 || estimated_cost(stack_a, stack_b, plate_2) >= estimated_cost(stack_a, stack_b, plate_1))
		return (plate_1);
	return (plate_2);
}

void	exec_rr_pa(t_stack *stack_a, t_stack *stack_b, int ra, int rb)
{
	if (ra > rb)
	{
		ft_rr(stack_a, stack_b, rb);
		ft_ra(stack_a, ra - rb);
	}
	else
	{
		ft_rr(stack_a, stack_b, ra);
		ft_rb(stack_b, rb - ra);
	}
	ft_pa(stack_a, stack_b);
}

void	exec_rrr_pa(t_stack *stack_a, t_stack *stack_b, int rra, int rrb)
{
	if (rra > rrb)
	{
		ft_rrr(stack_a, stack_b, rrb);
		ft_rra(stack_a, rra - rrb);
	}
	else
	{
		ft_rrr(stack_a, stack_b, rra);
		ft_rrb(stack_b, rrb - rra);
	}
	ft_pa(stack_a, stack_b);
}

void	efficient_pa(t_stack *stack_a, t_stack *stack_b, t_plate *to_move)
{
	t_plate	*to_top;
	int		ra;
	int		rb;
	int		rra;
	int		rrb;

	to_top = get_smallest_bigger(stack_a, to_move);
	ra = cost_rotate_top(stack_a, to_top);
	rb = cost_rotate_top(stack_b, to_move);
	rra = cost_reverse_top(stack_a, to_top);
	rrb = cost_reverse_top(stack_b, to_move);
	if (ft_max(ra, rb) <= ft_max(rra, rrb)
		&& ft_max(ra, rb) <= (ft_min(ra, rra) + ft_min(rb, rrb)))
		return (exec_rr_pa(stack_a, stack_b, ra, rb));
	if (ft_max(rra, rrb) <= ft_max(ra, rb)
		&& ft_max(rra, rrb) <= (ft_min(ra, rra) + ft_min(rb, rrb)))
		return (exec_rrr_pa(stack_a, stack_b, rra, rrb));
	if (ra > rra)
		ft_rra(stack_a, rra);
	else
		ft_ra(stack_a, ra);
	if (rb > rrb)
		ft_rrb(stack_b, rrb);
	else
		ft_rb(stack_b, rb);
	ft_pa(stack_a, stack_b);
}

void	lis_sort(t_stack *stack_a, t_stack *stack_b)
{
	t_lis	*lis;

	lis = lis_construct(stack_a, stack_a->size);
	while (stack_a->size != lis->size)
		efficient_pb(stack_a, stack_b, lis);
	while (stack_b->size > 0)
		efficient_pa(stack_a, stack_b, lowest_cost_pa(stack_a, stack_b));
	put_plate_top(stack_a, stack_b, get_smallest_plate(stack_a), 0);
}