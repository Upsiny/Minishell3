/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   replace_prompt.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hguillau <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/20 17:50:39 by hguillau          #+#    #+#             */
/*   Updated: 2024/05/20 18:25:04 by hguillau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

char	*get_final_part(t_data *data, char *first_part, int pos)
{
}

char	*get_first_part(t_data *data, char *value, int stop)
{
	int		i;
	int		j;
	char	*first_part;

	i = 0;
	j = 0;
	first_part = malloc(sizeof(char) * (stop + ft_strlen(value)));
	while (i <= stop && data->prompt[i])
	{ // rempli first part par le prompt jusqu'au stop
	}
	stop += ft_strlen(value);
	while (i + j <= stop)
	{ // remplis la suite de la first part avec la value
	}
	return (first_part);
}

void	replace_prompt(t_data *data, char *value, int start, int end) //end etant la size
{
	char	*first_part;
	char	*new_prompt;

	if (!value)
		value = "";
	first_part = get_first_part(data, value, start);
	new_prompt = get_final_part(data, first_part, start + end);
	free(first_part);
	free(data->prompt);
	data->prompt = ft_strdup3(new_prompt);
	free(new_prompt);
}
