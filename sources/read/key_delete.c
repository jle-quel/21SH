/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_delete.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aroulin <aroulin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/11 06:33:09 by aroulin           #+#    #+#             */
/*   Updated: 2017/10/29 17:02:57 by jle-quel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/sh.h"

/*
*************** PUBLIC *********************************************************
*/

int				key_del(t_read **read_std, unsigned long buff)
{
	t_cmd		*kill;

	(void)buff;
	if ((*read_std)->cmd->prev && ((*read_std)->history ||
	(!(*read_std)->history && (*read_std)->cmd->prev->c != 10)))
	{
		kill = (*read_std)->cmd->prev;
		if ((*read_std)->cmd->prev->prev)
		{
			(*read_std)->cmd->prev->prev->next = (*read_std)->cmd;
			(*read_std)->cmd->prev = (*read_std)->cmd->prev->prev;
		}
		else
			(*read_std)->cmd->prev = NULL;
		free(kill);
		(*read_std)->print = 2;
	}
	return (1);
}
