/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pf_csp.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emaniez <emaniez@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/06 11:57:57 by emaniez           #+#    #+#             */
/*   Updated: 2015/03/10 17:53:26 by emaniez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_printf.h>

void	pf_csp(char **s, t_pf *arg, va_list ap)
{
	char	*p;
	va_list	cpy;

	(void)arg;
	va_copy(cpy, ap);
	if ((unsigned long)va_arg(cpy, long) == 0)
	{
		if (!arg->prec)
			va_arg(ap, int);
		else
		{
			p = ft_dec2hex((unsigned long)va_arg(ap, void*), 0, 0);
			*s = ft_strjoin_fb(s, &p);
		}
	}
	else
	{
		p = ft_dec2hex((unsigned long)va_arg(ap, void*), 0, 0);
		*s = ft_strjoin_fb(s, &p);
	}
	va_end(cpy);
}
