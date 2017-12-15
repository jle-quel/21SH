/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   executing.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jle-quel <jle-quel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/06 15:31:41 by jle-quel          #+#    #+#             */
/*   Updated: 2017/11/06 21:56:46 by jle-quel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sh.h"

static const t_exec		g_functions[] =
{
	(t_exec){VALUE_SEMI_COLON, &ft_semicolon},
	(t_exec){VALUE_AND_IF, &ft_and},
	(t_exec){VALUE_OR_IF, &ft_or},
	(t_exec){VALUE_PIPELINE, &ft_pipe},
	(t_exec){VALUE_LESS, &ft_left},
	(t_exec){VALUE_DLESS, &ft_doubleleft},
	(t_exec){VALUE_GREAT, &ft_right},
	(t_exec){VALUE_DGREAT, &ft_right},
	(t_exec){VALUE_GREAT_AND, &ft_aggre}
};

static const t_blts		g_builtins[] =
{
	(t_blts){"echo", &ft_echo},
	(t_blts){"env", &ft_env},
	(t_blts){"exit", &ft_exit},
	(t_blts){"setenv", &ft_setenv},
	(t_blts){"unsetenv", &ft_unsetenv},
	(t_blts){"cd", &ft_cd}
};

/*
*************** PRIVATE ********************************************************
*/

static void		functions(t_ast *ast, t_shell *shell, t_process *process)
{
	short		index;

	index = 0;
	while (index < 9)
	{
		if (ast->value == g_functions[index].value)
			g_functions[index].f(ast, shell, process);
		index++;
	}
}

static bool		builtins(t_ast *ast, t_shell *shell, t_process *process)
{
	short		index;

	index = 0;
	while (index < 6)
	{
		if (ft_strcmp(ast->command[0], g_builtins[index].str) == 0)
		{
			g_builtins[index].f(ast->command, &shell->env, &process->ret);
			process->forked == true ? exit(EXIT_SUCCESS) : 0;
			return (true);
		}
		index++;
	}
	return (false);
}

/*
*************** PUBLIC *********************************************************
*/

void			executing(t_ast *ast, t_shell *shell, t_process *process)
{
	if (ast)
	{
		if (ast->value)
			functions(ast, shell, process);
		else if (builtins(ast, shell, process) == false)
			ft_execve(ast, shell, process);
	}
}
