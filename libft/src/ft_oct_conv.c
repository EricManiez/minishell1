/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_oct_conv.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emaniez <emaniez@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/06 10:52:08 by emaniez           #+#    #+#             */
/*   Updated: 2015/03/10 11:52:04 by emaniez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char				*ft_oct_conv(unsigned long int dec, int lead_0)
{
	unsigned long	mid;
	char			*oct;
	char			*tmp;

	oct = ft_memalloc(1);
	if (dec == 0)
		return (ft_strdup("0"));
	while (dec)
	{
		mid = dec % 8;
		tmp = ft_itoa(mid);
		oct = ft_strjoin_fb(&oct, &tmp);
		dec /= 8;
	}
	if (lead_0)
		oct = ft_charjoin_f(&oct, '0');
	return (ft_strrev(oct));
}
