/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pf_pre_print.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emaniez <emaniez@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/06 10:50:11 by emaniez           #+#    #+#             */
/*   Updated: 2015/03/09 18:13:24 by emaniez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void		pf_pre_print(t_pf *arg, char **s, va_list ap)
{
	va_list	cpy;
	int		prec_stock;

	va_copy(cpy, ap);
	arg->len = pf_len_calc(cpy, arg);
	va_end(cpy);
	prec_stock = arg->prec - arg->len;
	va_copy(cpy, ap);
	if ((P <= arg->cs && arg->cs <= X && arg->prec > arg->len) ||
			(arg->cs == S && arg->prec >= 0 && arg->prec < arg->len))
		arg->len = arg->prec;
	pf_width_mgmt(arg, s, cpy, arg->width - arg->len);
	if (arg->width < arg->len || arg->minus)
		pf_sign_print(arg, s, cpy);
	va_end(cpy);
	if (P <= arg->cs && arg->cs <= X && arg->prec >= 0 && prec_stock > 0)
		ft_strpadding(prec_stock, '0', s);
}
