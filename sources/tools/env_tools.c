/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env_tools.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jle-quel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/24 21:52:27 by jle-quel          #+#    #+#             */
/*   Updated: 2017/10/28 23:53:56 by jle-quel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/sh.h"

/*
*************** PUBLIC *********************************************************
*/

int				get_env_index(char *str, char **env)
{
	int			index;

	index = 0;
	if (env)
	{
		while (env[index])
		{
			if (ft_strncmp(env[index], str, ft_strlen(str)) == 0)
				return (index);
			index++;
		}
	}
	return (-1);
}

char			**get_path(char **env)
{
	int			index;
	char		**ret;

	index = get_env_index("PATH", env);
	ret = index != -1 ? ft_strsplit(env[index] + 5, ':') : NULL;
	return (ret);
}
