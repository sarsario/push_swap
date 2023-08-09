/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: osarsari <osarsari@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/25 11:13:49 by osarsari          #+#    #+#             */
/*   Updated: 2023/08/07 16:06:52 by osarsari         ###   ########.fr       */
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

# include "./lib/libft.h"

typedef struct s_stack {
	int	*stack;
	int	size;
}		t_stack;

int		ft_stack_new(t_stack *stack, int size);
int		ft_init_stack(t_stack *stack, int argc, char **argv);
char	**ft_sanitize(int argc, char **argv);
char	**ft_split_whitespaces(char *str);
char	**ft_deep_free(char **arr1, char **arr2);
void	ft_double_free(char **arr1, char **arr2);
int		ft_free_args(char **args, int ret);
int		ft_valid_args(char **args);
void	ft_pa(t_stack *a, t_stack *b);
void	ft_pb(t_stack *a, t_stack *b);
void	ft_sa(t_stack *a);
void	ft_sb(t_stack *b);
void	ft_ss(t_stack *a, t_stack *b);
void	ft_ra(t_stack *a);
void	ft_rb(t_stack *b);
void	ft_rr(t_stack *a, t_stack *b);
void	ft_rra(t_stack *a);
void	ft_rrb(t_stack *b);
void	ft_rrr(t_stack *a, t_stack *b);
int		ft_is_sorted(t_stack *stack);
int		ft_sort(t_stack *a, t_stack *b);
int		ft_min_value(t_stack *stack);
int		ft_max_value(t_stack *stack);
int		ft_bigger_value(t_stack *stack, int value);
int		ft_smaller_value(t_stack *stack, int value);
void	ft_pb_pivot(t_stack *a, t_stack *b, int pivot);
void	combined_r(t_stack *a, t_stack *b);
void	combined_rr(t_stack *a, t_stack *b);
void	combined_s(t_stack *a, t_stack *b);
void	ft_sort_three(t_stack *stack);
void	ft_sort_hundred(t_stack *a, t_stack *b);
int		cost_rotate(t_stack *stack, int n);
int		cost_reverse_rotate(t_stack *stack, int n);
int		cost_logic(int ra, int rb, int rra, int rrb);
int		lowest_rotate_cost_pa(t_stack *stack_a, t_stack *stack_b);
int		lowest_reverse_rotate_cost_pa(t_stack *stack_a, t_stack *stack_b);
void	ft_ra_n(t_stack *a, int n);
void	ft_rra_n(t_stack *a, int n);
void	ft_rb_n(t_stack *b, int n);
void	ft_rrb_n(t_stack *b, int n);
void	ft_rr_n(t_stack *a, t_stack *b, int n);
void	ft_rrr_n(t_stack *a, t_stack *b, int n);
int		can_rr(int ra, int rb, int rra, int rrb);
int		can_rrr(int ra, int rb, int rra, int rrb);
void	exec_rr_pa(t_stack *a, t_stack *b, int ra, int rb);
void	exec_rrr_pa(t_stack *a, t_stack *b, int rra, int rrb);
void	ft_best_rotate(t_stack *stack);
int		ft_min(int a, int b);
int		ft_max(int a, int b);
int		get_smallest_bigger(t_stack *stack, int n);
int		estimated_cost(t_stack *a, t_stack *b, int n);

#endif
