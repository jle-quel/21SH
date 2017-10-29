/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_struct_for_read.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aroulin <aroulin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/06 14:32:43 by aroulin           #+#    #+#             */
/*   Updated: 2017/10/29 11:46:13 by jle-quel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/sh.h"

/*
*************** PUBLIC *********************************************************
*/

t_read			*init_struct_for_read(void)
{
	t_read		*read_std;

	if (!(read_std = (t_read *)ft_memalloc(sizeof(t_read))))
		return (NULL);
	if (!(read_std->cmd = create_element('\0')))
		return (NULL);
	gbl_save_read(read_std->cmd);
	return (read_std);
}
