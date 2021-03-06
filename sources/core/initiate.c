/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initiate.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jle-quel <jle-quel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/13 10:00:58 by jle-quel          #+#    #+#             */
/*   Updated: 2017/11/06 21:17:57 by jle-quel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sh.h"

/*
*************** PUBLIC *********************************************************
*/

t_shell			*initiate_shell(void)
{
	t_shell			*new;
	extern char		**environ;

	new = (t_shell*)ft_memalloc(sizeof(t_shell));
	new->env = ft_arraydup((const char**)environ);
	return (new);
}

t_process		*initiate_process(void)
{
	t_process	*new;

	new = (t_process*)ft_memalloc(sizeof(t_process));
	return (new);
}
