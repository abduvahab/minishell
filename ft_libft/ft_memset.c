/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: areheman <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/27 10:43:15 by areheman          #+#    #+#             */
/*   Updated: 2022/03/10 14:42:40 by areheman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *s, int c, size_t l)
{
	unsigned char	*b_s;

	b_s = (unsigned char *)s;
	while (l--)
	{
		*(b_s++) = (unsigned char)c;
	}
	return (s);
}
