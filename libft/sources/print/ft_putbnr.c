/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putbnr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jefferso <jefferso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/06 06:59:43 by jefferso          #+#    #+#             */
/*   Updated: 2017/10/06 07:01:03 by jefferson        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/libft.h"

void	ft_putbnr(int nb)
{
	int		index;

	index = 4096;
	while (index > 0)
	{
		if (nb < index)
			ft_putnbr(0);
		else
		{
			ft_putnbr(1);
			nb -= 2;
		}
		index /= 2;
	}
}
