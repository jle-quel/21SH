/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   core.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jle-quel <jle-quel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/06 22:59:45 by jle-quel          #+#    #+#             */
/*   Updated: 2017/11/06 23:00:11 by jle-quel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sh.h"

/*
*************** PUBLIC *********************************************************
*/

void			lexing(t_parsing **node, t_cmd *cmd)
{
	tokenisation(cmd);
	lexer(cmd, node);
	token_recognition(*node);
}

void			parsing(t_parsing **node, uint8_t *ret)
{
	empty(node, ret);
	order(node, ret);
	syntax(node, ret);
}

void			expanding(t_parsing *node, char **env)
{
	tilde(node, env);
	variable(node, env);
	backslash(node);
	split(node);
}

void			populating(t_ast **ast, t_parsing *node, char **env)
{
	lstnext(&node);
	operaters(ast, node, PRIO_SEPARATOR);
	commands(ast, node, env);
}

void			delete(t_ast **ast, t_parsing **node, t_cmd **cmd)
{
	treedel(ast);
	lstdel(node);
	cmddel(cmd);
}
