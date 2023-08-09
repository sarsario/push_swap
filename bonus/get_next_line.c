/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: osarsari <osarsari@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/09 09:52:18 by osarsari          #+#    #+#             */
/*   Updated: 2023/08/09 11:21:31 by osarsari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/checker.h"

int	get_next_line(int fd, char **line)
{
	static char	str[4];
	int			i;

	i = 0;
	while (read(fd, &str[i], 1) > 0 && i < 4)
	{
		if (str[i] == '\n')
		{
			*line = ft_strdup(str);
			if (!*line)
				return (0);
			str[0] = '\0';
			return (1);
		}
		i++;
	}
	if (i == 0)
		return (0);
	*line = ft_strdup(str);
	if (!*line)
		return (0);
	str[0] = '\0';
	return (1);
}
