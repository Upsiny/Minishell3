/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   unset.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hguillau <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/24 10:25:20 by hguillau          #+#    #+#             */
/*   Updated: 2024/04/24 10:25:22 by hguillau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

int	check_var(char *str)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	if (str[0] >= '0' && str[0] <= '9')
		return (2);
	while (str[i])
	{
		if (str[i] == '=')
			j++;
		i++;
	}
	if (j != 0)
		return (1);
	return (0);
}

char	**unset_var(char **tab_cmd, char *str)
{
	int		i;
	int		j;
	char	**cpy;

	i = 0;
	j = 0;
	cpy = malloc(sizeof(char *) * (ft_tab_len(tab_cmd) + 1));
	while (tab_cmd[i] != NULL && tab_cmd)
	{
		if (ft_strncmp(tab_cmd[i], str, ft_strlen(str)) == 0)
		{
			while (tab_cmd[i + 1])
				cpy[j++] = ft_strdup3(tab_cmd[++i]);
		}
		else
			cpy[j++] = ft_strdup3(tab_cmd[i]);
		i++;
	}
	cpy[j] = NULL;
	free_tab(tab_cmd);
	tab_cmd = ft_cpytab(cpy);
	free_tab(cpy);
	return (tab_cmd);
}

void	unset_builtin(t_data *data, char **cmd)
{
	int	i;

	i = 1;
	while (cmd[i])
	{
		if (check_var(cmd[i]) == 0)
		{
			data->cp_env = unset_var(data->cp_env, cmd[i]);
			data->ret_err = 0;
		}
		else
		{
			ft_print_error_msg3("minishell: unset: `",
				cmd[1], "': not a valid identifier\n");
			data->ret_err = 1;
		}
		i++;
	}
	free_tab(data->cp_exp);
	data->cp_exp = order_exp(data->cp_env);
	data->ret_err = 0;
}
