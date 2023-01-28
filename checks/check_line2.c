/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_line2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: areheman <areheman@student.42mulhouse.fr>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/20 12:46:10 by areheman          #+#    #+#             */
/*   Updated: 2022/10/07 12:35:31 by areheman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

static int	handle_single(char *str, int i)
{
	if ((str[i] == '>' && (str[i + 1] == '<' || str[i + 1] == '|'))
		|| (str[i] == '<' && (str[i + 1] == '>' || str[i + 1] == '|'))
		|| (str[i] == '|' && (str[i + 1] == '<' || str[i + 1] == '|'))
		|| (str[i] == '|' && str [i + 1] == '>'))
	{
		ft_putstr_fd("Error: Invalid syntax.\n", 2);
		return (1);
	}
	return (0);
}

static int	handle_double(char *str, int i)
{
	if (((str[i] == '>' && str[i + 1] == '>' && (str[i + 2] == '|'
					|| str[i + 2] == '<' || str[i + 2] == '>')))
		|| (str[i] == '<' && str[i + 1] == '<'
			&& (str[i + 2] == '|' || str[i + 2] == '<'
				|| str[i + 2] == '>')))
	{
		ft_putstr_fd("Error: Invalid syntax.\n", 2);
		return (1);
	}
	return (0);
}

int	pc_redirs(char *str)
{
	int	i;
	int	j;

	i = 0;
	j = ft_strlen(str);
	while (i < j)
	{
		if (str[i] == '\'' || str[i] == '\"')
			i = pass_quotes(str, i);
		else
		{
			if (i + 1 < j)
			{
				if (handle_single(str, i))
					return (1);
			}
			if (i + 2 < j)
			{
				if (handle_double(str, i))
					return (1);
			}
			i++;
		}
	}
	return (0);
}
