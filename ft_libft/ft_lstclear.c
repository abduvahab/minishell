/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: areheman <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/16 12:42:42 by areheman          #+#    #+#             */
/*   Updated: 2022/03/16 13:56:13 by areheman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void *))
{
	t_list	*current;
	t_list	*next;

	if (lst)
	{	
		current = *lst;
		while (current)
		{
			next = current->next;
			ft_lstdelone(current, del);
			current = next;
		}
		*lst = NULL;
	}
}
