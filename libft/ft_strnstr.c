/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybouaoud <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/02 13:51:30 by ybouaoud          #+#    #+#             */
/*   Updated: 2023/11/20 01:34:35 by ybouaoud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	size_t	j;
	size_t	i;

	j = 0;
	if (!big && len == 0)
		return (NULL);
	if (little[0] == '\0')
		return ((char *)big);
	while (big[j] != '\0')
	{
		i = 0;
		while (big[j + i] == little[i] && (j + i) < len)
		{
			if (big[j + i] == '\0' && little[i] == '\0')
				return ((char *)&big[j]);
			i++;
		}
		if (little[i] == '\0')
			return ((char *)big + j);
		j++;
	}
	return (0);
}
