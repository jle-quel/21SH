/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jle-quel <jle-quel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/12 09:12:52 by jle-quel          #+#    #+#             */
/*   Updated: 2017/10/29 00:56:07 by jle-quel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/sh.h"

static void	*g_fct[] =
{
	&expanding_tilde,
	&expanding_pid,
	&expanding_ret,
	&expanding_var,
	&expanding_backslash,
	NULL
};

/*
*************** PRIVATE ********************************************************
*/

static void		parsing(t_line *line, unsigned char *ret)
{
	trim_str(&line->str);
	parsing_str(&line->str, ret);
	lexing(&line->node, line->str);
	parsing_operaters(&line->node, ret);
	parsing_words(&line->node, ret);
	parsing_stds(line->node);
	parsing_redirections(&line->node);
}

static void		expanding(t_line *line, unsigned char ret)
{
	size_t		index;

	index = 0;
	while (g_fct[index])
		iteration(line->node, line->env, ret, g_fct[index++]);
}

static void		populating(t_ast **ast, t_list *node, char **env)
{
	ft_ptrnext(&node, ft_lstlen(node));
	operaters(ast, node, ";", &primary_tokens);
	operaters(ast, node, NULL, &bonus_tokens);
	operaters(ast, node, "|", &primary_tokens);
	operaters(ast, node, NULL, &second_tokens);
	commands(ast, node, env);
}

static void		deleting(t_ast **ast, t_line *line)
{
	ft_treedel(ast);
	ft_memdel((void**)&line->prompt);
	ft_memdel((void**)&line->str);
	ft_lstdel(&line->node);
}

/*
*************** PUBLIC *********************************************************
*/

int				main(void)
{
	t_ast		*ast;
	t_line		*line;
	t_process	*process;

	ast = NULL;
	line = initiate_line();
	process = initiate_process();
	init_termcap();
	init_history(line->env);
	ft_signal();
	while (101010)
	{
		read_stdin(DEFAULT, line, process);
		parsing(line, &process->ret);
		expanding(line, process->ret);
		populating(&ast, line->node, line->env);
		executing(ast, line, process);
		deleting(&ast, line);
	}
}
