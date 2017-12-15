/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   populating.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jle-quel <jle-quel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/06 10:58:34 by jle-quel          #+#    #+#             */
/*   Updated: 2017/11/06 19:14:03 by jle-quel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sh.h"

/*
*************** PUBLIC *********************************************************
*/

void			commands(t_ast **ast, t_parsing *node, char **env)
{
	size_t		place;

	place = 0;
	while (node)
	{
		if (!node->value)
		{
			create_access(node, env);
			add_to_tree(ast, place, node);
			place++;
		}
		node = node->prev;
	}
}

void			operaters(t_ast **ast, t_parsing *node, int priority)
{
	size_t		place;
	t_parsing	*temp;

	place = 0;
	temp = node;
	while (node)
	{
		if (node->value)
		{
			place++;
			node->priority == priority ? add_to_tree(ast, place, node) : 0;
		}
		node = node->prev;
	}
	temp && priority != 5 ? operaters(ast, temp, priority + 1) : 0;
}
