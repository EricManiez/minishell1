/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pf_string_mgmt.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emaniez <emaniez@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/06 10:44:14 by emaniez           #+#    #+#             */
/*   Updated: 2015/03/06 11:20:33 by emaniez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void		pf_string_mgmt(char **s, va_list ap, char *cs)
{
	va_list	cpy;
	char	*sub;

	va_copy(cpy, ap);
	if (va_arg(cpy, char*))
	{
		if (ft_strchr(cs, '.'))
		{
			sub = ft_strsub(va_arg(ap, char*), 0, pf_prec_parse(cs));
			*(s) = ft_strjoin_fb(s, &sub);
		}
		else
			*(s) = ft_strjoin_fl(s, va_arg(ap, char*));
	}
	else
		*(s) = ft_strjoin_fl(s, "(null)");
	va_end(cpy);
}
