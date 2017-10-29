/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gbl_save_history.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aroulin <aroulin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/23 19:51:12 by aroulin           #+#    #+#             */
/*   Updated: 2017/10/23 09:49:47 by jle-quel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/sh.h"

/*
*************** PUBLIC *********************************************************
*/

t_hist			*gbl_save_history(t_hist *hist, int flags)
{
	static t_hist	*save;

	if (flags & RESET_STRUCT)
		save = NULL;
	else if (flags & SAVE_STRUCT)
		save = hist;
	else if (flags & REC_STRUCT)
		return (save);
	return (NULL);
}
