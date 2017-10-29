/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   executing.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jle-quel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/17 16:06:34 by jle-quel          #+#    #+#             */
/*   Updated: 2017/10/29 12:57:07 by jle-quel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/sh.h"

static const t_blts		g_builtins[] =
{
	(t_blts){"echo", &ft_echo},
	(t_blts){"env", &env},
	(t_blts){"exit", &exiit},
	(t_blts){"setenv", &seteenv},
	(t_blts){"unsetenv", &unseteenv},
	(t_blts){"cd", &cd}
};

static const t_exec		g_functions[] =
{
	(t_exec){COLON, &colon},
	(t_exec){AND, &ft_and},
	(t_exec){OR, &ft_or},
	(t_exec){PIPE, &ft_pipe},
	(t_exec){LEFT, &ft_left},
	(t_exec){RIGHT, &right},
	(t_exec){AGGRE, &ft_aggre}
};

/*
*************** PRIVATE ********************************************************
*/

static void		functions(t_ast *ast, t_line *line, t_process *process)
{
	short		index;

	index = 0;
	while (index < 7)
	{
		if (ast->type == g_functions[index].type)
			g_functions[index].f(ast, line, process);
		index++;
	}
}

static bool		builtins(t_ast *ast, t_line *line, t_process *process)
{
	short		index;

	index = 0;
	while (index < 6)
	{
		if (ft_strcmp(ast->command[0], g_builtins[index].str) == 0)
		{
			g_builtins[index].f(ast->command, &line->env, &process->ret);
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

void			executing(t_ast *ast, t_line *line, t_process *process)
{
	if (ast)
	{
		if (ast->operater)
			functions(ast, line, process);
		else if (builtins(ast, line, process) == false)
			ft_execve(ast, line, process);
	}
}
