/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   next_history.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aroulin <aroulin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/24 16:30:08 by aroulin           #+#    #+#             */
/*   Updated: 2017/10/23 09:50:44 by jle-quel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/sh.h"

/*
*************** PUBLIC *********************************************************
*/

void			next_history(t_read **read_std)
{
	t_hist		*hist;

	hist = gbl_save_history(NULL, REC_STRUCT);
	if (hist && hist->next)
	{
		hist = hist->next;
		memdel_cmd(&((*read_std)->cmd));
		copy_cmd(read_std, hist->hist->cmd);
		(*read_std)->history = 1;
	}
	else if ((*read_std)->history)
	{
		memdel_cmd(&((*read_std)->cmd));
		(*read_std)->cmd = gbl_save_read(NULL);
		(*read_std)->history = 0;
	}
	gbl_save_history(hist, SAVE_STRUCT);
}
