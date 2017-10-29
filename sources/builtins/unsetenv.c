/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   unsetenv.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jle-quel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/12 12:46:14 by jle-quel          #+#    #+#             */
/*   Updated: 2017/10/28 22:10:29 by jle-quel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/sh.h"

/*
*************** PRIVATE ********************************************************
*/

static void		error(void)
{
	ft_putstr_fd("Unsetenv: ", 2);
	ft_putendl_fd("Too few arguments", 2);
}

static void		remove_variable(int place, char ***env)
{
	int		index;
	int		i;
	char	**new;

	index = 0;
	i = 0;
	new = (char**)ft_memalloc(sizeof(char*) * ft_arraylen((const char**)*env));
	while ((*env)[index])
	{
		if (index != place)
			new[i++] = ft_strdup((*env)[index]);
		index++;
	}
	ft_arraydel(env);
	*env = new;
}

/*
*************** PUBLIC *********************************************************
*/

void			unseteenv(char **command, char ***env, unsigned char *ret)
{
	size_t		index;
	int			place;

	index = 1;
	if (command[index])
	{
		while (command[index])
		{
			place = get_env_index(command[index], *env);
			place != -1 ? remove_variable(place, env) : 0;
			index++;
		}
	}
	else
		error();
	*ret = 0;
}
