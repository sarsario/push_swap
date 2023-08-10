/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_read_instructions.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: osarsari <osarsari@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/07 17:31:28 by osarsari          #+#    #+#             */
/*   Updated: 2023/08/10 13:26:49 by osarsari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/checker.h"

int	ft_exec_instruction(t_stack *a, t_stack *b, char *line)
{
	if (*line == 's')
		return (ft_exec_swap(a, b, line));
	else if (*line == 'p')
		return (ft_exec_push(a, b, line));
	else if (*line == 'r')
		return (ft_exec_rotate(a, b, line));
	else
		return (0);
}

int	valid_instruction(char *str)
{
	if (!ft_strncmp(str, "sa", 2) || !ft_strncmp(str, "sb", 2)
		|| !ft_strncmp(str, "ss", 2) || !ft_strncmp(str, "pa", 2)
		|| !ft_strncmp(str, "pb", 2) || !ft_strncmp(str, "ra", 2)
		|| !ft_strncmp(str, "rb", 2) || !ft_strncmp(str, "rr", 2)
		|| !ft_strncmp(str, "rra", 3) || !ft_strncmp(str, "rrb", 3)
		|| !ft_strncmp(str, "rrr", 3))
		return (1);
	return (0);
}

int	ft_read_instructions(t_stack *a, t_stack *b)
{
	char	*line;

	line = ft_calloc(4, sizeof(char));
	if (!line)
		return (0);
	while (get_next_line(0, &line))
	{
		if (!valid_instruction(line))
		{
			free(line);
			return (0);
		}
		if (!ft_exec_instruction(a, b, line))
		{
			free(line);
			return (0);
		}
		ft_bzero(line, 4);
	}
	if (line)
		free(line);
	return (1);
}
