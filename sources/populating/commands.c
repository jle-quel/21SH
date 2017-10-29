/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   commands.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jle-quel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/16 14:51:43 by jle-quel          #+#    #+#             */
/*   Updated: 2017/10/29 11:55:28 by jle-quel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/sh.h"

/*
*************** PRIVATE ********************************************************
*/

static bool		chk(t_list *node)
{
	if (node->str && node->str[0])
	{
		if (!node->prev)
			return (true);
		if (node->prev->str[0] == ';')
			return (true);
		if (node->prev->str[0] == '|')
			return (true);
		if (node->prev->str[0] == '&')
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

static void		create_access(char **str, char **paths)
{
	size_t		index;
	char		*ret;

	index = 0;
	while (paths[index])
	{
		ret = ft_threejoin(paths[index], "/", *str);
		if (access(ret, F_OK) == 0)
		{
			ft_memdel((void**)str);
			*str = ret;
			return ;
		}
		ft_memdel((void**)&ret);
		index++;
	}
}

static char		**do_expansion(t_list *node, char **env)
{
	char	**ret;
	char	**paths;

	ret = split(node->str);
	if (ret && ret[0] && ret[0][0] && ft_stronly(ret[0], '.') == false)
	{
		if (chk(node) == true && chk_builtins(ret[0]) == true)
		{
			paths = get_path(env);
			if (paths && !ft_strchr(ret[0], '/'))
			{
				create_access(&(ret[0]), paths);
				ft_arraydel(&paths);
			}
			ft_arraydel(&paths);
		}
	}
	return (ret);
}

/*
*************** PUBLIC *********************************************************
*/

void			commands(t_ast **root, t_list *node, char **env)
{
	size_t		index;
	int			place;

	index = 0;
	place = 0;
	while (node)
	{
		if (index % 2 == 0)
		{
			add_to_tree(root, place, NULL, do_expansion(node, env));
			place++;
		}
		index++;
		node = node->prev;
	}
}
