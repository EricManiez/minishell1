/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pf_cso.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emaniez <emaniez@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/07 14:37:04 by emaniez           #+#    #+#             */
/*   Updated: 2015/03/10 11:49:31 by emaniez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_printf.h>

void	pf_oj(char **s, t_pf *arg, va_list ap)
{
	va_list			cpy;
	char			*num;

	va_copy(cpy, ap);
	if ((uintmax_t)va_arg(cpy, unsigned long) == 0)
	{
		if (arg->sharp)
			*s = ft_charjoin_f(s, '0');
		if (arg->prec && !arg->sharp)
		{
			num = ft_oct_conv((uintmax_t)va_arg(ap, unsigned long), 0);
			*s = ft_strjoin_fb(s, &num);
		}
		else
			va_arg(ap, uintmax_t);
	}
	else
	{
		if (arg->sharp)
			*s = ft_charjoin_f(s, '0');
		num = ft_oct_conv((uintmax_t)va_arg(ap, unsigned long), 0);
		*s = ft_strjoin_fb(s, &num);
	}
	va_end(cpy);
}

void	pf_oz(char **s, t_pf *arg, va_list ap)
{
	va_list			cpy;
	char			*num;

	va_copy(cpy, ap);
	if ((size_t)va_arg(cpy, unsigned long) == 0)
	{
		if (arg->sharp)
			*s = ft_charjoin_f(s, '0');
		if (arg->prec && !arg->sharp)
		{
			num = ft_oct_conv((size_t)va_arg(ap, unsigned long), 0);
			*s = ft_strjoin_fb(s, &num);
		}
		else
			va_arg(ap, size_t);
	}
	else
	{
		if (arg->sharp)
			*s = ft_charjoin_f(s, '0');
		num = ft_oct_conv((size_t)va_arg(ap, unsigned long), 0);
		*s = ft_strjoin_fb(s, &num);
	}
	va_end(cpy);
}

void	pf_onorm(char **s, t_pf *arg, va_list ap)
{
	va_list			cpy;
	char			*num;

	va_copy(cpy, ap);
	if ((int)va_arg(cpy, unsigned long) == 0)
	{
		if (arg->sharp)
			*s = ft_charjoin_f(s, '0');
		if (arg->prec && !arg->sharp)
		{
			num = ft_oct_conv((unsigned int)va_arg(ap, unsigned long), 0);
			*s = ft_strjoin_fb(s, &num);
		}
		else
			va_arg(ap, int);
	}
	else
	{
		if (arg->sharp)
			*s = ft_charjoin_f(s, '0');
		num = ft_oct_conv((unsigned int)va_arg(ap, unsigned long), 0);
		*s = ft_strjoin_fb(s, &num);
	}
	va_end(cpy);
}

void	pf_cso(char **s, t_pf *arg, va_list ap)
{
	void	(*lmpfun[6])(char **s, t_pf *arg, va_list ap);

	lmpfun[HH] = &pf_ohh;
	lmpfun[H] = &pf_oh;
	lmpfun[LL] = &pf_oll;
	lmpfun[L] = &pf_ol;
	lmpfun[J] = &pf_oj;
	lmpfun[Z] = &pf_oz;
	if (arg->lm >= 0)
		lmpfun[arg->lm](s, arg, ap);
	else
		pf_onorm(s, arg, ap);
}
