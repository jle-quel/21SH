/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initiate.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jle-quel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/13 10:00:58 by jle-quel          #+#    #+#             */
/*   Updated: 2017/10/29 12:56:45 by jle-quel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/sh.h"

t_line			*initiate_line(void)
{
	t_line			*new;
	extern char		**environ;

	new = (t_line*)ft_memalloc(sizeof(t_line));
	new->env = ft_arraydup((const char**)environ);
	return (new);
}

t_process		*initiate_process(void)
{
	t_process	*new;

	new = (t_process*)ft_memalloc(sizeof(t_process));
	new->logger = open("/tmp/.logger", O_RDWR | O_CREAT | O_TRUNC, 0644);
	return (new);
}
