/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: areheman <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/02 14:45:00 by areheman          #+#    #+#             */
/*   Updated: 2022/03/02 17:07:25 by areheman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <stdlib.h>
#include "libft.h"

void	*ft_calloc(size_t n, size_t size)
{
	void	*p;

	p = (void *)malloc(size * n);
	if (!p)
		return (NULL);
	ft_bzero(p, n * size);
	return (p);
}
