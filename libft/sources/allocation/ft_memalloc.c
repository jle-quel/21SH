/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memalloc.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jefferso <jefferso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/06 16:50:42 by jefferso          #+#    #+#             */
/*   Updated: 2017/10/28 23:31:48 by jle-quel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/libft.h"

/*
*************** PRIVATE ********************************************************
*/

static char		error(void)
{
	ft_putendl_fd("Out of memory", 2);
	ft_canonique();
	exit(EXIT_FAILURE);
}

/*
*************** PUBLIC *********************************************************
*/

void			*ft_memalloc(size_t size)
{
	void			*mem;
	unsigned char	*str;

	mem = NULL;
	if (size > 0)
	{
		mem = malloc(size);
		if (mem == NULL)
			error();
		str = (unsigned char *)mem;
		while (size--)
			*str++ = 0;
	}
	return (mem);
}
