/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pf_csx.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emaniez <emaniez@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/07 16:18:40 by emaniez           #+#    #+#             */
/*   Updated: 2015/03/10 17:52:50 by emaniez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_printf.h>

void	pf_xj(char **s, t_pf *arg, va_list ap)
{
	char	*num;
	va_list	cpy;

	va_copy(cpy, ap);
	if (!arg->prec && !(uintmax_t)va_arg(cpy, unsigned long))
	{
		va_arg(ap, int);
		va_end(cpy);
		return ;
	}
	num = ft_dec2hex((uintmax_t)va_arg(ap, unsigned long), 0, arg->caps);
	*s = ft_strjoin_fb(s, &num);
	va_end(cpy);
}

void	pf_xz(char **s, t_pf *arg, va_list ap)
{
	char	*num;
	va_list	cpy;

	va_copy(cpy, ap);
	if (!arg->prec && !(size_t)va_arg(cpy, unsigned long))
	{
		va_arg(ap, int);
		va_end(cpy);
		return ;
	}
	num = ft_dec2hex((size_t)va_arg(ap, unsigned long), 0, arg->caps);
	*s = ft_strjoin_fb(s, &num);
	va_end(cpy);
}

void	pf_csx(char **s, t_pf *arg, va_list ap)
{
	void	(*lmpfun[6])(char **s, t_pf *arg, va_list ap);
	char	*num;
	va_list	cpy;

	va_copy(cpy, ap);
	lmpfun[HH] = &pf_xhh;
	lmpfun[H] = &pf_xh;
	lmpfun[LL] = &pf_xll;
	lmpfun[L] = &pf_xl;
	lmpfun[J] = &pf_xj;
	lmpfun[Z] = &pf_xz;
	if (arg->lm >= 0)
		lmpfun[arg->lm](s, arg, ap);
	else
	{
		if (!arg->prec && !(unsigned int)va_arg(cpy, unsigned long))
		{
			va_arg(ap, long);
			va_end(cpy);
			return ;
		}
		num = ft_dec2hex((unsigned int)va_arg(ap, unsigned long), 0, arg->caps);
		*s = ft_strjoin_fb(s, &num);
	}
	va_end(cpy);
}
