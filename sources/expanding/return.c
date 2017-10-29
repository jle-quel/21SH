/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   return.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jle-quel <jle-quel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/24 12:15:09 by jle-quel          #+#    #+#             */
/*   Updated: 2017/10/29 14:01:51 by jle-quel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/sh.h"

/*
*************** PRIVATE ********************************************************
*/

static void		do_expansion(char **str, char *rest, unsigned char ret)
{
	char		*retuurn;
	char		*new;

	if (ft_strncmp(rest, "$?", 2) == 0)
	{
		retuurn = ft_itoa(ret);
		new = ft_memalloc(ft_strlen(*str) + ft_strlen(retuurn));
		ft_strncpy(new, *str, ft_strlen(*str) - ft_strlen(rest));
		ft_strcat(new, retuurn);
		ft_strcat(new, rest + 2);
		ft_memdel((void**)str);
		ft_memdel((void**)&retuurn);
		*str = new;
	}
}

/*
*************** PUBLIC *********************************************************
*/

void			expanding_ret(char **str, char **env, unsigned char ret)
{
	size_t		index;

	(void)env;
	index = 0;
	while ((*str)[index])
	{
		if (chk_slash((*str), index - 1) == true)
		{
			if ((*str)[index] == '$')
				do_expansion(str, *str + index, ret);
		}
		index++;
	}
}
