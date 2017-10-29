/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   backslash.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jle-quel <jle-quel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/24 17:42:02 by jle-quel          #+#    #+#             */
/*   Updated: 2017/10/29 14:01:18 by jle-quel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/sh.h"

/*
*************** PRIVATE ********************************************************
*/

static void		do_expansion(char **str, char *rest)
{
	char		*new;

	new = ft_memalloc(ft_strlen(*str));
	ft_strncpy(new, *str, ft_strlen(*str) - ft_strlen(rest));
	ft_strcat(new, rest + 1);
	ft_memdel((void**)str);
	*str = new;
}

/*
*************** PUBLIC *********************************************************
*/

void			expanding_backslash(char **str, char **env, unsigned char ret)
{
	size_t		index;
	int			s_quote;
	int			d_quote;

	(void)env;
	(void)ret;
	index = 0;
	s_quote = 0;
	d_quote = 0;
	while ((*str)[index])
	{
		chk_quotes((*str)[index], '\"', &s_quote, &d_quote);
		chk_quotes((*str)[index], '\'', &d_quote, &s_quote);
		if (s_quote == 0 && d_quote == 0 && (*str)[index] == '\\')
		{
			do_expansion(str, *str + index);
			(*str)[index] && (*str)[index] == '\\' ? index++ : 0;
		}
		else
			index++;
	}
}
