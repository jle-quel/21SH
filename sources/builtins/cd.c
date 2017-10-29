/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cd.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jle-quel <jle-quel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/12 09:49:18 by jle-quel          #+#    #+#             */
/*   Updated: 2017/10/29 13:59:49 by jle-quel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/sh.h"

/*
*********************** PRIVATE ************************************************
*/

static unsigned char	error(char *str, char *err)
{
	ft_putstr_fd("cd: ", 2);
	if (str)
	{
		ft_putstr_fd(err, 2);
		ft_putendl_fd(str, 2);
	}
	else
		ft_putendl_fd(err, 2);
	return (-1);
}

static void				modify_variable(char ***env, char *str,
						char **pwd, unsigned char *ret)
{
	char				**temp;

	temp = (char **)ft_memalloc(sizeof(char *) * 4);
	temp[0] = ft_strdup("setenv");
	temp[1] = ft_strdup(str);
	temp[2] = ft_strdup(*pwd);
	temp[3] = NULL;
	seteenv(temp, env, ret);
	ft_arraydel(&temp);
	ft_memdel((void **)pwd);
}

static unsigned char	change_direction(char *argv, char **env)
{
	char				err;
	char				*direction;

	if (!argv || !ft_strcmp(argv, "--"))
	{
		direction = ft_getenv(env, "HOME");
		return (direction ? chdir(direction) : error(NULL, " HOME not set"));
	}
	if (!ft_strcmp(argv, "-"))
	{
		direction = ft_getenv(env, "OLDPWD");
		return (direction ? chdir(direction) : error(NULL, "OLDPWD not set"));
	}
	else
	{
		if (access(argv, F_OK) == -1)
			err = error(argv, "no such file or directory: ");
		else
		{
			err = chdir(argv);
			err == -1 ? error(argv, "permission denied: ") : 0;
		}
	}
	return (err);
}

/*
*********************** PUBLIC *************************************************
*/

void					cd(char **command, char ***env, unsigned char *ret)
{
	char				err;
	char				*oldpwd;
	char				*pwd;

	oldpwd = getcwd(NULL, 4096);
	err = change_direction(command[1], *env);
	if (!err)
	{
		pwd = getcwd(NULL, 4096);
		modify_variable(env, "OLDPWD", &oldpwd, ret);
		modify_variable(env, "PWD", &pwd, ret);
	}
	ft_memdel((void **)&oldpwd);
	*ret = err;
}
