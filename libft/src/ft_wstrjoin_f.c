/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_wstrjoin_f.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emaniez <emaniez@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/10 16:19:10 by emaniez           #+#    #+#             */
/*   Updated: 2015/03/10 16:23:58 by emaniez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

char	*ft_wstrjoin_f(char **dst, wchar_t *src)
{
	int	i;

	i = -1;
	while (src[++i])
		*dst = ft_wcharjoin_f(dst, src[i]);
	return (*dst);
}
