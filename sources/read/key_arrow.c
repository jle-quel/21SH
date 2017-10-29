/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_arrow.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aroulin <aroulin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/11 03:27:42 by aroulin           #+#    #+#             */
/*   Updated: 2017/10/29 00:04:04 by jle-quel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/sh.h"

/*
*************** PUBLIC *********************************************************
*/

int				key_arrow_left(t_read **read_std, unsigned long buff)
{
	(void)buff;
	if ((*read_std)->cmd->prev && ((*read_std)->history ||
		(!(*read_std)->history && (*read_std)->cmd->prev->c != 10)))
	{
		(*read_std)->cmd = (*read_std)->cmd->prev;
		(*read_std)->print = 1;
	}
	return (1);
}

int				key_arrow_right(t_read **read_std, unsigned long buff)
{
	(void)buff;
	if ((*read_std)->cmd->next)
	{
		(*read_std)->cmd = (*read_std)->cmd->next;
		(*read_std)->print = 1;
	}
	return (1);
}

int				key_arrow_up(t_read **read_std, unsigned long buff)
{
	(void)buff;
	if (get_len_prompt(-42) > 0)
	{
		(*read_std)->print = 2;
		previous_history(read_std);
	}
	return (1);
}

int				key_arrow_down(t_read **read_std, unsigned long buff)
{
	(void)buff;
	if (get_len_prompt(-42) > 0)
	{
		(*read_std)->print = 2;
		next_history(read_std);
	}
	return (1);
}
