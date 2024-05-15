/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybouaoud <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/09 19:52:22 by ybouaoud          #+#    #+#             */
/*   Updated: 2023/11/09 23:16:42 by ybouaoud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void *))
{
	t_list	*temp;
	t_list	*n;

	n = *lst;
	if (!del || !lst)
		return ;
	while (n)
	{
		temp = n -> next;
		ft_lstdelone(n, del);
		n = temp;
	}
	*lst = NULL;
}
