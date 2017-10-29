/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jle-quel <jle-quel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/12 11:52:42 by jle-quel          #+#    #+#             */
/*   Updated: 2017/10/29 14:00:55 by jle-quel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/sh.h"

/*
*************** PRIVATE ********************************************************
*/

static void		error(char *str, char *err)
{
	ft_putstr_fd("Exit: ", 2);
	ft_putstr_fd(str, 2);
	ft_putendl_fd(err, 2);
}

static bool		chk(char *str)
{
	size_t		index;

	index = 0;
	while (str[index])
	{
		if (ft_isdigit(str[index]) == 0)
			return (false);
		index++;
	}
	return (true);
}

/*
*************** PUBLIC *********************************************************
*/

void			exiit(char **command, char ***env, unsigned char *ret)
{
	size_t		length;

	(void)env;
	length = ft_arraylen((const char **)command) - 1;
	if (length == 1)
	{
		if (chk(command[1]) == true)
			exit((unsigned char)ft_atoi(command[1]));
		error(command[1], ": numeric argument required");
	}
	else if (length > 1)
		error(command[length], ": too many arguments");
	else
		exit(*ret);
}
