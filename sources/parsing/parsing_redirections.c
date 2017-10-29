/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_redirections.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jle-quel <jle-quel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/29 12:14:49 by jle-quel          #+#    #+#             */
/*   Updated: 2017/10/29 14:17:29 by jle-quel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/sh.h"

/*
*************** PRIVATE ********************************************************
*/

static char		*get_rest(t_list *node)
{
	size_t		length;
	char		**temp;
	char		*rest;

	rest = NULL;
	if (node)
	{
		length = get_length_redirection(node->str, 0, ' ');
		temp = ft_strsplit(node->str, ' ');
		rest = temp[1] ? node->str + (length + ft_strlen(temp[0])) : NULL;
		ft_arraydel(&temp);
	}
	return (rest);
}

static void		remove_rest(t_list *node, char *rest)
{
	char		*new;

	if (node)
	{
		new = ft_strsub(node->str, 0, ft_strlen(node->str) - ft_strlen(rest));
		ft_memdel((void**)&node->str);
		node->str = new;
	}
}

static void		add_rest(char **str, char **argv)
{
	char		*memory;

	memory = *str;
	*str = ft_strjoin(*str, *argv);
	ft_memdel((void**)&memory);
	ft_memdel((void**)argv);
}

static void		get_argv(t_list *node, char **argv)
{
	char		*rest;
	char		*memory;

	rest = get_rest(node);
	memory = *argv;
	*argv = ft_strjoin(rest, *argv);
	remove_rest(node, rest);
	ft_memdel((void**)&memory);
}

/*
*************** PUBLIC *********************************************************
*/

void			parsing_redirections(t_list **node)
{
	t_list		*temp;
	char		*argv;

	temp = *node;
	argv = NULL;
	ft_ptrnext(&temp, ft_lstlen(temp));
	while (temp)
	{
		if (*temp->str == '>' || ft_isdigit(*temp->str) == 1)
			get_argv(temp->next, &argv);
		else if (chk_redirection(*temp->str) == true)
			add_rest(&temp->next->str, &argv);
		else if (!temp->prev)
			add_rest(&temp->str, &argv);
		temp = temp->prev;
	}
}
