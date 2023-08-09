/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split_whitespaces.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: osarsari <osarsari@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/26 15:46:10 by osarsari          #+#    #+#             */
/*   Updated: 2023/08/01 16:33:02 by osarsari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

static int	ft_extract_word(char *str, int *i, char **split, int *j)
{
	int	word_start;
	int	word_end;

	word_start = *i;
	while (str[*i] && !ft_isspace(str[*i]))
		(*i)++;
	word_end = *i;
	split[*j] = ft_substr(str, word_start, word_end - word_start);
	if (!split[*j])
		return (0);
	(*j)++;
	return (1);
}

static int	ft_count_words(char *str)
{
	int	i;
	int	count_words;

	i = 0;
	count_words = 0;
	while (str[i])
	{
		if (ft_isspace(str[i]))
			i++;
		else
		{
			count_words++;
			while (str[i] && !ft_isspace(str[i]))
				i++;
		}
	}
	return (count_words);
}

char	**ft_split_whitespaces(char *str)
{
	char	**split;
	int		i;
	int		j;
	int		word_count;

	i = 0;
	j = 0;
	word_count = ft_count_words(str);
	if (!word_count)
		return (NULL);
	split = ft_calloc(word_count + 1, sizeof(char *));
	if (!split)
		return (NULL);
	while (str[i])
	{
		if (ft_isspace(str[i]))
			i++;
		else if (!ft_extract_word(str, &i, split, &j))
			return (ft_deep_free(split, NULL));
	}
	return (split);
}
