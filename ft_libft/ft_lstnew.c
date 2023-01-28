/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: areheman <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/14 16:41:35 by areheman          #+#    #+#             */
/*   Updated: 2022/03/15 16:48:12 by areheman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstnew(void *content)
{
	t_list	*t_l;

	t_l = (t_list *)malloc(sizeof(t_list));
	if (!t_l)
		return (0);
	t_l->content = content;
	t_l->next = NULL;
	return (t_l);
}
