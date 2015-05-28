/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_retprintf.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emaniez <emaniez@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/16 15:24:43 by emaniez           #+#    #+#             */
/*   Updated: 2015/03/16 15:28:16 by emaniez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*ft_retprintf(const char *format, ...)
{
	va_list	ap;
	char	*str;

	setlocale(LC_ALL, "en_US.UTF-8");
	str = ft_memalloc(1);
	va_start(ap, format);
	pf_read_loop(&str, ap, (char*)format);
	va_end(ap);
	return (str);
}
