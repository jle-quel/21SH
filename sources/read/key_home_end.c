/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_home_end.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aroulin <aroulin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/11 06:30:22 by aroulin           #+#    #+#             */
/*   Updated: 2017/10/29 00:03:22 by jle-quel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/sh.h"

/*
*************** PUBLIC *********************************************************
*/

int				key_home_(t_read **read_std, unsigned long buff)
{
	(void)buff;
	if ((*read_std)->cmd->prev)
	{
		while ((*read_std)->cmd->prev)
		{
			if (!(*read_std)->history && (*read_std)->cmd->prev->c == 10)
				break ;
			(*read_std)->cmd = (*read_std)->cmd->prev;
		}
		(*read_std)->print = 2;
	}
	return (1);
}

int				key_end_(t_read **read_std, unsigned long buff)
{
	(void)buff;
	if ((*read_std)->cmd->next)
	{
		while ((*read_std)->cmd->next)
			(*read_std)->cmd = (*read_std)->cmd->next;
		(*read_std)->print = 2;
	}
	return (1);
}
