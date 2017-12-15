/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jle-quel <jle-quel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/01 19:36:50 by jle-quel          #+#    #+#             */
/*   Updated: 2017/11/06 22:23:05 by jle-quel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sh.h"

/*
*************** PRIVATE ********************************************************
*/

static size_t	get_length(t_cmd *cmd, uint8_t rounds)
{
	size_t		length;

	length = 0;
	if (cmd)
	{
		while (cmd && cmd->c)
		{
			if (cmd->value != rounds)
				break ;
			length++;
			cmd = cmd->next;
		}
	}
	return (length);
}

static void		populate(t_cmd *cmd, size_t length, char *new)
{
	size_t		index;

	if (cmd)
	{
		index = 0;
		while (cmd && cmd->c && length--)
		{
			new[index++] = cmd->c;
			cmd = cmd->next;
		}
	}
}

static void		add_to_list(t_parsing **node, char *new)
{
	if (*node == NULL)
		*node = lstnew(new, 0, 0, NULL);
	else
		lstadd(*node, lstnew(new, 0, 0, NULL));
}

static void		skip(t_cmd **cmd, uint8_t rounds)
{
	if (*cmd)
	{
		while ((*cmd)->c)
		{
			if ((*cmd)->value != rounds)
				break ;
			*cmd = (*cmd)->next;
		}
	}
}

/*
*************** PUBLIC *********************************************************
*/

void			lexer(t_cmd *cmd, t_parsing **node)
{
	size_t		length;
	uint8_t		rounds;
	char		*new;

	if (cmd)
	{
		length = 0;
		rounds = 1;
		while (cmd->c)
		{
			length = get_length(cmd, rounds);
			if (length > 0)
			{
				new = ft_memalloc(length + 1);
				populate(cmd, length, new);
				add_to_list(node, new);
			}
			skip(&cmd, rounds);
			rounds = rounds == 1 ? 2 : 1;
		}
	}
}
