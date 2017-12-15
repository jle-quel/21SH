/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   and.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jle-quel <jle-quel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/06 16:04:30 by jle-quel          #+#    #+#             */
/*   Updated: 2017/11/06 16:04:50 by jle-quel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sh.h"

/*
*************** PUBLIC *********************************************************
*/

void			ft_and(t_ast *ast, t_shell *shell, t_process *process)
{
	executing(ast->left, shell, process);
	if (process->ret == 0)
		executing(ast->right, shell, process);
}
