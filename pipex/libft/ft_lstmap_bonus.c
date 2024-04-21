/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybouaoud <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/09 23:17:33 by ybouaoud          #+#    #+#             */
/*   Updated: 2023/11/20 02:45:55 by ybouaoud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*new;
	t_list	*temp;
	void	*tmp;

	new = NULL;
	temp = NULL;
	if (!lst || !f || !del)
		return (NULL);
	while (lst)
	{
		tmp = f(lst -> content);
		temp = ft_lstnew(tmp);
		if (!temp)
		{
			del(tmp);
			ft_lstclear(&new, del);
			return (NULL);
		}
		ft_lstadd_back(&new, temp);
		lst = lst -> next;
	}
	return (new);
}
