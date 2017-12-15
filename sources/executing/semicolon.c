/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   semicolon.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jle-quel <jle-quel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/06 15:41:41 by jle-quel          #+#    #+#             */
/*   Updated: 2017/11/06 20:08:47 by jle-quel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sh.h"

/*
*************** PUBLIC *********************************************************
*/

void			ft_semicolon(t_ast *ast, t_shell *shell, t_process *process)
{
	executing(ast->left, shell, process);
	executing(ast->right, shell, process);
}
