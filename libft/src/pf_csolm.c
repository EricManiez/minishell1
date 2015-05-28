/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pf_csolm.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emaniez <emaniez@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/07 15:28:55 by emaniez           #+#    #+#             */
/*   Updated: 2015/03/10 17:53:45 by emaniez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_printf.h>

void	pf_ohh(char **s, t_pf *arg, va_list ap)
{
	va_list			cpy;
	char			*num;

	va_copy(cpy, ap);
	if ((unsigned char)va_arg(cpy, unsigned long) == 0)
	{
		if (arg->sharp)
			*s = ft_charjoin_f(s, '0');
		if (arg->prec && !arg->sharp)
		{
			num = ft_oct_conv((unsigned char)va_arg(ap, unsigned long), 0);
			*s = ft_strjoin_fb(s, &num);
		}
		else
			va_arg(ap, unsigned long);
	}
	else
	{
		if (arg->sharp)
			*s = ft_charjoin_f(s, '0');
		num = ft_oct_conv((unsigned char)va_arg(ap, unsigned long), 0);
		*s = ft_strjoin_fb(s, &num);
	}
	va_end(cpy);
}

void	pf_oh(char **s, t_pf *arg, va_list ap)
{
	va_list			cpy;
	char			*num;

	va_copy(cpy, ap);
	if ((unsigned short)va_arg(cpy, unsigned long) == 0)
	{
		if (arg->sharp)
			*s = ft_charjoin_f(s, '0');
		if (arg->prec && !arg->sharp)
		{
			num = ft_oct_conv((unsigned short)va_arg(ap, unsigned long), 0);
			*s = ft_strjoin_fb(s, &num);
		}
		else
			va_arg(ap, unsigned long);
	}
	else
	{
		if (arg->sharp)
			*s = ft_charjoin_f(s, '0');
		num = ft_oct_conv((unsigned short)va_arg(ap, unsigned long), 0);
		*s = ft_strjoin_fb(s, &num);
	}
	va_end(cpy);
}

void	pf_ol(char **s, t_pf *arg, va_list ap)
{
	va_list			cpy;
	char			*num;

	va_copy(cpy, ap);
	if ((unsigned long)va_arg(cpy, unsigned long) == 0)
	{
		if (arg->sharp)
			*s = ft_charjoin_f(s, '0');
		if (arg->prec && !arg->sharp)
		{
			num = ft_oct_conv((unsigned long)va_arg(ap, unsigned long), 0);
			*s = ft_strjoin_fb(s, &num);
		}
		else
			va_arg(ap, unsigned long);
	}
	else
	{
		if (arg->sharp)
			*s = ft_charjoin_f(s, '0');
		num = ft_oct_conv((unsigned long)va_arg(ap, unsigned long), 0);
		*s = ft_strjoin_fb(s, &num);
	}
	va_end(cpy);
}

void	pf_oll(char **s, t_pf *arg, va_list ap)

{
	va_list			cpy;
	char			*num;

	va_copy(cpy, ap);
	if (va_arg(cpy, unsigned long long) == 0)
	{
		if (arg->sharp)
			*s = ft_charjoin_f(s, '0');
		if (arg->prec && !arg->sharp)
		{
			num = ft_oct_conv(va_arg(ap, unsigned long long), 0);
			*s = ft_strjoin_fb(s, &num);
		}
		else
			va_arg(ap, unsigned long);
	}
	else
	{
		if (arg->sharp)
			*s = ft_charjoin_f(s, '0');
		num = ft_oct_conv(va_arg(ap, unsigned long long), 0);
		*s = ft_strjoin_fb(s, &num);
	}
	va_end(cpy);
}
