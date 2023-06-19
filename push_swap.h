/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: osarsari <osarsari@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/25 13:13:38 by osarsari          #+#    #+#             */
/*   Updated: 2023/06/19 13:58:45 by osarsari         ###   ########.fr       */
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

typedef struct s_stack{
	int	*numbers;
	int	size;
}		t_stack;

int		ft_min(int a, int b);
int		ft_max(int a, int b);
t_bool	ft_is_space(int c);
t_bool	ft_is_int(const char *s);
t_bool	valid_args(int argc, char **argv);
t_stack	*ft_stack_new(int argc);
t_bool	ft_push(t_stack *stack, int value);
t_stack	*fill_stack(int argc, char **argv);
void	free_stack(t_stack *stack);
void	ft_pa(t_stack *stack_a, t_stack *stack_b);
void	ft_pb(t_stack *stack_a, t_stack *stack_b);
void	ft_sa(t_stack *stack);
void	ft_sb(t_stack *stack);
void	ft_ss(t_stack *stack_a, t_stack *stack_b);
t_bool	ft_rotate(t_stack *stack);
void	ft_ra(t_stack *stack, int nb);
void	ft_rb(t_stack *stack, int nb);
void	ft_rr(t_stack *stack_a, t_stack *stack_b, int nb);
t_bool	ft_reverse_rotate(t_stack *stack);
void	ft_rra(t_stack *stack_a, int nb);
void	ft_rrb(t_stack *stack_b, int nb);
void	ft_rrr(t_stack *stack_a, t_stack *stack_b, int nb);
void	sort_three(t_stack *stack);
int		get_smallest_int(t_stack *stack);
int		get_biggest_int(t_stack *stack);
int		get_smaller_int(t_stack *stack, int n);
int		get_bigger_int(t_stack *stack, int n);
int		get_smallest_bigger(t_stack *stack, int n);
void	combined_r(t_stack *stack_a, t_stack *stack_b);
void	combined_rr(t_stack *stack_a, t_stack *stack_b);
void	combined_s(t_stack *stack_a, t_stack *stack_b);
void	sort_under_seven(t_stack *stack_a, t_stack *stack_b);
int		cost_rotate(t_stack *stack, int n);
int		cost_reverse_rotate(t_stack *stack, int n);
int		cost_logic(int ra, int rb, int rra, int rrb);
int		estimated_cost(t_stack *stack_a, t_stack *stack_b, int n);
int		lowest_cost_pa(t_stack *stack_a, t_stack *stack_b);
void	rotate_top(t_stack *stack, int n, char c);
void	efficient_pb(t_stack *stack_a, t_stack *stack_b, t_stack *lis);
void	efficient_pa(t_stack *stack_a, t_stack *stack_b, int to_push);
void	lis_sort(t_stack *stack_a, t_stack *stack_b);
void	ft_sort(t_stack *stack_a, t_stack *stack_b);

#endif