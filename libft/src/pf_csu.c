/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pf_csu.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emaniez <emaniez@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/07 15:56:04 by emaniez           #+#    #+#             */
/*   Updated: 2015/03/10 17:53:01 by emaniez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_printf.h>

void	pf_uz(char **s, va_list ap, t_pf *arg)
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
	num = ft_uitoa((size_t)va_arg(ap, long));
	*s = ft_strjoin_fb(s, &num);
	va_end(cpy);
}

void	pf_uj(char **s, va_list ap, t_pf *arg)
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
	num = ft_uitoa((intmax_t)va_arg(ap, long));
	*s = ft_strjoin_fb(s, &num);
	va_end(cpy);
}

void	pf_csu(char **s, t_pf *arg, va_list ap)
{
	void	(*lmpfun[6])(char **s, va_list ap, t_pf *arg);
	char	*num;
	va_list	cpy;

	va_copy(cpy, ap);
	lmpfun[HH] = &pf_uhh;
	lmpfun[H] = &pf_uh;
	lmpfun[LL] = &pf_ull;
	lmpfun[L] = &pf_ul;
	lmpfun[J] = &pf_uj;
	lmpfun[Z] = &pf_uz;
	if (arg->lm >= 0)
		lmpfun[arg->lm](s, ap, arg);
	else
	{
		if (!arg->prec && !(unsigned int)va_arg(cpy, long))
		{
			va_arg(ap, int);
			va_end(cpy);
			return ;
		}
		num = ft_uitoa((unsigned int)va_arg(ap, long));
		*s = ft_strjoin_fb(s, &num);
	}
	va_end(cpy);
}
