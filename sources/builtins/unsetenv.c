/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   unsetenv.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jle-quel <jle-quel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/06 19:03:59 by jle-quel          #+#    #+#             */
/*   Updated: 2017/11/06 19:04:46 by jle-quel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sh.h"

/*
*************** PRIVATE ********************************************************
*/

static void		err(void)
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

void			ft_unsetenv(char **command, char ***env, uint8_t *ret)
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
		err();
	*ret = 0;
}
