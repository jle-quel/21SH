/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_shift.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aroulin <aroulin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/11 06:34:02 by aroulin           #+#    #+#             */
/*   Updated: 2017/10/29 16:15:29 by jle-quel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/sh.h"

/*
*************** PUBLIC *********************************************************
*/

int				key_shift_up(t_read **read_std, unsigned long buff)
{
	int			co;

	(*read_std)->print = 1;
	(void)buff;
	co = tgetnum("co");
	if (co)
		while (--co && (*read_std)->cmd->prev)
		{
			if (!(*read_std)->history && (*read_std)->cmd->prev->c == 10)
				break ;
			(*read_std)->cmd = (*read_std)->cmd->prev;
		}
	return (1);
}

int				key_shift_down(t_read **read_std, unsigned long buff)
{
	int			co;

	(void)buff;
	(*read_std)->print = 1;
	co = tgetnum("co");
	if (co)
		while (--co && (*read_std)->cmd->next)
			(*read_std)->cmd = (*read_std)->cmd->next;
	return (1);
}

int				key_shift_left(t_read **read_std, unsigned long buff)
{
	(void)buff;
	(*read_std)->print = 1;
	while ((*read_std)->cmd->prev && (*read_std)->cmd->prev->c == 32)
		(*read_std)->cmd = (*read_std)->cmd->prev;
	while ((*read_std)->cmd->prev)
	{
		if ((*read_std)->cmd->prev->c == 32)
			break ;
		(*read_std)->cmd = (*read_std)->cmd->prev;
	}
	return (1);
}

int				key_shift_right(t_read **read_std, unsigned long buff)
{
	(void)buff;
	(*read_std)->print = 1;
	while ((*read_std)->cmd->c)
	{
		if ((*read_std)->cmd->c == 32)
			break ;
		(*read_std)->cmd = (*read_std)->cmd->next;
	}
	while ((*read_std)->cmd->c && (*read_std)->cmd->c == 32)
		(*read_std)->cmd = (*read_std)->cmd->next;
	return (1);
}
