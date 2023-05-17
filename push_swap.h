/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: osarsari <osarsari@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/02 08:25:41 by osarsari          #+#    #+#             */
/*   Updated: 2023/05/17 15:45:15 by osarsari         ###   ########.fr       */
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

typedef struct s_plate
{
	struct s_plate	*prev;
	struct s_plate	*next;
	int				value;
	int				position;
	int				sorted_position;
}					t_plate;

typedef struct s_stack
{
	struct s_plate	*top;
	struct s_plate	*bottom;
	size_t			size;
}					t_stack;

t_bool	valid_args(int argc, char **argv);
t_bool	ft_isint(const char *s);
t_bool	ft_isspace(int c);
t_stack	*ft_stack_new(void);
t_plate	*ft_plate_new(t_plate *next, int value);
void	position_after_fill(t_stack *stack);
t_stack	*fill_stack(int argc, char **argv);
int		distance_top(t_stack *stack, t_plate *plate);
int		distance_bot(t_stack *stack, t_plate *plate);
t_bool	ft_push(t_stack *stack, int value);
t_bool	ft_pop(t_stack *stack, int *value);
t_bool	ft_push_stack(t_stack *src, t_stack *dst);
void	run_push_stack(t_stack *src, t_stack *dst, char name);
void	run_cheapest_push(t_stack *src, t_stack *dst, t_plate *plate);
t_bool	ft_swap(t_stack *stack);
void	run_swap(t_stack *stack, char name);
t_bool	ft_rotate(t_stack *stack);
void	run_rotate(t_stack *stack, char name);
void	repeat_rotate(t_stack *stack, int nb, char name);
t_bool	ft_reverse_rotate(t_stack *stack);
void	run_reverse_rotate(t_stack *stack, char name);
void	repeat_reverse_rotate(t_stack *stack, int nb, char name);
void	ft_print_stack(t_stack *stack);
t_bool	stack_is_asc(t_stack *stack);
t_bool	stack_is_dsc(t_stack *stack);
void	sort_two(t_stack *stack);
void	sort_three(t_stack *stack);
void	sort_small_stack(t_stack *stack_a, t_stack *stack_b);
t_plate	*get_smallest_plate(t_stack *stack);
t_plate	*get_smaller_plate(t_stack *stack, t_plate *plate);
t_plate	*get_biggest_plate(t_stack *stack);
t_plate	*get_bigger_plate(t_stack *stack, t_plate *plate);
void	selection_sort(t_stack *stack_a, t_stack *stack_b);
void	ft_sort(t_stack *stack_a, t_stack *stack_b);

#endif