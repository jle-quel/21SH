/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jle-quel <jle-quel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/01 22:14:21 by jle-quel          #+#    #+#             */
/*   Updated: 2017/11/06 22:19:54 by jle-quel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sh.h"

/*
*************** PRIVATE ********************************************************
*/

static void		err(char *str, uint8_t *ret, int err, t_parsing **node)
{
	error(str, ret, err);
	lstdel(node);
}

/*
*************** PUBLIC *********************************************************
*/

void			order(t_parsing **node, uint8_t *ret)
{
	uint8_t		rounds;
	t_parsing	*temp;

	if (node && *node)
	{
		rounds = 0;
		temp = *node;
		while (temp->next)
		{
			if (rounds == 0 && temp->value)
			{
				err(temp->input, ret, SYNTAX_ERR, node);
				return ;
			}
			rounds = rounds ? 0 : 1;
			temp = temp->next;
		}
		temp->value ? err(temp->input, ret, SYNTAX_ERR, node) : 0;
	}
}

void			syntax(t_parsing **node, uint8_t *ret)
{
	t_parsing	*temp;

	temp = *node;
	while (temp)
	{
		if (temp->input[0] == '&' && !temp->input[1])
		{
			err(temp->input, ret, NOT_SUPPORTED, node);
			return ;
		}
		if (temp->value == SYNTAX_ERR)
		{
			err(temp->input, ret, SYNTAX_ERR, node);
			return ;
		}
		temp = temp->next;
	}
}

void			empty(t_parsing **node, uint8_t *ret)
{
	t_parsing	*temp;

	temp = *node;
	while (temp)
	{
		if (ft_stronly(temp->input, ' '))
		{
			err(temp->input, ret, SYNTAX_ERR, node);
			return ;
		}
		temp = temp->next;
	}
}
