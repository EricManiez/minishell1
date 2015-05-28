/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_getwc.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emaniez <emaniez@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/10 14:56:52 by emaniez           #+#    #+#             */
/*   Updated: 2015/03/10 18:02:36 by emaniez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

void	pwc_conv_2bytes(unsigned int v, unsigned int mask1)
{
	char	o1;
	char	o2;
	char	octet;

	o1 = ((v >> 6) << 27) >> 27;
	o2 = (v << 26) >> 26;
	octet = (mask1 >> 8) | o1;
	write(1, &octet, 1);
	octet = ((mask1 << 24) >> 24) | o2;
	write(1, &octet, 1);
}

void	pwc_conv_3bytes(unsigned int v, unsigned int mask2)
{
	char	o3;
	char	o2;
	char	o1;
	char	octet;

	o3 = (v << 26) >> 26;
	o2 = ((v >> 6) << 26) >> 26;
	o1 = ((v >> 12) << 28) >> 28;
	octet = (mask2 >> 16) | o1;
	write(1, &octet, 1);
	octet = ((mask2 << 16) >> 24) | o2;
	write(1, &octet, 1);
	octet = ((mask2 << 24) >> 24) | o3;
	write(1, &octet, 1);
}

void	pwc_conv_4bytes(unsigned int v, unsigned int mask3)
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
	write(1, &octet, 1);
	octet = ((mask3 << 8) >> 24) | o2;
	write(1, &octet, 1);
	octet = ((mask3 << 16) >> 24) | o3;
	write(1, &octet, 1);
	octet = ((mask3 << 24) >> 24) | o4;
	write(1, &octet, 1);
}

void	ft_putwchar(wchar_t c)
{
	unsigned int	mask1;
	unsigned int	mask2;
	unsigned int	mask3;
	unsigned int	v;

	mask1 = 49280;
	mask2 = 14712960;
	mask3 = 4034953344;
	v = c;
	if (c < 128)
		ft_putchar(c);
	else if (c < 256)
		pwc_conv_2bytes(v, mask1);
	else if (c < 65535)
		pwc_conv_3bytes(v, mask2);
	else
		pwc_conv_4bytes(v, mask3);
}
