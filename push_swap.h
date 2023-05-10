/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: osarsari <osarsari@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/02 08:25:41 by osarsari          #+#    #+#             */
/*   Updated: 2023/05/11 00:25:52 by osarsari         ###   ########.fr       */
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
t_stack	*ft_stack_new(int value);
t_plate	*ft_plate_new(t_plate *next, int value);
t_stack	*fill_stack(int argc, char **argv);
t_bool	ft_push(t_stack *stack, int value);
t_bool	ft_pop(t_stack *stack, int *value);
t_bool	ft_push_stack(t_stack *src, t_stack *dst);
t_bool	ft_swap(t_stack *stack);
t_bool	ft_rotate(t_stack *stack);
t_bool	ft_reverse_rotate(t_stack *stack);
void	ft_print_stack(t_stack *stack);
t_bool	stack_is_sorted(t_stack *stack);
void	ft_sort(t_stack *stack_a, t_stack *stack_b);

#endif