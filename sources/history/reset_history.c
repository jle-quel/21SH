/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reset_history.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aroulin <aroulin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/02 16:35:21 by aroulin           #+#    #+#             */
/*   Updated: 2017/10/23 09:50:57 by jle-quel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/sh.h"

/*
*************** PUBLIC *********************************************************
*/

void			reset_history(void)
{
	t_hist			*tmp;

	if (!(tmp = gbl_save_history(NULL, REC_STRUCT)))
		return ;
	while (tmp->next)
		tmp = tmp->next;
	gbl_save_history(tmp, SAVE_STRUCT);
}
