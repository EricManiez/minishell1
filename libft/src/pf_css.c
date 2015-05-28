/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pf_css.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emaniez <emaniez@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/06 10:43:20 by emaniez           #+#    #+#             */
/*   Updated: 2015/03/10 19:28:20 by emaniez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void		lstring(char **s, t_pf *arg, va_list ap)
{
	va_list	cpy;
	char	*str;

	va_copy(cpy, ap);
	if (va_arg(cpy, wchar_t*))
	{
		if (arg->prec >= 0)
		{
			str = pf_wstrsub(va_arg(ap, wchar_t*), 0, arg->prec);
			str = ft_strsub(str, 0, arg->prec);
			*(s) = ft_strjoin_fb(s, &str);
		}
		else
			*(s) = ft_wstrjoin_f(s, va_arg(ap, wchar_t*));
	}
	else
	{
		if (arg->prec)
			*(s) = ft_strjoin_fl(s, "(null)");
		va_arg(ap, int);
	}
	va_end(cpy);
}

void		norm_string(char **s, t_pf *arg, va_list ap)
{
	va_list	cpy;
	char	*str;

	va_copy(cpy, ap);
	if (va_arg(cpy, char*))
	{
		if (arg->prec >= 0)
		{
			str = ft_strsub(va_arg(ap, char*), 0, arg->prec);
			*(s) = ft_strjoin_fb(s, &str);
		}
		else
			*(s) = ft_strjoin_fl(s, va_arg(ap, char*));
	}
	else
	{
		if (arg->prec)
			*(s) = ft_strjoin_fl(s, "(null)");
		va_arg(ap, int);
	}
	va_end(cpy);
}

void		pf_css(char **s, t_pf *arg, va_list ap)
{
	if (arg->lm == 3)
		lstring(s, arg, ap);
	else
		norm_string(s, arg, ap);
}
