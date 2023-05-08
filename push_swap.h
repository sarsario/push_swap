/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: osarsari <osarsari@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/02 08:25:41 by osarsari          #+#    #+#             */
/*   Updated: 2023/05/08 23:28:42 by osarsari         ###   ########.fr       */
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
# include "./Lib/libft.h"

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
	struct s_stack	*top;
	struct s_stack	*bottom;
	size_t			size;
}					t_stack;

t_bool	valid_args(int argc, char **argv);
t_stack	*pile_stack(int argc, char **argv);
t_bool	ft_push(t_stack *stack_a, int value);
t_bool	ft_pop(t_stack *stack_a, int *value);
t_bool  ft_push_from_to(t_stack *stack_a, t_stack *stack_b);
void	ft_sort(t_stack *stack_a);
t_bool	ft_isspace(int c);
t_bool	ft_isint(const char *s);

#endif