/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prompt.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aroulin <aroulin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/19 14:22:37 by aroulin           #+#    #+#             */
/*   Updated: 2017/10/29 00:01:17 by jle-quel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/sh.h"

/*
*************** PRIVATE ********************************************************
*/

static t_cursor	init_cursor(int len)
{
	int			co;
	t_cursor	cur;

	cur = (t_cursor){1, 0};
	co = tgetnum("co");
	while (cur.co < len)
	{
		if (cur.co >= co)
		{
			cur.line += 1;
			cur.co = 0;
		}
		cur.co += 1;
	}
	return (cur);
}

/*
*************** PUBLIC *********************************************************
*/

t_cursor		prompt(unsigned char flags, char **env, unsigned char *ret)
{
	static char	*prompt;

	if (flags & HEREDOC && get_len_prompt(-2))
		prompt = " heredoc > ";
	else if (flags & DQUOTE && get_len_prompt(-1))
		prompt = " dquote > ";
	else if (flags & QUOTE && get_len_prompt(-1))
		prompt = " quote > ";
	else if (flags & NEXTCMD && get_len_prompt(-1))
		prompt = " nextcmd > ";
	else if (flags & DEFAULT)
		prompt = create_prompt(env, ret);
	if (flags & PRINT)
		ft_putstr_fd(prompt + 1, 2);
	return (init_cursor((get_len_prompt(-42) < 0) ? (int)ft_strlen(prompt) :
														get_len_prompt(-42)));
}
