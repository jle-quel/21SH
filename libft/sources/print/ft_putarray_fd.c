/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putarray_fd.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jefferso <jefferso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/06 07:12:21 by jefferso          #+#    #+#             */
/*   Updated: 2017/10/06 07:18:22 by jefferson        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/libft.h"

void	ft_putarray_fd(const char **argv, int fd)
{
	size_t	index;

	if (argv && fd >= 0)
	{
		index = 0;
		while (argv[index])
		{
			ft_putendl_fd(argv[index], fd);
			index++;
		}
	}
}
