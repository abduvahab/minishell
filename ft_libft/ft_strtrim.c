/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: areheman <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/04 09:07:04 by areheman          #+#    #+#             */
/*   Updated: 2022/03/18 16:27:33 by areheman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s1, char const *set)
{
	char		*new_s;
	size_t		i;
	size_t		j;

	i = 0;
	while (ft_memchr(set, *(s1 + i), ft_strlen(set)))
		i++;
	if (i == ft_strlen(s1))
	{
		new_s = malloc(1);
		*new_s = '\0';
	}
	else
	{
		j = 0;
		while (ft_memchr(set, *(s1 + ft_strlen(s1) - 1 - j), ft_strlen(set)))
			j++;
		new_s = ft_substr(s1, i, ft_strlen(s1) - i - j);
	}
	return (new_s);
}
