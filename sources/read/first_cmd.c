/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   first_cmd.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aroulin <aroulin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/13 05:46:50 by aroulin           #+#    #+#             */
/*   Updated: 2017/10/23 10:19:38 by jle-quel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/sh.h"

/*
*************** PUBLIC *********************************************************
*/

t_cmd			*first_cmd(t_cmd *cmd, int history)
{
	if (cmd)
		while (cmd->next)
			cmd = cmd->next;
	while (cmd->prev)
	{
		if (!history && cmd->prev->c == 10)
			return (cmd);
		cmd = cmd->prev;
	}
	return (cmd);
}
