/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbruma <sbruma@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/10 11:22:42 by sbruma            #+#    #+#             */
/*   Updated: 2024/05/16 12:04:31 by sbruma           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/libft.h"

static void	*free_split(char **split, size_t length)
{
	if (!split)
		return (NULL);
	while (length-- > 0)
		free (split[length]);
	free (split);
	return (NULL);
}

static int	count_splits(const char *str, char c)
{
	int	count;
	int	sep_found;

	count = 0;
	sep_found = 0;
	while (*str)
	{
		if (*str != c && sep_found == 0)
		{
			sep_found = 1;
			count++;
		}
		else if (*str == c)
			sep_found = 0;
		str++;
	}
	return (count);
}

static char	*split_dup(const char *str, int start, int finish)
{
	char	*split;
	int		i;

	i = 0;
	split = malloc((finish - start + 1) * sizeof(char));
	if (!split)
		return (NULL);
	while (start < finish)
		split[i++] = str[start++];
	split[i] = '\0';
	return (split);
}

static char	**process(char const *s, char c, char **split)
{
	int	i;
	int	iarr;
	int	index;

	i = -1;
	iarr = 0;
	index = -1;
	while (s[++i] || index >= 0)
	{
		if (s[i] != c && index < 0)
			index = i;
		else if ((s[i] == c || s[i + 1] == '\0') && index >= 0)
		{
			if (s[i] == c)
				split[iarr] = split_dup(s, index, i);
			else if (s[i + 1] == '\0')
				split[iarr] = split_dup(s, index, i + 1);
			if (!split[iarr++])
				return (free_split(split, iarr));
			index = -1;
		}
	}
	split[iarr] = NULL;
	return (split);
}

char	**ft_split(char const *s, char c)
{
	char	**split;

	if (!s)
		return (NULL);
	split = malloc((count_splits(s, c) + 1) * sizeof(char *));
	if (!split)
		return (NULL);
	split = process(s, c, split);
	if (!split)
		return (NULL);
	return (split);
}
