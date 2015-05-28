/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_wcharlen.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emaniez <emaniez@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/10 17:19:02 by emaniez           #+#    #+#             */
/*   Updated: 2015/03/10 17:23:17 by emaniez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

size_t	ft_wcharlen(wchar_t c)
{
	char	*s;
	size_t	len;

	s = ft_memalloc(1);
	s = ft_wcharjoin_f(&s, c);
	len = ft_strlen(s);
	ft_strdel(&s);
	return (len);
}
