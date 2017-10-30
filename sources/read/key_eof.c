/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_eof.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aroulin <aroulin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/12 17:38:25 by aroulin           #+#    #+#             */
/*   Updated: 2017/10/30 10:01:07 by jle-quel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/sh.h"

/*
*************** PUBLIC *********************************************************
*/

char			*save_home(char *str)
{
	static char	*home;

	if (str && !home)
		home = ft_strdup(str);
	return (home);
}

int				key_eof(t_read **read_std, unsigned long buff)
{
	if (!(*read_std)->cmd->c && !(*read_std)->cmd->prev)
	{
		b_write_history_in_file();
		ft_canonique();
		exit(EXIT_SUCCESS);
	}
	else if ((*read_std)->cmd->c)
	{
		key_delete_here(read_std, buff);
		(*read_std)->print = 2;
	}
	return (1);
}
