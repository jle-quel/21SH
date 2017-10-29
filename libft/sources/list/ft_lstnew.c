/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jle-quel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/28 23:15:56 by jle-quel          #+#    #+#             */
/*   Updated: 2017/10/28 23:16:22 by jle-quel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/libft.h"

/*
*************** PUBLIC *********************************************************
*/

void			ft_lstnew(t_list **node, const char *str,
				const char **argv, size_t number)
{
	t_list		*new;

	new = (t_list*)ft_memalloc(sizeof(t_list));
	new->str = ft_strdup(str);
	new->argv = ft_arraydup(argv);
	new->nb = number;
	new->next = NULL;
	new->prev = NULL;
	if (*node == NULL)
		*node = new;
	else
		ft_lstadd(*node, new);
}
