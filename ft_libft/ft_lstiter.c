/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstiter.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: areheman <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/16 14:36:05 by areheman          #+#    #+#             */
/*   Updated: 2022/03/16 14:46:43 by areheman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstiter(t_list *lst, void (*f)(void *))
{
	if (lst)
	{
		if (f)
		{
			f(lst->content);
			while (lst->next)
			{
				lst = lst->next;
				f(lst->content);
			}
		}
	}
}
