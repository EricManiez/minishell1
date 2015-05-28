/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsub.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emaniez <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/06 10:35:15 by emaniez           #+#    #+#             */
/*   Updated: 2015/03/10 17:50:53 by emaniez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*pf_wstrsub(wchar_t const *s, unsigned int start, size_t len)
{
	unsigned int		j;
	char				*sub;

	j = -1;
	sub = ft_memalloc(1);
	while (++j < len)
	{
		if (ft_wcharlen(s[start + j]) + ft_strlen(sub) <= len)
			sub = ft_wcharjoin_f(&sub, s[start + j]);
		else
			break ;
	}
	return (sub);
}
