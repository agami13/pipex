/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstsize_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybouaoud <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/09 11:55:58 by ybouaoud          #+#    #+#             */
/*   Updated: 2023/11/17 13:29:13 by ybouaoud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_lstsize(t_list *lst)
{
	int		i;
	t_list	*head;

	if (!lst)
		return (0);
	head = lst;
	i = 0;
	while (head != NULL)
	{
		head = head -> next;
		i++;
	}
	return (i);
}
