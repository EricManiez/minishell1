/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_getwc.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emaniez <emaniez@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/10 14:56:52 by emaniez           #+#    #+#             */
/*   Updated: 2015/03/10 17:55:39 by emaniez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

void	jf_conv_2bytes(unsigned int v, unsigned int mask1, char **s)
{
	char	o1;
	char	o2;
	char	octet;

	o1 = ((v >> 6) << 27) >> 27;
	o2 = (v << 26) >> 26;
	octet = (mask1 >> 8) | o1;
	*s = ft_charjoin_f(s, octet);
	octet = ((mask1 << 24) >> 24) | o2;
	*s = ft_charjoin_f(s, octet);
}

void	jf_conv_3bytes(unsigned int v, unsigned int mask2, char **s)
{
	char	o1;
	char	o2;
	char	o3;
	char	octet;

	o1 = ((v >> 12) << 28) >> 28;
	o2 = ((v >> 6) << 26) >> 26;
	o3 = (v << 26) >> 26;
	octet = (mask2 >> 16) | o1;
	*s = ft_charjoin_f(s, octet);
	octet = ((mask2 << 16) >> 24) | o2;
	*s = ft_charjoin_f(s, octet);
	octet = ((mask2 << 24) >> 24) | o3;
	*s = ft_charjoin_f(s, octet);
}

void	jf_conv_4bytes(unsigned int v, unsigned int mask3, char **s)
{
	char	o1;
	char	o2;
	char	o3;
	char	o4;
	char	octet;

	o1 = ((v >> 18) << 29) >> 29;
	o2 = ((v >> 12) << 26) >> 26;
	o3 = ((v >> 6) << 26) >> 26;
	o4 = (v << 26) >> 26;
	octet = (mask3 >> 24) | o1;
	*s = ft_charjoin_f(s, octet);
	octet = ((mask3 << 8) >> 24) | o2;
	*s = ft_charjoin_f(s, octet);
	octet = ((mask3 << 16) >> 24) | o3;
	*s = ft_charjoin_f(s, octet);
	octet = ((mask3 << 24) >> 24) | o4;
	*s = ft_charjoin_f(s, octet);
}

char	*ft_wcharjoin_f(char **s, wchar_t const c)
{
	unsigned int	mask1;
	unsigned int	mask2;
	unsigned int	mask3;
	unsigned int	v;

	v = c;
	mask1 = 49280;
	mask2 = 14712960;
	mask3 = 4034953344;
	if (c < 0xFF)
		*s = ft_charjoin_f(s, c);
	else if (c < 0xFFF)
		jf_conv_2bytes(v, mask1, s);
	else if (c < 0xFFFF)
		jf_conv_3bytes(v, mask2, s);
	else
		jf_conv_4bytes(v, mask3, s);
	return (*s);
}
