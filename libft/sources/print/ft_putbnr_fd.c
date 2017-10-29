/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putbnr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jefferso <jefferso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/06 07:03:49 by jefferso          #+#    #+#             */
/*   Updated: 2017/10/06 07:17:46 by jefferson        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/libft.h"

void	ft_putbnr_fd(int nb, int fd)
{
	int		index;

	if (fd >= 0)
	{
		index = 4096;
		while (index > 0)
		{
			if (nb < index)
				ft_putnbr_fd(0, fd);
			else
			{
				ft_putnbr_fd(1, fd);
				nb -= 2;
			}
			index /= 2;
		}
	}
}
