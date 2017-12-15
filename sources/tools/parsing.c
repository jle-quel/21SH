/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jle-quel <jle-quel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/04 12:05:58 by jle-quel          #+#    #+#             */
/*   Updated: 2017/11/05 11:47:47 by jle-quel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sh.h"

/*
*************** PUBLIC *********************************************************
*/

uint8_t			chk_quote(char c, uint8_t *status)
{
	if (c)
	{
		if (c == '\'' && !(*status & DQUOTE))
			*status = *status & QUOTE ? DEFAULT : QUOTE;
		else if (c == '\"' && !(*status & QUOTE))
			*status = *status & DQUOTE ? DEFAULT : DQUOTE;
	}
	return (*status);
}
