/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pf_csc.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emaniez <emaniez@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/07 16:24:11 by emaniez           #+#    #+#             */
/*   Updated: 2015/03/10 19:25:56 by emaniez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void		lchar(char **s, t_pf *arg, va_list ap)
{
	va_list	cpy;

	va_copy(cpy, ap);
	if ((wchar_t)va_arg(cpy, wchar_t))
		*s = ft_wcharjoin_f(s, va_arg(ap, wchar_t));
	else
	{
		arg->extra_chars++;
		va_arg(ap, int);
	}
	va_end(cpy);
}

void		norm_char(char **s, t_pf *arg, va_list ap)
{
	va_list	cpy;

	va_copy(cpy, ap);
	if ((char)va_arg(cpy, int))
		*(s) = ft_charjoin_f(s, (char)va_arg(ap, int));
	else
	{
		arg->extra_chars++;
		va_arg(ap, int);
	}
	va_end(cpy);
}

void		pf_csc(char **s, t_pf *arg, va_list ap)
{
	if (arg->lm == 3)
		lchar(s, arg, ap);
	else
		norm_char(s, arg, ap);
}
