/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybouaoud <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/31 11:49:23 by ybouaoud          #+#    #+#             */
/*   Updated: 2023/11/18 23:20:09 by ybouaoud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	unsigned char	*destp;
	unsigned char	*srcp;
	size_t			i;

	destp = (unsigned char *)dest;
	srcp = (unsigned char *)src;
	if (dest == src)
		return (dest);
	if (srcp < destp && srcp + n > destp)
	{
		i = n;
		while (i > 0)
		{
			i--;
			(destp)[i] = (srcp)[i];
		}
	}
	else
		ft_memcpy(dest, src, n);
	return (dest);
}
