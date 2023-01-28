/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expor_utilise.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: areheman <areheman@student.42mulhouse.fr>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/23 12:09:20 by areheman          #+#    #+#             */
/*   Updated: 2022/10/13 13:58:27 by areheman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

int	forbiden_str(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i] == '\\' || str[i] == ';' || str[i] == '&' \
				|| str[i] == '!' || str[i] == '`' || str[i] == '(' \
				|| str[i] == ')' || str[i] == '#' || str[i] == '*' \
				|| str[i] == '|' || str[i] == '>' || str[i] == '<' \
				|| str[0] == '=' || str[i] == '.' || str[i] == '+' \
				|| str[i] == '-' || str[i] == '}' || str[i] == '{' \
				|| str[i] == '@')
			return (1);
		i++;
	}
	return (0);
}

int	ft_is_first_number(char *s)
{
	int	i;

	i = 0;
	if (s[0] >= 48 && s[0] <= 57)
		return (1);
	return (0);
}

int	check_split_export(char *s)
{
	char	*tem;

	if (quotes_is_closed(s))
		return (1);
	tem = rm_quot_dollar(s);
	if (!tem)
		return (1);
	if (forbiden_str(tem))
	{
		free(tem);
		return (1);
	}
	if (ft_is_first_number(tem))
	{
		free(tem);
		return (1);
	}
	free(tem);
	return (0);
}

int	is_in_env(char *s)
{
	extern t_minish	g_minish;
	char			**vars;
	char			*tem;
	int				i;

	vars = all_env_var();
	i = 0;
	while (s[i] && s[i] != '=')
		i++;
	tem = ft_substr(s, 0, i);
	if (ft_add_and_delet(vars, tem, s) == 1)
		return (1);
	if (is_in_exprt(tem))
		ft_delete_str(&g_minish.expo, tem);
	free(tem);
	ft_frees(vars);
	return (0);
}

int	is_in_exprt(char *s)
{
	extern t_minish	g_minish;
	char			**tem;
	char			**vars;

	tem = g_minish.expo;
	if (!tem)
		return (0);
	vars = all_env_var();
	if (is_same_str(s, vars) == 1)
	{
		ft_frees(vars);
		return (1);
	}
	if (is_same_str(s, tem) == 1)
	{
		ft_frees(vars);
		return (1);
	}
	ft_frees(vars);
	return (0);
}
