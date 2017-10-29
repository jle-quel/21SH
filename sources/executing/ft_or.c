/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_or.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jle-quel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/17 18:12:00 by jle-quel          #+#    #+#             */
/*   Updated: 2017/10/17 18:37:41 by jle-quel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/sh.h"

/*
*************** PUBLIC *********************************************************
*/

void			ft_or(t_ast *ast, t_line *line, t_process *process)
{
	executing(ast->left, line, process);
	if (process->ret > 0)
		executing(ast->right, line, process);
}
