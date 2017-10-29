/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_arrayjoin.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jle-quel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/13 17:25:45 by jle-quel          #+#    #+#             */
/*   Updated: 2017/10/28 23:32:36 by jle-quel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/libft.h"

/*
*************** PUBLIC *********************************************************
*/

char			**ft_arrayjoin(const char **a1, const char **a2)
{
	size_t		index;
	size_t		i;
	char		**new;

	new = NULL;
	if (!a1 && a2)
		return (ft_arraydup(a2));
	if (!a2 && a1)
		return (ft_arraydup(a1));
	if (!a1 && !a2)
		return (NULL);
	index = 0;
	i = 0;
	new = (char**)ft_memalloc(sizeof(char*) *
									(ft_arraylen(a1) + ft_arraylen(a2) + 1));
	while (a1[i])
		new[index++] = ft_strdup(a1[i++]);
	i = 0;
	while (a2[i])
		new[index++] = ft_strdup(a2[i++]);
	new[index] = NULL;
	return (new);
}
