/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jefferso <jefferso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/06 06:52:58 by jefferso          #+#    #+#             */
/*   Updated: 2017/10/06 06:53:30 by jefferson        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/libft.h"

void	ft_putstr_fd(const char *str, int fd)
{
	if (str && fd >= 0)
		write(fd, str, ft_strlen(str));
}
