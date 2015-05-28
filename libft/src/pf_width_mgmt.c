/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_sign_print.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emaniez <emaniez@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/19 17:56:36 by emaniez           #+#    #+#             */
/*   Updated: 2015/03/09 15:45:34 by emaniez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	hex_mem_marker(char **s, t_pf *arg, va_list cpy, int phase)
{
	va_list	cpy2;

	va_copy(cpy2, cpy);
	if (phase == 1)
	{
		if (arg->cs == X && va_arg(cpy2, unsigned long) > 0)
			return (2);
		else if (arg->cs == P)
			return (2);
	}
	if (phase == 2)
	{
		if (arg->cs == X && va_arg(cpy2, unsigned long) > 0)
		{
			if (arg->caps)
				*(s) = ft_strjoin_fl(s, "0X");
			else
				*(s) = ft_strjoin_fl(s, "0x");
		}
		else if (arg->cs == P)
			*(s) = ft_strjoin_fl(s, "0x");
	}
	va_end(cpy2);
	return (0);
}

void		pf_width_mgmt(t_pf *arg, char **s, va_list cpy, int width)
{
	va_list	cpy2;

	va_copy(cpy2, cpy);
	if (arg->cs == P || (arg->cs == X && arg->sharp))
		width -= hex_mem_marker(s, arg, cpy, 1);
	if (!arg->zero && !arg->minus && width > 0)
	{
		ft_strpadding(width - 1, ' ', s);
		if (va_arg(cpy2, int) < 0 && arg->cs == D)
			ft_strpadding(1, '-', s);
		else if (arg->plus && arg->cs == D)
			ft_strpadding(1, '+', s);
		else
			ft_strpadding(1, ' ', s);
	}
	if (arg->cs == P || (arg->cs == X && arg->sharp))
		hex_mem_marker(s, arg, cpy, 2);
	if (arg->zero && width > 0)
		ft_strpadding(width - pf_sign_print(arg, s, cpy), '0', s);
	va_end(cpy2);
}
