/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jle-quel <jle-quel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/06 18:54:23 by jle-quel          #+#    #+#             */
/*   Updated: 2017/11/06 19:07:35 by jle-quel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sh.h"

/*
*************** PRIVATE ********************************************************
*/

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

void			ft_exit(char **command, char ***env __attribute__((unused)),
				uint8_t *ret)
{
	size_t		length;

	length = ft_arraylen((const char **)command) - 1;
	if (length == 1)
	{
		if (chk(command[1]) == true)
			exit((unsigned char)ft_atoi(command[1]));
		error(command[1], ret, EXIT_DIGIT);
	}
	else if (length > 1)
	{
		error(command[1], ret, EXIT_ARG);
		return ;
	}
	exit(*ret);
}
