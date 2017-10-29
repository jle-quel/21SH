/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operaters.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jle-quel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/17 16:21:40 by jle-quel          #+#    #+#             */
/*   Updated: 2017/10/29 12:12:51 by jle-quel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/sh.h"

/*
*************** PUBLIC *********************************************************
*/

void			bonus_tokens(t_ast **ast, int place, t_list *node, char *ope)
{
	(void)ope;
	if (ft_strstr(node->str, "||") || ft_strstr(node->str, "&&"))
		add_to_tree(ast, place, node, NULL);
}

void			second_tokens(t_ast **ast, int place, t_list *node, char *ope)
{
	(void)ope;
	if (node->str[0] != ';' && node->str[0] != '|' && node->str[0] != '&')
		add_to_tree(ast, place, node, NULL);
}

void			primary_tokens(t_ast **ast, int place, t_list *node, char *ope)
{
	if (ft_strstr(node->str, ope))
		add_to_tree(ast, place, node, NULL);
}

void			operaters(t_ast **ast, t_list *node, char *ope,
				void (*f)(t_ast **ast, int place, t_list *node, char *ope))
{
	int			index;
	int			place;

	index = 0;
	place = 0;
	while (node)
	{
		if (index % 2 == 1)
		{
			place++;
			f(ast, place, node, ope);
		}
		node = node->prev;
		index++;
	}
}
