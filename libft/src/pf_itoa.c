/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_itoa.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emaniez <emaniez@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/14 14:23:00 by emaniez           #+#    #+#             */
/*   Updated: 2015/03/09 14:11:16 by emaniez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*pf_itoa(long long n, int absoluter)
{
	long	j;
	char	*res;

	if (n == 0)
		return (ft_strdup("0"));
	if (n == LONG_MAX)
		return (ft_strdup("9223372036854775807"));
	if (n == LONG_MIN)
	{
		if (absoluter)
			return (ft_strdup("9223372036854775808"));
		return (ft_strdup("-9223372036854775808"));
	}
	j = n;
	if (j < 0)
		j *= -1;
	res = ft_memalloc(1);
	while (j)
	{
		res = ft_charjoin_f(&res, j % 10 + 48);
		j = j / 10;
	}
	if (n < 0 && !absoluter)
		res = ft_charjoin_f(&res, '-');
	return (ft_strrev(res));
}
