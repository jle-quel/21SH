/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   split_tools.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jle-quel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/29 12:39:48 by jle-quel          #+#    #+#             */
/*   Updated: 2017/10/29 12:45:31 by jle-quel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/sh.h"

/*
*************** PUBLIC *********************************************************
*/

void			do_skip(char *str, size_t *index)
{
	while (str[*index])
	{
		if (str[*index] != ' ')
			break ;
		*index += 1;
	}
}

void			skip_quote(char *str, size_t *index, char c)
{
	*index += 1;
	while (str[*index])
	{
		if (str[*index] == c)
			break ;
		*index += 1;
	}
}
