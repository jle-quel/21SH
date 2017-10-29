/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jefferso <jefferso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/06 07:01:47 by jefferso          #+#    #+#             */
/*   Updated: 2017/10/06 07:18:06 by jefferson        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/libft.h"

void	ft_putnbr_fd(int nb, int fd)
{
	long	new;

	new = nb;
	if (new < 0)
	{
		ft_putchar_fd('-', fd);
		new = -new;
	}
	if (new > 9)
	{
		ft_putnbr_fd(new / 10, fd);
		ft_putnbr_fd(new % 10, fd);
	}
	else
		ft_putchar_fd(new + '0', fd);
}
