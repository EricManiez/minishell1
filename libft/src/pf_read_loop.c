/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_read_loop.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emaniez <emaniez@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/15 12:04:15 by emaniez           #+#    #+#             */
/*   Updated: 2015/03/09 18:14:55 by emaniez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		pf_read_loop(char **str, va_list ap, char *format)
{
	char	*cs;
	int		prog;
	int		extra;

	prog = -1;
	cs = ft_memalloc(1);
	extra = 0;
	while ((prog = pf_parser(format, str, &cs, prog)))
	{
		if (cs[0])
			extra += pf_typedef(cs, str, ap);
	}
	return (extra);
}
