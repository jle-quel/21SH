/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putendl_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jefferso <jefferso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/06 06:55:31 by jefferso          #+#    #+#             */
/*   Updated: 2017/10/06 07:19:26 by jefferson        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/libft.h"

void	ft_putendl_fd(const char *str, int fd)
{
	if (str && fd >= 0)
	{
		ft_putstr_fd(str, fd);
		ft_putchar_fd(10, fd);
	}
}
