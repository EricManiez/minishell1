/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsub.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emaniez <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/06 10:35:15 by emaniez           #+#    #+#             */
/*   Updated: 2015/03/10 19:30:08 by emaniez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_wstrsub(wchar_t const *s, unsigned int start, size_t len)
{
	unsigned int		j;
	char				*sub;

	j = -1;
	sub = ft_memalloc(1);
	while (++j < len)
		sub = ft_wcharjoin_f(&sub, s[start + j]);
	return (sub);
}
