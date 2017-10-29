/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   memdel_read.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aroulin <aroulin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/20 10:52:17 by aroulin           #+#    #+#             */
/*   Updated: 2017/10/23 10:22:18 by jle-quel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/sh.h"

/*
*************** PUBLIC *********************************************************
*/

int				memdel_cmd(t_cmd **cmd)
{
	t_cmd *tmp;

	if (*cmd)
	{
		while ((*cmd) && (*cmd)->prev)
			(*cmd) = (*cmd)->prev;
		while ((*cmd))
		{
			tmp = (*cmd);
			(*cmd) = (*cmd)->next;
			free(tmp);
		}
	}
	(*cmd) = NULL;
	return (1);
}

int				memdel_read(t_read **read_std)
{
	memdel_cmd(&((*read_std)->cmd));
	ft_memdel((void **)read_std);
	return (1);
}
