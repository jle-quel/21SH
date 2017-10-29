/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pid.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jle-quel <jle-quel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/24 12:09:58 by jle-quel          #+#    #+#             */
/*   Updated: 2017/10/29 14:01:35 by jle-quel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/sh.h"

/*
*************** PRIVATE ********************************************************
*/

static void		do_expansion(char **str, char *rest)
{
	char		*pid;
	char		*new;

	if (ft_strncmp(rest, "$$", 2) == 0)
	{
		pid = ft_itoa(getpid());
		new = ft_memalloc(ft_strlen(*str) + ft_strlen(pid));
		ft_strncpy(new, *str, ft_strlen(*str) - ft_strlen(rest));
		ft_strcat(new, pid);
		ft_strcat(new, rest + 2);
		ft_memdel((void**)str);
		ft_memdel((void**)&pid);
		*str = new;
	}
}

/*
*************** PUBLIC *********************************************************
*/

void			expanding_pid(char **str, char **env, unsigned char ret)
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
		if (chk_slash(*str, index - 1) == true)
		{
			chk_quotes((*str)[index], '\"', &s_quote, &d_quote);
			chk_quotes((*str)[index], '\'', &d_quote, &s_quote);
			if (s_quote == 0 && (*str)[index] == '$')
				do_expansion(str, *str + index);
		}
		index++;
	}
}
