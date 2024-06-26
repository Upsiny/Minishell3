/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_for_exec.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hguillau <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/24 10:21:13 by hguillau          #+#    #+#             */
/*   Updated: 2024/05/08 11:16:11 by hguillau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

char	*recup_pathexec(t_data *data)
{
	int	i;

	i = 0;
	if (!data->cp_env || !data->cp_env[i])
		return (NULL);
	while (data->cp_env[i])
	{
		if (ft_strncmp(data->cp_env[i], "PATH=", 5) == 0)
			return (ft_strdup3(data->cp_env[i] + 5));
		i++;
	}
	return (NULL);
}

char	**init_cmd(char **cmd)
{
	char	**pathcmd;
	char	*tmp;

	pathcmd = ft_tabcpy(cmd);
	tmp = ft_strjoin("/", pathcmd[0]);
	free(pathcmd[0]);
	pathcmd[0] = ft_strdup(tmp);
	free(tmp);
	return (pathcmd);
}

char	**recup_path(t_data *data)
{
	char	*b_path;
	char	**all_path;

	b_path = recup_pathexec(data);
	all_path = NULL;
	if (b_path)
	{
		all_path = ft_split(b_path, ':');
		free(b_path);
	}
	return (all_path);
}

void	ft_set_path_and_execve(t_data *data, char **cmd)
{
	char	**all_path;
	char	**pathcmd;

	all_path = recup_path(data);
	pathcmd = init_cmd(cmd);
	if (all_path == NULL || cmd[0][0] == '/')
	{
		data->ret_err = 127;
		ft_print_error_msg3("minishell: ", data->s_lex->content,
			": No such file or directory\n");
		free_tab(pathcmd);
		free_tab(all_path); //used to remove leak n $ = NULL
		return ;
	}
	ft_execution(data, all_path, pathcmd, cmd);
}
