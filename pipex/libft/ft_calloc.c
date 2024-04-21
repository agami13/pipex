/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybouaoud <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/02 13:03:03 by ybouaoud          #+#    #+#             */
/*   Updated: 2023/12/11 08:59:51 by ybouaoud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>

void	*ft_calloc(size_t nmemb, size_t size)
{
	void	*mmr;

	if (nmemb && size && (nmemb > 4294967295 / size))
		return (NULL);
	mmr = malloc(nmemb * size);
	if (!mmr)
		return (NULL);
	if ((nmemb * size) != 0)
		ft_bzero(mmr, nmemb * size);
	else
		ft_bzero(mmr, 1);
	return (mmr);
}
