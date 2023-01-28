/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putendl_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: areheman <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/14 15:27:55 by areheman          #+#    #+#             */
/*   Updated: 2022/03/14 15:39:21 by areheman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putendl_fd(char *s, int fd)
{
	size_t	i;
	char	nl;

	if (!s)
		return ;
	i = 0;
	nl = '\n';
	while (s[i])
	{
		write(fd, s + i, 1);
		i++;
		if (i == ft_strlen(s))
			write(fd, &nl, 1);
	}
}
