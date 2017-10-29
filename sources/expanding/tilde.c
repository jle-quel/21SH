/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tilde.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jle-quel <jle-quel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/23 15:23:49 by jle-quel          #+#    #+#             */
/*   Updated: 2017/10/29 14:07:02 by jle-quel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/sh.h"

/*
*************** PRIVATE ********************************************************
*/

static bool		chk(const char *str, size_t index)
{
	if (index == 0 || !str[index - 1] || str[index - 1] == ' ')
	{
		if (!str[index + 1] || str[index + 1] == ' ' || str[index + 1] == '/')
		{
			if (str[index] == '~')
				return (true);
		}
	}
	return (false);
}

void			do_expansion(char **str, char *rest, char **env)
{
	char		*var;
	char		*new;

	var = ft_getenv(env, "HOME");
	if (var && ft_strlen(var) > 0)
	{
		new = ft_memalloc(ft_strlen(*str) + ft_strlen(var));
		ft_strncpy(new, *str, ft_strrlen(*str, '~', 0));
		ft_strcat(new, var);
		ft_strcat(new, rest + 1);
		ft_memdel((void **)str);
		*str = new;
	}
}

/*
*************** PUBLIC *********************************************************
*/

void			expanding_tilde(char **str, char **env, unsigned char ret)
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
			if (s_quote == 0 && d_quote == 0 && chk(*str, index) == true)
				do_expansion(str, *str + index, env);
		}
		index++;
	}
}
