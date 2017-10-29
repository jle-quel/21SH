/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ast_tools.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jle-quel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/18 15:51:51 by jle-quel          #+#    #+#             */
/*   Updated: 2017/10/28 23:47:27 by jle-quel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/sh.h"

/*
*************** PUBLIC *********************************************************
*/

void			ft_treedel(t_ast **ast)
{
	if (*ast)
	{
		ft_treedel(&(*ast)->left);
		ft_treedel(&(*ast)->right);
		ft_arraydel(&(*ast)->command);
		free(*ast);
		*ast = NULL;
	}
}

static t_ast	*create_ast(int place, t_list *node, char **command)
{
	t_ast	*new;

	new = (t_ast*)ft_memalloc(sizeof(t_ast));
	new->place = place ? place : 0;
	new->type = node ? (int)node->nb : 0;
	new->operater = node ? node->str : NULL;
	new->command = command ? command : NULL;
	new->left = NULL;
	new->right = NULL;
	return (new);
}

void			add_to_tree(t_ast **ast, int place, t_list *node,
				char **command)
{
	if (*ast == NULL)
	{
		*ast = create_ast(place, node, command);
		return ;
	}
	if (place < (*ast)->place)
		add_to_tree(&(*ast)->right, place, node, command);
	else if (place >= (*ast)->place)
		add_to_tree(&(*ast)->left, place, node, command);
}
