/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_getenv.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jle-quel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/19 16:49:06 by jle-quel          #+#    #+#             */
/*   Updated: 2017/10/28 23:08:31 by jle-quel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/libft.h"

/*
*************** PRIVATE ********************************************************
*/

static size_t	get_skip(char *str)
{
	size_t		index;

	index = 0;
	while (str[index])
	{
		if (str[index] == '=')
			break ;
		index++;
	}
	return (index);
}

/*
*************** PUBLIC *********************************************************
*/

char			*ft_getenv(char **env, char *variable)
{
	size_t	index;
	char	*temp;

	if (env && variable)
	{
		index = 0;
		while (env[index])
		{
			temp = ft_strsub(env[index], 0, get_skip(env[index]));
			if (!ft_strcmp(variable, temp))
			{
				ft_memdel((void **)&temp);
				return (env[index] + ft_strlen(variable) + 1);
			}
			ft_memdel((void **)&temp);
			index++;
		}
	}
	return (NULL);
}
