/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jle-quel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/28 23:07:14 by jle-quel          #+#    #+#             */
/*   Updated: 2017/10/28 23:07:45 by jle-quel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/libft.h"

/*
*************** PUBLIC *********************************************************
*/

int				ft_strcmp(const char *s1, const char *s2)
{
	int			index;

	index = 0;
	if (!s1 || !s2)
		return (-1);
	while (s1[index] == s2[index] && s1[index] != '\0' && s2[index] != '\0')
		index++;
	return (((unsigned char *)s1)[index] - ((unsigned char*)s2)[index]);
}
