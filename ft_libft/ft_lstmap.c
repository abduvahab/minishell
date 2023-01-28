/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: areheman <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/16 14:47:42 by areheman          #+#    #+#             */
/*   Updated: 2022/03/18 16:42:15 by areheman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*new;
	t_list	*n_next;

	if (lst && f)
	{
		new = ft_lstnew(f(lst->content));
		if (!new)
			return (0);
		n_next = new;
		while (lst->next)
		{
			lst = lst->next;
			n_next->next = ft_lstnew(f(lst->content));
			if (!(n_next->next))
			{
				ft_lstclear(&new, del);
				return (0);
			}
			n_next = n_next->next;
		}
		return (new);
	}
	else
		return (0);
}
