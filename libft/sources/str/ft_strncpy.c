/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jefferso <jefferso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/06 16:56:00 by jefferso          #+#    #+#             */
/*   Updated: 2017/10/06 16:59:45 by jefferson        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/libft.h"

char	*ft_strncpy(char *dst, const char *src, size_t len)
{
	size_t		index;
	size_t		size;

	if (dst)
	{
		index = 0;
		size = ft_strlen(src);
		while (index < len)
		{
			if (index > size)
				dst[index] = '\0';
			else
				dst[index] = src[index];
			index++;
		}
		return (dst);
	}
	return (NULL);
}
