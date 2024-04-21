/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybouaoud <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/04 11:41:24 by ybouaoud          #+#    #+#             */
/*   Updated: 2023/11/09 15:27:47 by ybouaoud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	size_t	i;
	char	*rtr;

	i = 0;
	if (!s || start >= ft_strlen(s))
		return (ft_strdup(""));
	if (len > ft_strlen(s) - start)
		len = ft_strlen(s) - start;
	rtr = (char *)malloc(len + 1);
	if (!rtr)
		return (0);
	while (s[start] && len > 0)
	{
		rtr[i++] = s[start++];
		len--;
	}
	rtr[i] = '\0';
	return (rtr);
}
