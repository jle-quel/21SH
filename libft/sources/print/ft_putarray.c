/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putarray.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jefferso <jefferso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/06 07:11:14 by jefferso          #+#    #+#             */
/*   Updated: 2017/10/06 07:12:09 by jefferson        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/libft.h"

void	ft_putarray(const char **argv)
{
	size_t	index;

	if (argv)
	{
		index = 0;
		while (argv[index])
		{
			ft_putendl(argv[index]);
			index++;
		}
	}
}
