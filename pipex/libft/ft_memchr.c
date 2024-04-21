/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybouaoud <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/02 13:11:25 by ybouaoud          #+#    #+#             */
/*   Updated: 2023/11/24 13:32:23 by ybouaoud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *str, int c, size_t n)
{
	unsigned char	*strn;

	strn = (unsigned char *)str;
	while (n > 0)
	{
		if (*strn == (unsigned char)c)
			return (strn);
		strn++;
		n--;
	}
	return (0);
}
