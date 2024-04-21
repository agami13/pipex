/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybouaoud <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/04 11:42:26 by ybouaoud          #+#    #+#             */
/*   Updated: 2023/11/18 21:59:45 by ybouaoud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	size_t	i;
	size_t	j;
	size_t	full_len;
	char	*rs;

	j = 0;
	i = 0;
	if (!s1 || !s2)
		return (NULL);
	full_len = ft_strlen(s1) + ft_strlen(s2);
	rs = (char *)malloc(sizeof(char) * (full_len + 1));
	if (!rs)
		return (NULL);
	while (s1[i] != '\0' && i < full_len)
	{
		rs[i] = s1[i];
		i++;
	}
	while (s2[j] != '\0' && j < full_len)
	{
		rs[i + j] = s2[j];
		j++;
	}
	rs[i + j] = '\0';
	return (rs);
}
