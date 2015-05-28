/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pf_csulm.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emaniez <emaniez@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/09 17:16:51 by emaniez           #+#    #+#             */
/*   Updated: 2015/03/10 17:58:38 by emaniez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_printf.h>

void	pf_uhh(char **s, va_list ap, t_pf *arg)
{
	char	*num;
	va_list	cpy;

	va_copy(cpy, ap);
	if (!arg->prec && !(unsigned char)va_arg(cpy, long))
	{
		va_arg(ap, int);
		va_end(cpy);
		return ;
	}
	num = ft_uitoa((unsigned char)va_arg(ap, long));
	*s = ft_strjoin_fb(s, &num);
	va_end(cpy);
}

void	pf_uh(char **s, va_list ap, t_pf *arg)
{
	char	*num;
	va_list	cpy;

	va_copy(cpy, ap);
	if (!arg->prec && !(unsigned short)va_arg(cpy, long))
	{
		va_arg(ap, int);
		va_end(cpy);
		return ;
	}
	num = ft_uitoa((unsigned short)va_arg(ap, long));
	*s = ft_strjoin_fb(s, &num);
	va_end(cpy);
}

void	pf_ull(char **s, va_list ap, t_pf *arg)
{
	char	*num;
	va_list	cpy;

	va_copy(cpy, ap);
	if (!arg->prec && !(unsigned long long)va_arg(cpy, long))
	{
		va_arg(ap, int);
		va_end(cpy);
		return ;
	}
	num = ft_uitoa((unsigned long long)va_arg(ap, long long));
	*s = ft_strjoin_fb(s, &num);
	va_end(cpy);
}

void	pf_ul(char **s, va_list ap, t_pf *arg)
{
	char	*num;
	va_list	cpy;

	va_copy(cpy, ap);
	if (!arg->prec && !(unsigned long)va_arg(cpy, long))
	{
		va_arg(ap, int);
		va_end(cpy);
		return ;
	}
	num = ft_uitoa((unsigned long)va_arg(ap, long));
	*s = ft_strjoin_fb(s, &num);
	va_end(cpy);
}
