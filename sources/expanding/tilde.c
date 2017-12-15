/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tilde.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jle-quel <jle-quel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/04 13:55:29 by jle-quel          #+#    #+#             */
/*   Updated: 2017/11/06 22:20:26 by jle-quel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sh.h"

/*
*************** PRIVATE ****************************************************
*/

static bool		chk(const char *str, size_t index)
{
	if (index == 0 || !str[index - 1] || str[index - 1] == ' ')
	{
		if (!str[index + 1] || str[index + 1] == ' ' || str[index + 1] == '/')
		{
			if (str[index] == '~')
				return (true);
		}
	}
	return (false);
}

static bool		expansion(char **str, char *rest, char **env)
{
	char		*home;
	char		*new;

	home = ft_getenv(env, "HOME");
	if (home && ft_strlen(home))
	{
		new = (char *)ft_memalloc(sizeof(char) *
		(ft_strlen(*str) + ft_strlen(home) + 1));
		ft_strncpy(new, *str, ft_strrlen(*str, '~', 0));
		ft_strcat(new, home);
		ft_strcat(new, rest ? rest + 1 : NULL);
		ft_memdel((void **)str);
		*str = new;
		return (true);
	}
	return (false);
}

/*
*************** PUBLIC *****************************************************
*/

void			tilde(t_parsing *node, char **env)
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
				if (status & DEFAULT && chk(node->input, index))
					if (expansion(&node->input, node->input + index, env))
						tilde(temp, env);
				index++;
			}
		}
		node = node->next;
	}
}
