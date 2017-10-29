/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jle-quel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/28 23:25:42 by jle-quel          #+#    #+#             */
/*   Updated: 2017/10/28 23:26:33 by jle-quel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/libft.h"

/*
*************** PUBLIC *********************************************************
*/

char			*ft_strjoin(char const *s1, char const *s2)
{
	size_t		index;
	size_t		i;
	char		*new;

	if (!s1 && s2)
		return (ft_strdup(s2));
	if (!s2 && s1)
		return (ft_strdup(s1));
	if (!s1 && !s2)
		return (NULL);
	index = 0;
	i = 0;
	new = ft_memalloc(ft_strlen(s1) + ft_strlen(s2) + 1);
	while (s1[i])
		new[index++] = s1[i++];
	i = 0;
	while (s2[i])
		new[index++] = s2[i++];
	return (new);
}
