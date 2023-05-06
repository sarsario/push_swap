/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: osarsari <osarsari@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/02 08:25:41 by osarsari          #+#    #+#             */
/*   Updated: 2023/05/06 23:34:38 by osarsari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H

# define PUSH_SWAP_H
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
	t_bool			last;
}					t_stack;

t_stack	*ft_stacknew(char *s);
t_bool	ft_isnbr(const char *s);
t_bool	ft_isint(const char *s);
t_bool	is_unique(char **argv, int i);

#endif