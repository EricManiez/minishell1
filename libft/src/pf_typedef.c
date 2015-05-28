/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_typedef.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emaniez <emaniez@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/15 11:12:22 by emaniez           #+#    #+#             */
/*   Updated: 2015/03/10 18:52:58 by emaniez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void		init_struct(t_pf *arg, char *cs)
{
	arg->lm = -1;
	arg->cs = -1;
	arg->caps = 0;
	arg->sharp = 0;
	arg->zero = 0;
	arg->minus = 0;
	arg->plus = 0;
	arg->sp = 0;
	arg->prec = -1;
	arg->width = -1;
	arg->extra_chars = 0;
	arg->cscpy = ft_strdup(cs);
}

int			pf_typedef(char *cs, char **s, va_list ap)
{
	va_list	cpy;
	t_pf	arg;

	init_struct(&arg, cs);
	va_copy(cpy, ap);
	pf_struct_fill(&arg, cs);
	pf_pre_print(&arg, s, cpy);
	pf_redirection(s, &arg, ap);
	pf_post_print(&arg, s, cpy);
	va_end(cpy);
	return (arg.extra_chars / 2);
}
