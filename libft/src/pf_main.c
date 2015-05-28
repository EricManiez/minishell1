/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pf_main.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emaniez <emaniez@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/14 15:56:25 by emaniez           #+#    #+#             */
/*   Updated: 2015/03/10 19:11:16 by emaniez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_printf(const char *format, ...)
{
	char	*str;
	va_list	ap;
	size_t	ret;

	setlocale(LC_ALL, "en_US.UTF-8");
	str = ft_memalloc(1);
	va_start(ap, format);
	ret = pf_read_loop(&str, ap, (char*)format);
	write(1, str, ft_strlen(str));
	va_end(ap);
	ret += ft_strlen(str);
	if (ret)
		ft_strdel(&str);
	return (ret);
}
