/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_end_pipe.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: areheman <areheman@student.42mulhouse.fr>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/17 14:21:05 by areheman          #+#    #+#             */
/*   Updated: 2022/10/11 09:44:46 by areheman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

char	*get_new_line(void)
{
	extern t_minish	g_minish;
	char			*line;

	ft_signal();
	g_minish.sig = 1;
	while (1)
	{
		line = readline("pipe>");
		if (!line)
			break ;
		if (!g_minish.line && line[0] == '\0')
			break ;
		if (line[0] != '\0')
			break ;
	}
	if (!g_minish.line && !line)
		return (0);
	return (line);
}

char	*get_after_pipe(char *line)
{
	extern t_minish	g_minish;
	char			*n_line;
	char			*tem;

	tem = get_new_line();
	if (!tem)
		return (line);
	if (!tem[0])
		return (NULL);
	if (!g_minish.line)
		return (tem);
	n_line = ft_strjoin(line, tem);
	if (!tem)
		free(tem);
	return (n_line);
}

int	is_end_pipe(char *line)
{
	int		len;
	char	*n_line;
	int		i;

	n_line = ft_strrchr(line, '|');
	if (n_line)
	{
		len = ft_strlen(line);
		i = 1;
		while (*(n_line + i) == ' ')
			i++;
		if (line[len] == *(n_line + i))
			return (1);
	}
	return (0);
}
