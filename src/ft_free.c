/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: osarsari <osarsari@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/01 16:35:04 by osarsari          #+#    #+#             */
/*   Updated: 2023/08/02 07:57:52 by osarsari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

char	**ft_deep_free(char **arr1, char **arr2)
{
	if (arr1)
		ft_free_args(arr1, 0);
	if (arr2)
		ft_free_args(arr2, 0);
	return (NULL);
}

void	ft_double_free(char **arr1, char **arr2)
{
	if (arr1)
		free(arr1);
	if (arr2)
		free(arr2);
}

int	ft_free_args(char **args, int ret)
{
	int	i;

	if (!args)
		return (ret);
	i = -1;
	while (args[++i])
		free(args[i]);
	free(args);
	return (ret);
}
