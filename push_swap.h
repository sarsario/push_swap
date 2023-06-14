/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: osarsari <osarsari@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/25 13:13:38 by osarsari          #+#    #+#             */
/*   Updated: 2023/06/14 19:27:06 by osarsari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H

# define PUSH_SWAP_H
# ifndef INT_MAX
#  define INT_MAX 2147483647
# endif
# ifndef INT_MIN
#  define INT_MIN -2147483648
# endif
# include "Lib/libft.h"

typedef enum e_bool{
	false,
	true
}	t_bool;

typedef struct s_plate{
	struct s_plate	*prev;
	struct s_plate	*next;
	int				value;
	int				position;
	int				sorted_position;
}					t_plate;

typedef struct s_stack{
	struct s_plate	*top;
	struct s_plate	*bot;
	int				size;
}					t_stack;

t_bool	ft_is_space(int c);
t_bool	ft_int_overflow(const char *s, const char sign);
t_bool	ft_is_int(const char *s);
t_bool	valid_args(int argc, char **argv);
void	free_stack(t_stack *stack);
t_stack	*ft_stack_new(void);
t_plate	*ft_plate_new(t_plate *next, int value);
t_bool	ft_push(t_stack *stack, int value);
t_bool	ft_pop(t_stack *stack, int *value);
t_plate	*get_smallest_plate(t_stack *stack);
t_plate	*get_biggest_plate(t_stack *stack);
t_plate	*get_smaller_plate(t_stack *stack, t_plate *plate);
t_plate	*get_bigger_plate(t_stack *stack, t_plate *plate);
void	position_after_fill(t_stack *stack);
t_stack	*fill_stack(int argc, char **argv);
void	update_position(t_stack *stack);
t_bool	stack_is_asc(t_stack *stack);
t_bool	stack_is_dsc(t_stack *stack);
t_bool	ft_push_stack(t_stack *src, t_stack *dst);
void	ft_pa(t_stack *stack_a, t_stack *stack_b);
void	ft_pb(t_stack *stack_a, t_stack *stack_b);
t_bool	ft_swap(t_stack *stack);
void	ft_sa(t_stack *stack_a);
void	ft_sb(t_stack *stack_b);
void	ft_ss(t_stack *stack_a, t_stack *stack_b);
void	try_ss_before_sa(t_stack *stack_a, t_stack *stack_b);
void	try_ss_before_sb(t_stack *stack_a, t_stack *stack_b);
t_bool	ft_rotate(t_stack *stack);
void	ft_ra(t_stack *stack_a, int nb);
void	ft_rb(t_stack *stack_b, int nb);
void	ft_rr(t_stack *stack_a, t_stack *stack_b, int nb);
void	try_rr_before_ra(t_stack *stack_a, t_stack *stack_b, int nb);
void	try_rr_before_rb(t_stack *stack_a, t_stack *stack_b, int nb);
t_bool	ft_reverse_rotate(t_stack *stack);
void	ft_rra(t_stack *stack_a, int nb);
void	ft_rrb(t_stack *stack_b, int nb);
void	ft_rrr(t_stack *stack_a, t_stack *stack_b, int nb);
void	try_rrr_before_rra(t_stack *stack_a, t_stack *stack_b, int nb);
void	try_rrr_before_rrb(t_stack *stack_a, t_stack *stack_b, int nb);
void	sort_two(t_stack *stack_a, t_stack *stack_b);
void	sort_three(t_stack *stack_a, t_stack *stack_b);
void	pre_sort_pb(t_stack *stack_a, t_stack *stack_b, int pivot);
int		distance_top_rotate(t_stack *stack, t_plate *plate);
int		distance_top_reverse_rotate(t_stack *stack, t_plate *plate);
// Trying to include this part
int		cost_rotate_top(t_stack *stack, t_plate *plate);
int		cost_reverse_top(t_stack *stack, t_plate *plate);
t_plate	*find_biggest_smaller(t_stack *stack, t_plate *plate);
t_plate	*find_smallest_bigger(t_stack *stack, t_plate *to_move);
int		get_cost_indiv(int cost_ra, int cost_rb, int cost_rra, int cost_rrb);
int		get_cost_comb(int cost_ra, int cost_rb, int cost_rra, int cost_rrb);
int		cost_trick(int cost_ra, int cost_rb, int cost_rra, int cost_rrb);
int		ft_cost_pa(t_stack *stack_a, t_stack *stack_b, t_plate *to_move);
int		ft_cost_pb(t_stack *stack_a, t_stack *stack_b, t_plate *to_move);
void	best_move_top_a(t_stack *stack, t_plate *to_top);
void	align_stacks_pb(t_stack *stack_a, t_stack *stack_b, t_plate *to_move);
void	align_stacks_pa(t_stack *stack_a, t_stack *stack_b, t_plate *to_move);
t_plate	*best_plate_pb(t_stack *stack_a, t_stack *stack_b, int staying_value);
t_plate	*best_plate_pa(t_stack *stack_a, t_stack *stack_b);
void	optimal_pa(t_stack *stack_a, t_stack *stack_b);
void	upper_half_pa(t_stack *stack_a, t_stack *stack_b);
t_plate	*best_plate_pa_half(t_stack *stack_a, t_stack *stack_b, int staying_value);
// End of include
void	put_plate_top(t_stack *stack_a,
			t_stack *stack_b,
			t_plate *plate,
			int i);
void	sort_five(t_stack *stack_a, t_stack *stack_b);
void	sort_small_stack(t_stack *stack_a, t_stack *stack_b);
void	optimal_half_pb(t_stack *stack_a, t_stack *stack_b,
			int value);
void	lower_half_pb(t_stack *stack_a, t_stack *stack_b);
// void	top_half_pa(t_stack *stack_a, t_stack *stack_b);
void	quick_sort(t_stack *stack_a, t_stack *stack_b);
void	cost_sort(t_stack *stack_a, t_stack *stack_b);
void	ft_sort(t_stack *stack_a, t_stack *stack_b);

#endif