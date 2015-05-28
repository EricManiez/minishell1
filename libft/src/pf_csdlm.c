/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pf_csdlm.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emaniez <emaniez@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/07 14:32:01 by emaniez           #+#    #+#             */
/*   Updated: 2015/03/10 17:54:27 by emaniez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_printf.h>

void	pf_dhh(char **s, va_list ap, t_pf *arg)
{
	char	*num;
	va_list	cpy;

	va_copy(cpy, ap);
	if (!arg->prec && !(signed char)va_arg(cpy, long))
	{
		va_arg(ap, int);
		va_end(cpy);
		return ;
	}
	num = pf_itoa((signed char)va_arg(ap, long), 1);
	*s = ft_strjoin_fb(s, &num);
	va_end(cpy);
}

void	pf_dh(char **s, va_list ap, t_pf *arg)
{
	char	*num;
	va_list	cpy;

	va_copy(cpy, ap);
	if (!arg->prec && !(short)va_arg(cpy, long))
	{
		va_arg(ap, int);
		va_end(cpy);
		return ;
	}
	num = pf_itoa((short)va_arg(ap, long), 1);
	*s = ft_strjoin_fb(s, &num);
	va_end(cpy);
}

void	pf_dll(char **s, va_list ap, t_pf *arg)
{
	char	*num;
	va_list	cpy;

	va_copy(cpy, ap);
	if (!arg->prec && !(long long)va_arg(cpy, long))
	{
		va_arg(ap, int);
		va_end(cpy);
		return ;
	}
	num = pf_itoa((long long)va_arg(ap, long long), 1);
	*s = ft_strjoin_fb(s, &num);
	va_end(cpy);
}

void	pf_dl(char **s, va_list ap, t_pf *arg)
{
	char	*num;
	va_list	cpy;

	va_copy(cpy, ap);
	if (!arg->prec && !va_arg(cpy, long))
	{
		va_arg(ap, int);
		va_end(cpy);
		return ;
	}
	num = pf_itoa(va_arg(ap, long), 1);
	*s = ft_strjoin_fb(s, &num);
	va_end(cpy);
}
