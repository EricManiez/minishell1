/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_prec_parse.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emaniez <emaniez@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/22 09:56:07 by emaniez           #+#    #+#             */
/*   Updated: 2015/03/09 17:26:04 by emaniez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int			pf_prec_parse(char *cs)
{
	char	*prec;
	int		ret;

	prec = ft_memalloc(1);
	while (*cs && *cs != '.')
		cs++;
	if (!*cs)
		return (-1);
	while (*(++cs) && ft_isdigit(*cs))
		prec = ft_charjoin_f(&prec, *cs);
	if (!prec[0])
		return (0);
	ret = ft_atoi(prec);
	ft_strdel(&prec);
	return (ret);
}
