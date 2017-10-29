/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jle-quel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/28 23:17:12 by jle-quel          #+#    #+#             */
/*   Updated: 2017/10/28 23:17:49 by jle-quel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/libft.h"

/*
*************** PUBLIC *********************************************************
*/

void			ft_lstadd(t_list *node, t_list *new)
{
	if (node && new)
	{
		while (node->next)
			node = node->next;
		node->next = new;
		new->prev = node;
	}
}