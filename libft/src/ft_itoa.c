/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emaniez <emaniez@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/19 11:53:47 by emaniez           #+#    #+#             */
/*   Updated: 2015/03/09 14:10:34 by emaniez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_itoa(long n)
{
	long	j;
	char	*res;

	res = ft_memalloc(1);
	j = n;
	if (j == 0)
		return (ft_charjoin_f(&res, '0'));
	if (j == LONG_MAX)
		return (ft_strjoin_fl(&res, "9223372036854775807"));
	if (j == LONG_MIN)
		return (ft_strjoin_fl(&res, "-9223372036854775808"));
	if (j < 0)
		j = n * -1;
	while (j)
	{
		res = ft_charjoin_f(&res, j % 10 + 48);
		j = j / 10;
	}
	return (ft_strrev(res));
}
