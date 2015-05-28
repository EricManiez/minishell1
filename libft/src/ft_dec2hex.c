/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dec2hex.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emaniez <emaniez@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/06 10:51:44 by emaniez           #+#    #+#             */
/*   Updated: 2015/03/10 13:35:32 by emaniez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** A generic "decimal to hexadecimal" converter.
** Two extra functionalities :
** 	- "memswitch" : when activated (== 1), prints leading "0x" for use in
**		  memory-related applications
**	- "caps" : when activated (== 'X'), all letters turned to caps
*/

#include "libft.h"

static void			hex_conv_sub(unsigned long dec, char **hex)
{
	unsigned long long	mid;

	while (dec)
	{
		mid = dec % 16;
		if (mid > 9)
			*(hex) = ft_charjoin_f(hex, mid + 87);
		else
			*(hex) = ft_charjoin_f(hex, mid + 48);
		dec /= 16;
	}
}

char				*ft_dec2hex(unsigned long long dec, int memswitch, int caps)
{
	char			*hex;

	if (dec == 0)
		return (ft_strdup("0"));
	hex = ft_memalloc(1);
	hex_conv_sub(dec, &hex);
	if (memswitch)
		hex = ft_strjoin_fl(&hex, "x0");
	if (caps)
		hex = ft_toupperstr(hex);
	return (ft_strrev(hex));
}
