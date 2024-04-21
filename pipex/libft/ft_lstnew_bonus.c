/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybouaoud <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/09 11:23:26 by ybouaoud          #+#    #+#             */
/*   Updated: 2023/11/11 18:02:07 by ybouaoud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstnew(void *content)
{
	t_list	*main;

	main = (t_list *)malloc(sizeof(t_list));
	if (!main)
		return (NULL);
	main -> content = content;
	main -> next = NULL;
	return (main);
}
