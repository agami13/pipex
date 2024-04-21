/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybouaoud <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/25 01:44:57 by ybouaoud          #+#    #+#             */
/*   Updated: 2023/12/06 18:43:58 by ybouaoud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static unsigned int	num_len(int num)
{
	unsigned int	len;

	len = 0;
	if (num == 0)
		return (1);
	if (num < 0)
	{
		len += 1;
	}
	while (num != 0)
	{
		num /= 10;
		len++;
	}
	return (len);
}

int	ft_putnbr(int n)
{
	char	*num;

	num = ft_itoa(n);
	ft_putstr(num);
	free(num);
	return (num_len(n));
}
