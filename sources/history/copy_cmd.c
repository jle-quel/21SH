/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   copy_cmd.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aroulin <aroulin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/27 18:04:14 by aroulin           #+#    #+#             */
/*   Updated: 2017/10/30 09:45:51 by jle-quel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/sh.h"

/*
*************** PUBLIC *********************************************************
*/

void			copy_cmd(t_read **read_std, t_cmd *cpy)
{
	(*read_std)->cmd = NULL;
	(*read_std)->cmd = create_element('\0');
	cpy = first_cmd(cpy, 1);
	while (cpy->c)
	{
		key_print_fct((*read_std)->cmd, cpy->c);
		cpy = cpy->next;
	}
}
