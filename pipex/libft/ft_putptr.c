/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putptr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybouaoud <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/25 19:09:16 by ybouaoud          #+#    #+#             */
/*   Updated: 2023/11/25 23:48:5 by ybouaoud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_putptr(size_t num)
{
	int	rs;

	rs = 0;
	if (num == 0)
	{
		ft_putstr("(nil)");
		return (5);
	}
	ft_putstr("0x");
	rs = ft_printhex(num, 16, 'x') + 2;
	return (rs);
}
