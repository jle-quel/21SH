/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   variable.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jle-quel <jle-quel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/04 15:23:14 by jle-quel          #+#    #+#             */
/*   Updated: 2017/11/06 22:21:32 by jle-quel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sh.h"

/*
*************** TOOLS **********************************************************
*/

char			*get_variable(char *str)
{
	size_t		index;
	char		*new;

	new = NULL;
	if (str)
	{
		index = 0;
		while (str[index])
		{
			if (str[index] == '\"' || str[index] == ' ' || str[index] == '/')
				break ;
			index++;
		}
		new = index ? ft_strsub(str, 1, index - 1) : NULL;
	}
	return (new);
}

/*
*************** PRIVATE ********************************************************
*/

bool			expansion(char **str, char *rest, char **env)
{
	char		*temp;
	char		*variable;
	char		*new;

	temp = get_variable(rest);
	variable = ft_getenv(env, temp);
	if (variable && ft_strlen(variable))
	{
		new = (char *)ft_memalloc(sizeof(char) *
		(ft_strlen(*str) + ft_strlen(variable) + 1));
		ft_strncpy(new, *str, ft_strrlen(*str, '$', 0));
		ft_strcat(new, variable);
		ft_strcat(new, rest ? rest + (ft_strlen(temp) + 1) : NULL);
		ft_memdel((void **)str);
		*str = new;
		ft_memdel((void **)&temp);
		return (true);
	}
	ft_memdel((void **)&temp);
	return (false);
}

/*
*************** PUBLIC *****************************************************
*/

void			variable(t_parsing *node, char **env)
{
	size_t		index;
	uint8_t		status;
	t_parsing	*temp;

	status = DEFAULT;
	temp = node;
	while (node)
	{
		if (node->input)
		{
			index = 0;
			while (node->input[index])
			{
				chk_quote(node->input[index], &status);
				if (status & (DEFAULT | DQUOTE) && node->input[index] == '$')
					if (expansion(&node->input, node->input + index, env))
						variable(temp, env);
				index++;
			}
		}
		node = node->next;
	}
}
