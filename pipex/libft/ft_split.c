/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybouaoud <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/04 22:24:41 by ybouaoud          #+#    #+#             */
/*   Updated: 2023/11/20 02:42:01 by ybouaoud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	**free_strs(char **strs)
{
	unsigned int	i;

	i = 0;
	while (strs[i])
	{
		free(strs[i]);
		i++;
	}
	free(strs);
	return (NULL);
}

static size_t	word_count(const char *s, char c)
{
	size_t	count;
	size_t	i;

	count = 0;
	i = 0;
	while (s[i])
	{
		if (s[i] != c)
		{
			count++;
			while (s[i] && s[i] != c)
				i++;
		}
		else
			i++;
	}
	return (count);
}

static char	*ft_strcpy(const char *str, char c)
{
	int		i;
	char	*strs;
	int		slen;

	slen = 0;
	i = 0;
	while (str[slen] != c && str[slen])
		slen++;
	strs = (char *)malloc(sizeof(char) * (slen + 1));
	if (!strs)
		return (0);
	while (i < slen)
	{
		strs[i] = str[i];
		i++;
	}
	strs[i] = '\0';
	return (strs);
}

static int	strs_alloc(char **strs, const char *s, char c)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (s[i] == c)
		i++;
	while (s[i])
	{
		strs[j] = ft_strcpy(&s[i], c);
		if (!strs[j])
			return (1);
		while (s[i] != c && s[i])
			i++;
		while (s[i] == c && c)
			i++;
		j++;
	}
	strs[j] = NULL;
	return (0);
}

char	**ft_split(char const *s, char c)
{
	char	**strs;
	int		w_count;

	if (!s)
		return (NULL);
	if (s[0] == 0)
	{
		strs = (char **)malloc(1 * sizeof(char *));
		if (!strs)
			return (NULL);
		strs[0] = NULL;
		return (strs);
	}
	w_count = word_count(s, c);
	strs = (char **)malloc(sizeof(char *) * (w_count + 1));
	if (!strs)
		return (NULL);
	if (strs_alloc(strs, s, c) == 1)
		return (free_strs(strs));
	return (strs);
}
