/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_delete_here.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aroulin <aroulin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/12 17:36:48 by aroulin           #+#    #+#             */
/*   Updated: 2017/10/29 16:10:41 by jle-quel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/sh.h"

/*
*************** PUBLIC *********************************************************
*/

int				key_delete_here(t_read **read_std, unsigned long buff)
{
	t_cmd		*kill;

	(void)buff;
	if ((*read_std)->cmd->next)
	{
		kill = (*read_std)->cmd;
		(*read_std)->cmd = (*read_std)->cmd->next;
		if ((*read_std)->cmd->prev->prev)
			(*read_std)->cmd->prev->prev->next = (*read_std)->cmd;
		(*read_std)->cmd->prev = (*read_std)->cmd->prev->prev;
		free(kill);
		(*read_std)->print = 2;
	}
	return (1);
}
