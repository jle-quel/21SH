/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tree.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jle-quel <jle-quel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/06 11:23:23 by jle-quel          #+#    #+#             */
/*   Updated: 2017/11/06 21:13:36 by jle-quel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sh.h"

/*
*************** PRIVATE ********************************************************
*/

static t_ast	*create_ast(size_t place, t_parsing *node)
{
	t_ast	*new;

	new = (t_ast*)ft_memalloc(sizeof(t_ast));
	new->place = place;
	new->value = node->value;
	new->command = node->command;
	new->left = NULL;
	new->right = NULL;
	return (new);
}

/*
*************** PUBLIC *********************************************************
*/

void			treedel(t_ast **ast)
{
	if (*ast)
	{
		treedel(&(*ast)->left);
		treedel(&(*ast)->right);
		ft_arraydel(&(*ast)->command);
		ft_memdel((void **)ast);
	}
}

void			add_to_tree(t_ast **ast, size_t place, t_parsing *node)
{
	if (*ast == NULL)
		*ast = create_ast(place, node);
	else if (place < (*ast)->place)
		add_to_tree(&(*ast)->right, place, node);
	else if (place >= (*ast)->place)
		add_to_tree(&(*ast)->left, place, node);
}
