/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybouaoud <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/02 13:14:56 by ybouaoud          #+#    #+#             */
/*   Updated: 2023/11/20 00:35:57 by ybouaoud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	unsigned char		*destp;
	const unsigned char	*srcp;

	if (dest == src)
		return (dest);
	destp = (unsigned char *)dest;
	srcp = (const unsigned char *)src;
	if (!dest && !src)
		return (NULL);
	while (n)
	{
		*destp++ = *srcp++;
		n--;
	}
	return (dest);
}
