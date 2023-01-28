/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: areheman <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/02 17:30:39 by areheman          #+#    #+#             */
/*   Updated: 2022/03/14 13:32:02 by areheman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	*put_strs(char const *s1, unsigned int start, size_t len)
{
	char	*p;
	size_t	i;

	p = (char *)malloc(sizeof(char) * len + 1);
	if (!p)
		return (0);
	i = 0;
	while (i < len)
	{
		p[i++] = s1[start++];
	}	
	p[i] = '\0';
	return (p);
}

char	*ft_substr(char const *s1, unsigned int start, size_t len)
{
	char				*s2;

	if (!s1)
		return (0);
	if (start >= ft_strlen(s1))
	{
		s2 = (char *)malloc(sizeof(char));
		if (!s2)
			return (0);
		s2[0] = '\0';
		return (s2);
	}
	else
	{
		if (len > ft_strlen(s1) - start)
			len = ft_strlen(s1) - start;
		s2 = put_strs(s1, start, len);
		return (s2);
	}
}
