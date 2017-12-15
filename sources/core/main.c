/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jle-quel <jle-quel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/12 09:12:52 by jle-quel          #+#    #+#             */
/*   Updated: 2017/11/06 23:00:19 by jle-quel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sh.h"

/*
*************** PUBLIC *********************************************************
*/

int				main(void)
{
	t_ast		*ast;
	t_shell		*shell;
	t_process	*process;
	t_cmd		*cmd;

	ast = NULL;
	shell = initiate_shell();
	process = initiate_process();
	init_termcap();
	init_history(shell->env);
	ft_signal();
	while (101010)
	{
		lexing(&shell->parsing, (cmd = read_stdin(DEFAULT, shell, process)));
		parsing(&shell->parsing, &process->ret);
		expanding(shell->parsing, shell->env);
		populating(&ast, shell->parsing, shell->env);
		executing(ast, shell, process);
		delete(&ast, &shell->parsing, &cmd);
	}
}
