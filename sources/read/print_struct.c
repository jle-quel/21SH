/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_struct.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aroulin <aroulin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/13 05:32:01 by aroulin           #+#    #+#             */
/*   Updated: 2017/10/29 16:08:51 by jle-quel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/sh.h"

/*
*************** PRIVATE ********************************************************
*/

static int		print_list(int to_select, t_cmd *cmd, t_cmd *stop,
				t_cursor *cur)
{
	int			co;

	co = tgetnum("co");
	while ((!to_select && cmd->c) || (to_select && cmd != stop))
	{
		(cmd->c != 10) ? ft_putchar_fd(cmd->c, init_fd()) : 0;
		if (cmd->c == 10 || cur->co >= co - 1)
		{
			(to_select) ? MV_BOT : insert_one_line();
			cur->line += 1;
			cur->co = 0;
		}
		cur->co += 1;
		cmd = cmd->next;
	}
	return (1);
}

static void		print_to_end(t_read *read_std, t_cmd *cmd, int end)
{
	restore_cursor_(read_std->cur);
	if (!end)
		CLEAR_FROM_CUR;
	read_std->cur = prompt(PRINT, NULL, NULL);
	print_list(end, cmd, read_std->cmd, &(read_std->cur));
}

/*
*************** PUBLIC *********************************************************
*/

int				print_struct(t_read *read_std)
{
	t_cmd		*cmd;

	if ((read_std)->print)
	{
		CURSOR_INVIS;
		cmd = first_cmd(read_std->cmd, read_std->history);
		if ((read_std)->print == 2)
			print_to_end(read_std, cmd, 0);
		print_to_end(read_std, cmd, 1);
		CURSOR_BACK;
		(read_std)->print = 0;
	}
	return (1);
}
