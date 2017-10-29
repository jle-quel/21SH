/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcat.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jle-quel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/28 23:14:48 by jle-quel          #+#    #+#             */
/*   Updated: 2017/10/28 23:15:45 by jle-quel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/libft.h"

/*
*************** PUBLIC *********************************************************
*/

char			*ft_strcat(char *s1, const char *s2)
{
	int			index;
	int			len;

	index = 0;
	len = 0;
	if (s1)
	{
		while (s1[index] != '\0')
			index++;
	}
	if (s2)
	{
		while (s2[len] != '\0')
			s1[index++] = s2[len++];
	}
	if (s1)
		s1[index] = '\0';
	return (s1);
}
