/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pf_csd.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emaniez <emaniez@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/06 12:12:48 by emaniez           #+#    #+#             */
/*   Updated: 2015/03/10 17:54:36 by emaniez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_printf.h>

void	pf_dz(char **s, va_list ap, t_pf *arg)
{
	char	*num;
	va_list	cpy;

	va_copy(cpy, ap);
	if (!arg->prec && !(size_t)va_arg(cpy, long))
	{
		va_arg(ap, int);
		va_end(cpy);
		return ;
	}
	num = pf_itoa((size_t)va_arg(ap, long), 1);
	*s = ft_strjoin_fb(s, &num);
	va_end(cpy);
}

void	pf_dj(char **s, va_list ap, t_pf *arg)
{
	char	*num;
	va_list	cpy;

	va_copy(cpy, ap);
	if (!arg->prec && !(intmax_t)va_arg(cpy, long))
	{
		va_arg(ap, int);
		va_end(cpy);
		return ;
	}
	num = pf_itoa((intmax_t)va_arg(ap, long), 1);
	*s = ft_strjoin_fb(s, &num);
	va_end(cpy);
}

void	pf_csd(char **s, t_pf *arg, va_list ap)
{
	void	(*lmpfun[6])(char **s, va_list ap, t_pf *arg);
	char	*num;
	va_list	cpy;

	va_copy(cpy, ap);
	lmpfun[HH] = &pf_dhh;
	lmpfun[H] = &pf_dh;
	lmpfun[LL] = &pf_dll;
	lmpfun[L] = &pf_dl;
	lmpfun[J] = &pf_dj;
	lmpfun[Z] = &pf_dz;
	if (arg->lm >= 0)
		lmpfun[arg->lm](s, ap, arg);
	else
	{
		if (!arg->prec && !(int)va_arg(cpy, long))
		{
			va_arg(ap, long);
			va_end(cpy);
			return ;
		}
		num = pf_itoa((int)va_arg(ap, long), 1);
		*s = ft_strjoin_fb(s, &num);
	}
	va_end(cpy);
}
