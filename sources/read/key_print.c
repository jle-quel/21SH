/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_print.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aroulin <aroulin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/12 21:50:30 by aroulin           #+#    #+#             */
/*   Updated: 2017/10/29 16:28:18 by jle-quel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/sh.h"

/*
*************** PUBLIC *********************************************************
*/

t_cmd			*create_element(char c)
{
	t_cmd		*element;

	element = (t_cmd *)ft_memalloc(sizeof(t_cmd));
	element->next = NULL;
	element->prev = NULL;
	element->c = c;
	return (element);
}

int				key_print_fct(t_cmd *cmd, char c)
{
	t_cmd		*element;

	element = create_element(c);
	element->prev = cmd->prev;
	element->next = cmd;
	if (cmd->prev)
		cmd->prev->next = element;
	cmd->prev = element;
	return (1);
}

int				key_print_(t_read **read_std, unsigned long *buff)
{
	unsigned char	c;

	while (*buff)
	{
		c = (unsigned char)(*buff % (UCHAR_MAX + 1));
		*buff /= (UCHAR_MAX + 1);
		if (ft_iscrlf(c) && key_enter_(read_std, c))
			return (1);
		else if (ft_isprint(c))
		{
			key_print_fct((*read_std)->cmd, c);
			(*read_std)->print = 2;
		}
	}
	return (1);
}
