/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jle-quel <jle-quel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/01 22:16:00 by jle-quel          #+#    #+#             */
/*   Updated: 2017/11/06 20:09:29 by jle-quel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sh.h"

static const t_error	g_err[] =
{
	(t_error){SYNTAX_ERR, "syntax error near unexpected token `", -1},
	(t_error){COMMAND_404, "commmand not found: `", 127},
	(t_error){NOT_SUPPORTED, "operater not supported: `", -1},
	(t_error){DENIED, "permission denied: `", -1},
	(t_error){DIRECTORY, "is a directory: `", -1},
	(t_error){FILE_404, "no such file or directory: `", -1},
	(t_error){EXIT_ARG, "numeric argument required: `", -1},
	(t_error){EXIT_DIGIT, "too many arguments: `", -1}
};

/*
*************** PUBLIC *********************************************************
*/

void			print_error(char *str, char *err)
{
	ft_putstr("21sh: ");
	ft_putstr(err);
	ft_putstr(str);
	ft_putendl("\'");
}

void			error(char *str, uint8_t *ret, int err)
{
	short		index;

	index = 0;
	while (index < 8)
	{
		if (err == g_err[index].err_type)
		{
			print_error(str, g_err[index].str);
			*ret = g_err[index].err_ret;
		}
		index++;
	}
}
