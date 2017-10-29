/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_arraydup.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jle-quel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/28 23:33:01 by jle-quel          #+#    #+#             */
/*   Updated: 2017/10/28 23:35:14 by jle-quel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/libft.h"

/*
*************** PUBLIC *********************************************************
*/

char			**ft_arraydup(const char **argv)
{
	size_t		index;
	char		**new;

	new = NULL;
	if (argv)
	{
		index = 0;
		new = (char**)ft_memalloc(sizeof(char*) * (ft_arraylen(argv) + 1));
		while (argv[index])
		{
			new[index] = ft_strdup(argv[index]);
			index++;
		}
		new[index] = NULL;
	}
	return (new);
}
