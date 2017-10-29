/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jefferso <jefferso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/06 06:56:56 by jefferso          #+#    #+#             */
/*   Updated: 2017/10/06 07:17:58 by jefferson        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/libft.h"

void	ft_putnbr(int nb)
{
	long	new;

	new = nb;
	if (new < 0)
	{
		ft_putchar('-');
		new = -new;
	}
	if (new > 9)
	{
		ft_putnbr(new / 10);
		ft_putnbr(new % 10);
	}
	else
		ft_putchar(new + '0');
}
