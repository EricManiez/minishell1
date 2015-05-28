/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pf_csxlm.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emaniez <emaniez@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/07 16:23:55 by emaniez           #+#    #+#             */
/*   Updated: 2015/03/10 17:52:18 by emaniez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_printf.h>

void	pf_xhh(char **s, t_pf *arg, va_list ap)
{
	char	*num;
	va_list	cpy;

	va_copy(cpy, ap);
	if (!arg->prec && !(unsigned char)va_arg(cpy, unsigned long))
	{
		va_arg(ap, int);
		va_end(cpy);
		return ;
	}
	num = ft_dec2hex((unsigned char)va_arg(ap, unsigned long), 0, arg->caps);
	*s = ft_strjoin_fb(s, &num);
	va_end(cpy);
}

void	pf_xh(char **s, t_pf *arg, va_list ap)
{
	char	*num;
	va_list	cpy;

	va_copy(cpy, ap);
	if (!arg->prec && !(unsigned short)va_arg(cpy, unsigned long))
	{
		va_arg(ap, int);
		va_end(cpy);
		return ;
	}
	num = ft_dec2hex((unsigned short)va_arg(ap, unsigned long), 0, arg->caps);
	*s = ft_strjoin_fb(s, &num);
	va_end(cpy);
}

void	pf_xl(char **s, t_pf *arg, va_list ap)
{
	char	*num;
	va_list	cpy;

	va_copy(cpy, ap);
	if (!arg->prec && !va_arg(cpy, unsigned long))
	{
		va_arg(ap, int);
		va_end(cpy);
		return ;
	}
	num = ft_dec2hex(va_arg(ap, unsigned long), 0, arg->caps);
	*s = ft_strjoin_fb(s, &num);
	va_end(cpy);
}

void	pf_xll(char **s, t_pf *arg, va_list ap)
{
	char	*num;
	va_list	cpy;

	va_copy(cpy, ap);
	if (!arg->prec && !(unsigned long long)va_arg(cpy, unsigned long))
	{
		va_arg(ap, int);
		va_end(cpy);
		return ;
	}
	num = ft_dec2hex(va_arg(ap, unsigned long long), 0, arg->caps);
	*s = ft_strjoin_fb(s, &num);
	va_end(cpy);
}
