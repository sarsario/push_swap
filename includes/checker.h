/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: osarsari <osarsari@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/07 17:04:32 by osarsari          #+#    #+#             */
/*   Updated: 2023/08/09 12:33:00 by osarsari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHECKER_H
# define CHECKER_H
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
int		ft_swap(t_stack *stack);
int		ft_push(t_stack *src, t_stack *dst);
int		ft_push_stack(t_stack *src, t_stack *dst);
int		ft_rotate(t_stack *stack);
int		ft_reverse_rotate(t_stack *stack);
int		ft_read_instructions(t_stack *a, t_stack *b);
int		ft_is_sorted(t_stack *stack);
int		ft_exec_swap(t_stack *a, t_stack *b, char *op);
int		ft_exec_push(t_stack *a, t_stack *b, char *op);
int		ft_exec_rotate(t_stack *a, t_stack *b, char *op);
int		get_next_line(int fd, char **line);
int		ft_is_sorted(t_stack *stack);

#endif