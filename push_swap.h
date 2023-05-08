/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: osarsari <osarsari@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/02 08:25:41 by osarsari          #+#    #+#             */
/*   Updated: 2023/05/08 12:40:14 by osarsari         ###   ########.fr       */
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

typedef struct s_stack
{
	struct s_stack	*left;
	struct s_stack	*right;
	int				value;
	t_bool			first;
}					t_stack;

t_bool	valid_args(int argc, char **argv);
void	ft_sort(int argc, char **argv);
t_stack	*ft_stacknew(int i);
t_bool	ft_isspace(int c);
t_bool	ft_isint(const char *s);

#endif