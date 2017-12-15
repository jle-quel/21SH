/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   setenv.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jle-quel <jle-quel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/06 19:02:04 by jle-quel          #+#    #+#             */
/*   Updated: 2017/11/06 19:09:10 by jle-quel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sh.h"

/*
*************** PRIVATE ********************************************************
*/

static void		err(void)
{
	ft_putstr_fd("setenv: ", 2);
	ft_putendl_fd("Too many arguments", 2);
}

static void		modify_variable(char **command, int place, char ***env)
{
	char		*new;

	new = ft_threejoin(command[1], "=", command[2]);
	ft_memdel((void **)&(*env)[place]);
	(*env)[place] = new;
}

static void		add_variable(char **command, char ***env)
{
	size_t		index;
	char		**new;

	index = 0;
	new = (char **)ft_memalloc(sizeof(char *) *
										(ft_arraylen((const char **)*env) + 2));
	while ((*env)[index])
	{
		new[index] = ft_strdup((*env)[index]);
		index++;
	}
	new[index] = ft_threejoin(command[1], "=", command[2]);
	new[index + 1] = NULL;
	ft_arraydel(env);
	*env = new;
}

/*
*************** PUBLIC *********************************************************
*/

void			ft_setenv(char **command, char ***env, unsigned char *ret)
{
	size_t		length;
	int			place;

	length = ft_arraylen((const char **)command);
	if (length == 1)
		ft_putarray((const char **)*env);
	else if (length >= 4)
		err();
	else
	{
		place = get_env_index(command[1], *env);
		if (place >= 0)
			modify_variable(command, place, env);
		else
			add_variable(command, env);
	}
	*ret = 0;
}
