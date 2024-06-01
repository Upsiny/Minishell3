/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   replace_prompt.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hguillau <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/20 17:50:39 by hguillau          #+#    #+#             */
/*   Updated: 2024/06/01 11:37:44 by hguillau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

// complete le nouveau prompt avec la premiere partie faite en amont
char	*get_final_part(t_data *data, char *first_part, int pos, int len_value)
{
	int		i;
	char	*new_prompt;

	i = 0;
	new_prompt = malloc(sizeof(char) * (ft_strlen(data->prompt) + len_value));
	while (first_part[i])
	{
		new_prompt[i] = first_part[i];
		i++;
	}
	while (data->prompt[pos + 1])
	{
		new_prompt[i] = data->prompt[pos + 1];
		i++;
		pos++;
	}
	new_prompt[i] = '\0';
	return (new_prompt);
}

//remplie la premiere partie du nouveau prompt
char	*get_first_part(t_data *data, char *value, int stop)
{
	int		i;
	int		j;
	char	*first_part;

	i = 0;
	j = 0;
	first_part = malloc(sizeof(char) * (stop + ft_strlen(value) + 1));
	while (i < stop && data->prompt[i])
	{ // rempli first part par le prompt jusqu'au stop
		first_part[i] = data->prompt[i];
		i++;
	}
	stop += ft_strlen(value);
	while (value[j])
	{ // remplis la suite de la first part avec la value
		first_part[i] = value[j];
		i++;
		j++;
	}
	first_part[i] = '\0';
	return (first_part);
}

// remplace le prompt avec l'expend si il a ete fait
void	replace_prompt(t_data *data, char *value, int start, int end) //end etant la size
{
	char	*first_part;
	char	*new_prompt;
	int		len_value;

	if (!value)
		value = "";
	len_value = ft_strlen(value);
	first_part = get_first_part(data, value, start);
	if (data->prompt[end + start])
		new_prompt = get_final_part(data, first_part, start + end, len_value);
	else
		new_prompt = ft_strdup(first_part);
	free(first_part);
	free(data->prompt);
	data->prompt = ft_strdup3(new_prompt);
	free(new_prompt);
}
