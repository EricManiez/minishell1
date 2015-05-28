/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pf_struct_fill.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emaniez <emaniez@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/05 17:12:36 by emaniez           #+#    #+#             */
/*   Updated: 2015/03/09 16:56:17 by emaniez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_printf.h>

int		cs_def(t_pf *arg, char *cs)
{
	if (ft_strchrstr(cs, "CDOUS"))
		arg->lm = 3;
	if (ft_strchrstr(cs, "OUX"))
		arg->caps = 1;
	if (ft_strchrstr(cs, "sS"))
		return (S);
	else if (ft_strchrstr(cs, "p"))
		return (P);
	else if (ft_strchrstr(cs, "dDi"))
		return (D);
	else if (ft_strchrstr(cs, "oO"))
		return (O);
	else if (ft_strchrstr(cs, "uU"))
		return (U);
	else if (ft_strchrstr(cs, "xX"))
		return (X);
	else if (ft_strchrstr(cs, "cC"))
		return (C);
	return (-1);
}

int		lm_def(char *cs)
{
	if (ft_strstr(cs, "hh"))
		return (HH);
	else if (ft_strchr(cs, 'h'))
		return (H);
	else if (ft_strstr(cs, "ll"))
		return (LL);
	else if (ft_strchr(cs, 'l'))
		return (L);
	else if (ft_strchr(cs, 'j'))
		return (J);
	else if (ft_strchr(cs, 'z'))
		return (Z);
	return (-1);
}

int		zero_parse(char *s)
{
	int	i;

	i = 0;
	if (s[0] == '0')
		return (1);
	while (s[++i])
	{
		if (s[i] == '0' && !ft_isdigit(s[i - 1]))
			return (1);
	}
	return (0);
}

void	pf_struct_fill(t_pf *arg, char *cs)
{
	arg->lm = lm_def(cs);
	arg->cs = cs_def(arg, cs);
	if (ft_strchr(cs, '#'))
		arg->sharp = 1;
	arg->zero = zero_parse(cs);
	if (ft_strchr(cs, '-'))
	{
		arg->minus = 1;
		arg->zero = 0;
	}
	if (ft_strchr(cs, ' '))
		arg->sp = 1;
	if (ft_strchr(cs, '+'))
	{
		arg->plus = 1;
		arg->sp = 0;
	}
	arg->prec = pf_prec_parse(cs);
	arg->width = pf_width_parse(cs);
	if (arg->prec >= 0 && D <= arg->cs && arg->cs <= X)
		arg->zero = 0;
}
