/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: osarsari <osarsari@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/05 11:05:34 by osarsari          #+#    #+#             */
/*   Updated: 2023/05/06 12:06:16 by osarsari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

/*
** Trims leading and trailing characters specified in set from a string s1,
** and returns a newly allocated string with the trimmed result.
**
** s1:	The string to trim.
** set:	The set of characters to trim from s1.
**
** Returns:
** The trimmed string, or NULL if the allocation fails.
*/

char	*ft_strtrim(char const *s1, char const *set)
{
	char const	*start;
	char const	*end;
	char		*result;
	size_t		len;

	if (!s1 || !set)
		return (NULL);
	start = s1;
	while (*start && ft_strchr(set, *start))
		start++;
	end = s1 + ft_strlen(s1) - 1;
	while (end > start && ft_strchr(set, *end))
		end--;
	len = end - start + 1;
	result = ft_substr(start, 0, len);
	return (result);
}

//Old version

/*
** Searches for a character in a string.
**
** c:	The character to search for.
** set:	The string in which to search.
**
** Returns:
** 1 if the character is found in the string, 0 otherwise.
*/

// static int	ft_char_in_str(char const c, char const *set)
// {
// 	if (!set)
// 		return (0);
// 	while (*set)
// 	{
// 		if (*set == c)
// 			return (1);
// 		set++;
// 	}
// 	return (0);
// }

// char	*ft_strtrim(char const *s1, char const *set)
// {
// 	char	*trimmed;
// 	char	*start;
// 	char	*end;

// 	if (!s1 || !set)
// 		return (NULL);
// 	start = (char *)s1;
// 	end = start + ft_strlen(s1) - 1;
// 	while (*start && ft_char_in_str(*start, set))
// 		start++;
// 	while (end > start && ft_char_in_str(*end, set))
// 		end--;
// 	trimmed = (char *)malloc(sizeof(char) * (end - start + 2));
// 	if (!trimmed)
// 		return (NULL);
// 	ft_strlcpy(trimmed, start, end - start + 2);
// 	return (trimmed);
// }