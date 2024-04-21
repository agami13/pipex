/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printhex.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybouaoud <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/22 18:33:11 by ybouaoud          #+#    #+#             */
/*   Updated: 2023/12/06 18:39:24 by ybouaoud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_printhex(size_t n, size_t base, char c)
{
	int		count;
	char	*base_16;

	count = 0;
	if (c == 'x')
		base_16 = "0123456789abcdef";
	else if (c == 'X')
		base_16 = "0123456789ABCDEF";
	if (n < base)
	{
		count += ft_putchar(base_16[n % base]);
		return (count);
	}
	if (n >= base)
	{
		count += ft_printhex(n / base, base, c);
		count += ft_putchar(base_16[n % base]);
	}
	return (count);
}
