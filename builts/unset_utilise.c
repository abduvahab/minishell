/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   unset_utilise.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: areheman <areheman@student.42mulhouse.fr>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/25 18:30:46 by areheman          #+#    #+#             */
/*   Updated: 2022/10/11 16:49:45 by areheman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

void	ft_delete_str(char ***bs, char *s)
{
	char	**tem;
	char	**tem2;
	int		i;
	int		j;

	i = 0;
	while ((*bs)[i])
		i++;
	tem = malloc(sizeof(char *) * (i));
	if (!tem)
		return ;
	tem2 = (*bs);
	j = 0;
	i = 0;
	while (tem2[i])
	{
		if (!ft_strcmp(tem2[i], s))
			i++;
		if (tem2[i])
			tem[j++] = ft_strdup(tem2[i++]);
	}
	tem[j] = NULL;
	ft_frees(*bs);
	*bs = tem;
}

int	is_unset_export(char *s)
{
	extern t_minish	g_minish;
	char			**tem;
	int				i;

	tem = g_minish.expo;
	if (!tem)
		return (0);
	i = 0;
	while (tem[i])
	{
		if (!ft_strcmp(tem[i], s))
			return (1);
		i++;
	}
	return (0);
}

int	is_unset_env(char *s)
{
	extern t_minish	g_minish;
	char			**vars;
	int				i;

	i = 0;
	vars = all_env_var();
	while (vars[i])
	{
		if (!ft_strcmp(vars[i], s))
		{
			ft_frees(vars);
			return (1);
		}
		i++;
	}
	ft_frees(vars);
	return (0);
}
