/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sanitize.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: osarsari <osarsari@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/25 11:57:11 by osarsari          #+#    #+#             */
/*   Updated: 2023/08/02 08:45:30 by osarsari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

static char	**ft_strjoin_array(char **arr1, char **arr2)
{
	char	**join;
	int		i;
	int		j;
	int		join_len;

	i = ft_array_len(arr1);
	j = ft_array_len(arr2);
	if (!arr1 && !arr2)
		return (NULL);
	join_len = i + j + 1;
	join = ft_calloc(join_len, sizeof(char *));
	if (!join)
		return (NULL);
	i = -1;
	while (++i > -2 && arr1 && arr1[i])
		join[i] = arr1[i];
	j = -1;
	while (++j > -2 && arr2 && arr2[j])
		join[i + j] = arr2[j];
	return (join);
}

char	**ft_sanitize(int argc, char **argv)
{
	char	**args;
	char	**tmp;
	char	**old_args;
	int		i;

	args = NULL;
	i = 1;
	while (i < argc)
	{
		tmp = ft_split_whitespaces(argv[i]);
		if (!tmp)
			return (ft_deep_free(args, tmp));
		old_args = args;
		args = ft_strjoin_array(args, tmp);
		if (!args)
			return (ft_deep_free(old_args, tmp));
		ft_double_free(old_args, tmp);
		i++;
	}
	return (args);
}
