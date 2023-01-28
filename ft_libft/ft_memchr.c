/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: areheman <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/27 13:34:08 by areheman          #+#    #+#             */
/*   Updated: 2022/03/10 15:15:20 by areheman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int n, size_t l)
{
	unsigned char	*p;
	unsigned int	i;

	p = (unsigned char *)s;
	i = 0;
	while (i < l)
	{
		if (p[i] == (unsigned char)n)
			return ((void *)(s + i));
		i++;
	}
	return (0);
}
