/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_width_parse.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emaniez <emaniez@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/21 13:29:38 by emaniez           #+#    #+#             */
/*   Updated: 2015/03/09 16:29:22 by emaniez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

size_t		pf_width_parse(char *cs)
{
	char	*width;
	int		i;
	int		ret;

	width = ft_memalloc(1);
	i = -1;
	while (cs[++i] && (!ft_isdigit(cs[i]) || cs[i] == '0'))
	{
		if (cs[i] && cs[i] == '.')
		{
			while (cs[++i] && ft_isdigit(cs[i]))
				;
		}
	}
	while (cs[i] && ft_isdigit(cs[i]))
		width = ft_charjoin_f(&width, cs[i++]);
	ret = ft_atoi(width);
	ft_strdel(&width);
	return (ret);
}
