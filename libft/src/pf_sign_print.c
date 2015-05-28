/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_sign_print.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emaniez <emaniez@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/21 10:10:00 by emaniez           #+#    #+#             */
/*   Updated: 2015/03/10 12:12:36 by emaniez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		h_sp(t_pf *arg, char **s, va_list cpy)
{
	if (arg->lm == 0)
	{
		if ((signed char)va_arg(cpy, int) < 0)
			ft_strpadding(1, '-', s);
		else if (arg->plus)
			ft_strpadding(1, '+', s);
		else if (arg->sp)
			ft_strpadding(1, ' ', s);
		return (1);
	}
	if (arg->lm == 1)
	{
		if ((short)va_arg(cpy, int) < 0)
			ft_strpadding(1, '-', s);
		else if (arg->plus)
			ft_strpadding(1, '+', s);
		else if (arg->sp)
			ft_strpadding(1, ' ', s);
		return (1);
	}
	return (0);
}

int		l_sp(t_pf *arg, char **s, va_list cpy)
{
	if (arg->lm == 2)
	{
		if (va_arg(cpy, long long) < 0)
			ft_strpadding(1, '-', s);
		else if (arg->plus)
			ft_strpadding(1, '+', s);
		else if (arg->sp)
			ft_strpadding(1, ' ', s);
		return (1);
	}
	if (arg->lm == 3)
	{
		if (va_arg(cpy, long) < 0)
			ft_strpadding(1, '-', s);
		else if (arg->plus)
			ft_strpadding(1, '+', s);
		else if (arg->sp)
			ft_strpadding(1, ' ', s);
		return (1);
	}
	return (0);
}

int		jz_sp(t_pf *arg, char **s, va_list cpy)
{
	if (arg->lm == 4)
	{
		if (va_arg(cpy, intmax_t) < 0)
			ft_strpadding(1, '-', s);
		else if (arg->plus)
			ft_strpadding(1, '+', s);
		else if (arg->sp)
			ft_strpadding(1, ' ', s);
		return (1);
	}
	if (arg->lm == 5)
	{
		if (va_arg(cpy, long long) == LLONG_MIN)
			ft_strpadding(1, '-', s);
		else if (arg->plus)
			ft_strpadding(1, '+', s);
		else if (arg->sp)
			ft_strpadding(1, ' ', s);
		return (1);
	}
	return (0);
}

int		pf_sign_print(t_pf *arg, char **s, va_list cpy)
{
	if (arg->cs == D)
	{
		if (arg->lm < 0)
		{
			if (va_arg(cpy, int) < 0)
				ft_strpadding(1, '-', s);
			else if (arg->plus)
				ft_strpadding(1, '+', s);
			else if (arg->sp)
				ft_strpadding(1, ' ', s);
			else
				return (0);
			return (1);
		}
		if (h_sp(arg, s, cpy) || l_sp(arg, s, cpy) || jz_sp(arg, s, cpy))
			return (1);
	}
	return (0);
}
