/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: areheman <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/28 10:42:51 by areheman          #+#    #+#             */
/*   Updated: 2022/02/28 12:49:56 by areheman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t l)
{
	size_t			i;
	unsigned char	*d;
	unsigned char	*s;

	i = 0 ;
	if (!dst && !src)
		return (0);
	d = (unsigned char *)dst;
	s = (unsigned char *)src;
	if (s < d)
	{
		while (l--)
			d[l] = s[l];
	}
	else
	{
		while (i < l)
		{
			d[i] = s[i];
			i++;
		}
	}
	return (dst);
}
