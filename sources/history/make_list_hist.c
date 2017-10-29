/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   make_list_hist.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aroulin <aroulin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/23 19:59:30 by aroulin           #+#    #+#             */
/*   Updated: 2017/10/29 14:46:53 by jle-quel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/sh.h"

/*
*************** PUBLIC *********************************************************
*/

t_hist			*create_hist(t_read *read_std)
{
	t_hist		*lst;

	if (!read_std)
		return (NULL);
	if (!(lst = (t_hist *)ft_memalloc(sizeof(t_hist))))
		return (NULL);
	lst->hist = read_std;
	lst->next = NULL;
	lst->prev = NULL;
	return (lst);
}

int				make_list_hist(t_read *read_std)
{
	t_hist		*lst;

	lst = gbl_save_history(NULL, REC_STRUCT);
	if (lst)
	{
		while (lst->next)
			lst = lst->next;
		lst->next = create_hist(read_std);
		lst->next->prev = lst;
		gbl_save_history(lst->next, SAVE_STRUCT);
	}
	else
		gbl_save_history(create_hist(read_std), SAVE_STRUCT);
	return (1);
}
