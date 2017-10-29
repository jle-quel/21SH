/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jle-quel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/28 23:30:04 by jle-quel          #+#    #+#             */
/*   Updated: 2017/10/28 23:32:50 by jle-quel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/libft.h"

/*
******************* PRIVATE ****************************************************
*/

static long long	ft_nblen(long long nb)
{
	int				i;

	i = 0;
	if (nb == 0)
		return (1);
	while (nb > 0)
	{
		nb /= 10;
		i++;
	}
	return (i);
}

/*
******************** PUBLIC ****************************************************
*/

char				*ft_itoa(int n)
{
	char			*str;
	int				len;
	int				neg_f;
	long long		num;

	neg_f = (n >= 0) ? 0 : 1;
	num = n;
	num = (neg_f) ? -num : num;
	len = (neg_f) ? ft_nblen(num) + 1 : ft_nblen(num);
	str = (char*)ft_memalloc(sizeof(char) * (len + 1));
	if (num == 0)
	{
		str[0] = '0';
		return (str);
	}
	if (neg_f)
		str[0] = '-';
	str[len] = '\0';
	while (len-- > neg_f)
	{
		str[len] = num % 10 + '0';
		num /= 10;
	}
	return (str);
}
