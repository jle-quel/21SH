/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   previous_history.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aroulin <aroulin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/24 15:34:32 by aroulin           #+#    #+#             */
/*   Updated: 2017/10/23 09:50:51 by jle-quel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/sh.h"

/*
*************** PUBLIC *********************************************************
*/

void			previous_history(t_read **read_std)
{
	t_hist		*hist;

	hist = gbl_save_history(NULL, REC_STRUCT);
	if (!(*read_std)->history && hist)
	{
		copy_cmd(read_std, hist->hist->cmd);
		(*read_std)->history = 1;
	}
	else if ((*read_std)->history && hist && hist->prev)
	{
		hist = hist->prev;
		memdel_cmd(&((*read_std)->cmd));
		copy_cmd(read_std, hist->hist->cmd);
	}
	gbl_save_history(hist, SAVE_STRUCT);
}
