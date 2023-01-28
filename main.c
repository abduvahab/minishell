/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: areheman <areheman@student.42mulhouse.fr>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/17 12:59:35 by areheman          #+#    #+#             */
/*   Updated: 2022/10/11 16:55:53 by areheman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

t_minish	g_minish;

void	ft_init_env(t_minish *minish, char **environ)
{
	minish->env = env_copy(environ);
	minish->expo = NULL;
	minish->statu = 0;
	minish->sig = 0;
}

void	free_minish(t_minish minish)
{
	int	i;

	i = 0;
	while (minish.env[i])
	{
		free(minish.env[i]);
		i++;
	}
	free(minish.env);
	if (minish.expo)
	{
		i = 0;
		while (minish.expo[i])
			free(minish.expo[i++]);
		free(minish.expo);
	}
	if (minish.line)
		free(minish.line);
}

int	main(int argc, char **argv, char **environ)
{
	(void)argc;
	(void)argv;
	ft_init_env(&g_minish, environ);
	ft_signal();
	while (isatty(0))
	{
		g_minish.sig = 0;
		g_minish.line = readline("minishell @>");
		if (!g_minish.line)
			break ;
		if (g_minish.line[0])
		{
			add_history(g_minish.line);
			if (is_end_pipe(g_minish.line))
				g_minish.line = get_after_pipe(g_minish.line);
			if (g_minish.line && check_line(g_minish.line) == 1)
				exc_cmd(g_minish.line);
		}
		if (g_minish.line)
			free(g_minish.line);
	}
	free_minish(g_minish);
	return (0);
}
