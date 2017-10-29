/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   variable.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jle-quel <jle-quel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/24 12:15:59 by jle-quel          #+#    #+#             */
/*   Updated: 2017/10/29 14:07:41 by jle-quel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/sh.h"

/*
*************** PRIVATE ********************************************************
*/

static void		do_expansion(char **str, char *rest, char **env)
{
	size_t		length;
	char		*temp;
	char		*var;
	char		*new;

	if (rest[1] && rest[1] != ' ')
	{
		length = ft_strrlen(rest, ' ', 1);
		temp = ft_strsub(rest, 1, length);
		var = ft_getenv(env, temp);
		new = ft_memalloc(ft_strlen(*str) + ft_strlen(var));
		ft_strncpy(new, *str, ft_strlen(*str) - ft_strlen(rest));
		ft_strcat(new, var);
		ft_strcat(new, rest + ft_strlen(temp) + 1);
		ft_memdel((void**)&temp);
		ft_memdel((void**)str);
		*str = new;
	}
}

/*
*************** PUBLIC *********************************************************
*/

void			expanding_var(char **str, char **env, unsigned char ret)
{
	size_t		index;
	int			s_quote;
	int			d_quote;

	(void)ret;
	index = 0;
	s_quote = 0;
	d_quote = 0;
	while ((*str)[index])
	{
		if (chk_slash((*str), index - 1) == true)
		{
			chk_quotes((*str)[index], '\"', &s_quote, &d_quote);
			chk_quotes((*str)[index], '\'', &d_quote, &s_quote);
			if (s_quote == 0 && (*str)[index] == '$')
				do_expansion(str, *str + index, env);
		}
		index++;
	}
}
