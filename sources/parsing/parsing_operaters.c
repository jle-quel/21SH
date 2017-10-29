/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_operaters.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jle-quel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/16 11:44:51 by jle-quel          #+#    #+#             */
/*   Updated: 2017/10/29 12:23:08 by jle-quel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/sh.h"

static const t_lexer	g_operaters[] =
{
	(t_lexer){";", COLON},
	(t_lexer){"|", PIPE},
	(t_lexer){"||", OR},
	(t_lexer){"&&", AND},
	(t_lexer){"<", LEFT},
	(t_lexer){"<<", LEFT},
	(t_lexer){">", RIGHT},
	(t_lexer){">>", RIGHT},
	(t_lexer){">&", AGGRE}
};

/*
*************** PRIVATE ********************************************************
*/

static void		error(char *str, t_list **node, unsigned char *ret)
{
	ft_putstr_fd("21sh: parse error near: ", 2);
	ft_putendl_fd(str, 2);
	ft_lstdel(node);
	*ret = 1;
}

static bool		chk(t_list *temp)
{
	short		index;

	index = 0;
	while (index < 9)
	{
		if (ft_strcmp(temp->str, g_operaters[index].str) == 0)
		{
			temp->nb = (size_t)g_operaters[index].type;
			return (true);
		}
		index++;
	}
	return (false);
}

/*
*************** PUBLIC *********************************************************
*/

void			parsing_operaters(t_list **node, unsigned char *ret)
{
	size_t		index;
	char		err;
	t_list		*temp;

	index = 0;
	temp = *node;
	while (temp)
	{
		if (index % 2 == 1)
		{
			err = chk(temp);
			if (err == false)
			{
				error(temp->str, node, ret);
				return ;
			}
		}
		index++;
		temp = temp->next;
	}
}
