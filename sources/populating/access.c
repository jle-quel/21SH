/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   access.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jle-quel <jle-quel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/06 13:05:03 by jle-quel          #+#    #+#             */
/*   Updated: 2017/11/06 19:28:22 by jle-quel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sh.h"

/*
*************** PRIVATE ********************************************************
*/

static bool		chk_node(t_parsing *node)
{
	if (ft_strchr(node->command[0], '/'))
		return (false);
	if (ft_stronly(node->command[0], '.'))
		return (false);
	if (ft_stronly(node->command[0], ' '))
		return (false);
	if (!node->prev)
		return (true);
	if (node->prev->command[0] && node->prev->command[0][0])
	{
		if (node->prev->command[0][0] == ';')
			return (true);
		if (node->prev->command[0][0] == '|')
			return (true);
		if (node->prev->command[0][0] == '&')
			return (true);
	}
	return (false);
}

static bool		chk_builtins(char *str)
{
	size_t				index;
	static const char	*command[] = {"echo", "env", "cd", NULL};

	index = 0;
	while (command[index])
	{
		if (ft_strcmp(str, command[index]) == 0)
			return (false);
		index++;
	}
	return (true);
}

static void		get_access(char **str, char **env)
{
	size_t		index;
	char		**paths;
	char		*ret;

	index = 0;
	if ((paths = get_path(env)))
	{
		while (paths[index])
		{
			ret = ft_threejoin(paths[index], "/", *str);
			if (access(ret, F_OK) == 0)
			{
				ft_memdel((void**)str);
				*str = ret;
				break ;
			}
			ft_memdel((void**)&ret);
			index++;
		}
		ft_arraydel(&paths);
	}
}

/*
*************** PUBLIC *********************************************************
*/

void			create_access(t_parsing *node, char **env)
{
	if (node && node->command && node->command[0])
	{
		if (chk_node(node) && chk_builtins(node->command[0]))
			get_access(&(node->command[0]), env);
	}
}
