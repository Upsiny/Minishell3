/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dollar.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hguillau <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/24 10:30:18 by hguillau          #+#    #+#             */
/*   Updated: 2024/05/24 15:57:41 by hguillau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

/*void	replace_prompt(t_data *data, char *value, int start, int end)
{
	char	*first_part;
	char	*last_part;
	char	*new_prompt;
	int		i;
	int		j;

	i = 0;
	j = end;
	first_part = malloc((start + 1) * sizeof(char));
	if (!first_part)
	{
		free(first_part);
		return ;
	}
	last_part = malloc((ft_strlen(data->prompt) - end + 1) * sizeof(char));
	if (!last_part)
	{
		free(last_part);
		return ;
	}
	if (!value)
		value = "";
	while (i < start)
	{
		first_part[i] = data->prompt[i];
		i++;
	}
	first_part[i] = '\0';
	i = 0;
	while (data->prompt[j])
	{
		last_part[i] = data->prompt[j];
		i++;
		j++;
	}
	last_part[i] = '\0';
	new_prompt = ft_strjoin(first_part, value);
	free(first_part);
	data->tmp_dollar = ft_strdup3(new_prompt);
	free(new_prompt);
	new_prompt = ft_strjoin(data->tmp_dollar, last_part);
	free(last_part);
	free(data->tmp_dollar);
	free(data->prompt);
	data->prompt = ft_strdup3(new_prompt);
	free(new_prompt);
//	free(value);
}


void	get_dollar(t_data *data) // a refaire
{
	int		i;
	int		j;
	int		k;
	char	*dol_value;
	char	*split;

	i = data->lexer_check;
	j = 0;
	k = 0;
    while (data->prompt[i + j])
	{
		j++; //refaire les conditions ci-dessous
		if (!ft_isspace(data->prompt[i + j]))
			break ;
		if ((!ft_isinside(data->prompt[i + j]) && data->bdq == 1)))
			break ;
		if	(!ft_isinside(data->prompt[i + j] && data->prompt[i + j - 1] != '$'))
			return (lexer_advance(data)) ;
	}
	dol_value = malloc(sizeof(char) * (j + 1));
//	printf("dol_value = %s\n", dol_value);
	if (!dol_value)
	{
	//	free(dol_value);
		return ;
	}
	while (k < (j-1))
	{
		dol_value[k] = data->prompt[i + 1];
		k++;
		i++;
	}
	dol_value[k] = '\0';
    split = search_in_env(data, dol_value);
//	if (!split)
  //  {
   //     free(split);
  //      return;
 //   }
	replace_prompt(data, split, data->lexer_check,
		data->lexer_check + j);
	
//	printf("split = %s\n", split);
	if (split)
	{
//		if (!ft_strcmp(split, ""))
//
	//	else
			free(split);
	}
	free(dol_value);
}*/


// recupere la value du dollar d'en l'env et envoie cette meme value pour remplacer le prompt
void	dev_dollar(t_data *data, char *value, int pinit, int size)
{
	char	*val_env;

	val_env = search_in_env(data, value);
	if (!val_env)
	{
		free(val_env);
		return ;
	}
	replace_prompt(val_env);
	free(val_env);
}


void	check_dollar(t_data *data, int pinit, int size) //pinit est la pos du dollar, size est la pose de la taille de la str derriere (dollar compris)
{
	char	*value;
	int		i;

	i = 1;
	value = malloc(sizeof(char) * size);
	if (!value)
	{
		free(value);
		return ;
	}
	while (i <= size)
	{
		value[i - 1] = data->prompt[pinit + i];
		i++;
	}
	value[i] = '\0';
	dev_dollar(data, value, pinit, size);
	free(value);
}

// fonction qui verifie si le caractere checker fait partie des caractere qui stop l'expend
int	ft_isinside(char c)
{
	int	i;

	i = 0;
	while (DOLLAR_STOP[i])
	{
		if (DOLLAR_STOP[i] == c)
			return (0);
		i++;
	}
	return (1);
}

// fonction qui a pour but de preparer l'expend du $ si expend il y a
void	get_dollar(t_data *data, int pos)
{
	int	i;

	i = 0;
	while (data->prompt[pos + i])
	{
		i++;
		if (!ft_isinside(data->prompt[pos + i]
			&& data->prompt[pos + i - 1] != '$'))
		{
			replace_prompt(data,"", i, i); // donner ce qu'il faut pour chaine vide
			return ;
		}
		if (!ft_isspace(data->prompt[pos + i])
			&& !ft_isinside(data->prompt[pos + i]))
			break ;
	}
	check_dollar(data, pos, i);
}
