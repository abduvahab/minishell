/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: areheman <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/28 13:57:17 by areheman          #+#    #+#             */
/*   Updated: 2022/03/10 14:25:46 by areheman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcpy(char *dst, const char *src, size_t l)
{
	size_t	i;
	size_t	lh;

	lh = ft_strlen(src);
	if (l == 0)
		return (lh);
	i = 0;
	while (src[i] && (i < l - 1))
	{
		dst[i] = *(src + i);
		i++;
	}
	dst[i] = '\0';
	return (lh);
}
