/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pf_len_calc.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emaniez <emaniez@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/06 10:45:14 by emaniez           #+#    #+#             */
/*   Updated: 2015/03/09 18:12:40 by emaniez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

size_t		pf_len_calc(va_list cpy, t_pf *arg)
{
	char	*s;
	va_list	ccp;
	size_t	ret;

	va_copy(ccp, cpy);
	s = ft_memalloc(1);
	pf_redirection(&s, arg, ccp);
	va_end(ccp);
	ret = ft_strlen(s) + arg->extra_chars;
	ft_strdel(&s);
	return (ret);
}
