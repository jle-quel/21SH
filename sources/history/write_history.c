/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   write_history.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aroulin <aroulin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/19 16:45:32 by aroulin           #+#    #+#             */
/*   Updated: 2017/10/30 09:58:28 by jle-quel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/sh.h"

/*
*************** PUBLIC *********************************************************
*/

t_hist			*set_history_to_last(void)
{
	t_hist		*hist;

	hist = gbl_save_history(NULL, REC_STRUCT);
	while (hist && hist->prev)
		hist = hist->prev;
	return (hist);
}

uint8_t			b_write_history_in_file(void)
{
	t_hist		*hist;
	int			fd;
	int			i;

	fd = open(save_home(NULL), O_WRONLY | O_CREAT | O_TRUNC, 0644);
	hist = set_history_to_last();
	i = -1;
	while (hist)
	{
		hist->hist->cmd = first_cmd(hist->hist->cmd, 1);
		while (hist->hist->cmd->c)
		{
			ft_putchar_fd(hist->hist->cmd->c, fd);
			hist->hist->cmd = hist->hist->cmd->next;
		}
		ft_putchar_fd(10, fd);
		hist = hist->next;
	}
	close(fd);
	return (1);
}
