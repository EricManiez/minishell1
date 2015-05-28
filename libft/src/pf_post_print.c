/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_post_print.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emaniez <emaniez@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/21 13:50:26 by emaniez           #+#    #+#             */
/*   Updated: 2015/03/10 17:51:53 by emaniez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void		pf_post_print(t_pf *a, char **s, va_list ap)
{
	va_list	cpy;
	char	*d;

	va_copy(cpy, ap);
	va_end(cpy);
	va_copy(cpy, ap);
	if (a->cs == P)
		a->width -= 2;
	if (a->width > a->len && a->minus)
	{
		d = ft_memalloc(1);
		ft_strpadding(a->width - a->len - pf_sign_print(a, &d, cpy), ' ', s);
		ft_strdel(&d);
	}
	va_end(cpy);
}
