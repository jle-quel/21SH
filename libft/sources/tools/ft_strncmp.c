/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jle-quel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/24 21:22:49 by jle-quel          #+#    #+#             */
/*   Updated: 2017/10/28 22:22:05 by jle-quel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/libft.h"

/*
*************** PUBLIC *********************************************************
*/

int				ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t		index;

	index = 0;
	if (!n || !s1 || !s2)
		return (-1);
	while (index < n - 1 && s1[index] && s2[index] && s1[index] == s2[index])
		index++;
	return ((unsigned char)s1[index] - (unsigned char)s2[index]);
}
