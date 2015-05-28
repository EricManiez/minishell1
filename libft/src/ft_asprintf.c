/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pf_main.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emaniez <emaniez@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/14 15:56:25 by emaniez           #+#    #+#             */
/*   Updated: 2015/03/16 15:23:26 by emaniez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_asprintf(char **str, const char *format, ...)
{
	va_list	ap;
	size_t	ret;

	setlocale(LC_ALL, "en_US.UTF-8");
	va_start(ap, format);
	ret = pf_read_loop(str, ap, (char*)format);
	va_end(ap);
	ret += ft_strlen(*str);
	return (ret);
}
