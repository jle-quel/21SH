/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_and.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jle-quel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/16 18:31:28 by jle-quel          #+#    #+#             */
/*   Updated: 2017/10/16 18:35:27 by jle-quel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/sh.h"

/*
*************** PUBLIC *********************************************************
*/

void			ft_and(t_ast *ast, t_line *line, t_process *process)
{
	executing(ast->left, line, process);
	if (process->ret == 0)
		executing(ast->right, line, process);
}
