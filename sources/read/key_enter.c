/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_enter.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aroulin <aroulin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/12 17:41:21 by aroulin           #+#    #+#             */
/*   Updated: 2017/10/29 16:28:55 by jle-quel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/sh.h"

/*
*************** PUBLIC *********************************************************
*/

int				key_enter_(t_read **read_std, unsigned long buff)
{
	(void)buff;
	(*read_std)->cmd = last_cmd((*read_std)->cmd);
	(*read_std)->print = 2;
	print_struct(*read_std);
	insert_one_line();
	if (!(check_cmd(read_std)))
		return ((*read_std)->finish = 1);
	else
	{
		(*read_std)->cur.line = 1;
		key_print_fct((*read_std)->cmd, 10);
		(*read_std)->history = 0;
		(*read_std)->print = 2;
	}
	return (0);
}
