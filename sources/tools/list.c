/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jle-quel <jle-quel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/02 11:57:52 by jle-quel          #+#    #+#             */
/*   Updated: 2017/11/06 22:17:34 by jle-quel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sh.h"

/*
*************** PUBLIC *********************************************************
*/

t_parsing		*lstnew(char *input, int value, int priority, char **command)
{
	t_parsing	*new;

	new = (t_parsing *)ft_memalloc(sizeof(t_parsing));
	new->input = input;
	new->value = value;
	new->priority = priority;
	new->command = command;
	return (new);
}

void			lstadd(t_parsing *node, t_parsing *new)
{
	if (node && new)
	{
		while (node->next)
			node = node->next;
		node->next = new;
		new->prev = node;
	}
}

void			lstdel(t_parsing **node)
{
	t_parsing	*memory;

	while (*node)
	{
		memory = *node;
		*node = (*node)->next;
		ft_memdel((void **)&memory->input);
		memory->command = NULL;
		ft_memdel((void **)&memory);
	}
}

void			lstnext(t_parsing **node)
{
	if (*node)
	{
		while ((*node)->next)
			*node = (*node)->next;
	}
}

void			cmddel(t_cmd **cmd)
{
	t_cmd		*memory;

	while (*cmd)
	{
		memory = *cmd;
		*cmd = (*cmd)->next;
		ft_memdel((void **)&memory);
	}
}
