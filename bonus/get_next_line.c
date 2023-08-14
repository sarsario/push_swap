/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: osarsari <osarsari@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/09 09:52:18 by osarsari          #+#    #+#             */
/*   Updated: 2023/08/14 16:12:49 by osarsari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/checker.h"

int	get_next_line(int fd, char **line)
{
	int		i;

	i = 0;
	while (i < 4 && read(fd, &line[0][i], 1) > 0)
	{
		if (line[0][i] != '\n' && ft_isspace(line[0][i]))
			return (1);
		if (line[0][i] == '\n')
		{
			line[0][i] = '\0';
			return (1);
		}
		i++;
	}
	if (i == 0)
		return (0);
	return (1);
}
