/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_getwc.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emaniez <emaniez@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/10 14:56:52 by emaniez           #+#    #+#             */
/*   Updated: 2015/03/10 17:58:11 by emaniez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

void	conv_2bytes(unsigned int v, unsigned int mask1, const char *s)
{
	char	o1;
	char	o2;
	char	octet;

	o1 = ((v >> 6) << 27) >> 27;
	o2 = (v << 26) >> 26;
	octet = (mask1 >> 8) | o1;
	s = ft_charjoin(s, octet);
	octet = ((mask1 << 24) >> 24) | o2;
	s = ft_charjoin(s, octet);
}

void	conv_3bytes(unsigned int v, unsigned int mask2, const char *s)
{
	char	o3;
	char	o2;
	char	o1;
	char	octet;

	o3 = (v << 26) >> 26;
	o2 = ((v >> 6) << 26) >> 26;
	o1 = ((v >> 12) << 28) >> 28;
	octet = (mask2 >> 16) | o1;
	s = ft_charjoin(s, octet);
	octet = ((mask2 << 16) >> 24) | o2;
	s = ft_charjoin(s, octet);
	octet = ((mask2 << 24) >> 24) | o3;
	s = ft_charjoin(s, octet);
}

void	conv_4bytes(unsigned int v, unsigned int mask3, const char *s)
{
	char	o4;
	char	o3;
	char	o2;
	char	o1;
	char	octet;

	o4 = (v << 26) >> 26;
	o3 = ((v >> 6) << 26) >> 26;
	o2 = ((v >> 12) << 26) >> 26;
	o1 = ((v >> 18) << 29) >> 29;
	octet = (mask3 >> 24) | o1;
	s = ft_charjoin(s, octet);
	octet = ((mask3 << 8) >> 24) | o2;
	s = ft_charjoin(s, octet);
	octet = ((mask3 << 16) >> 24) | o3;
	s = ft_charjoin(s, octet);
	octet = ((mask3 << 24) >> 24) | o4;
	s = ft_charjoin(s, octet);
}

char	*ft_wcharjoin(char const *s, wchar_t const c)
{
	unsigned int	mask1;
	unsigned int	mask2;
	unsigned int	mask3;
	unsigned int	v;

	v = c;
	mask1 = 49280;
	mask2 = 14712960;
	mask3 = 4034953344;
	if (c < 128)
		s = ft_charjoin(s, c);
	else if (c < 256)
		conv_2bytes(v, mask1, s);
	else if (c < 65535)
		conv_3bytes(v, mask2, s);
	else
		conv_4bytes(v, mask3, s);
	return ((char*)s);
}
