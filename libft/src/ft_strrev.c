/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrev.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emaniez <emaniez@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/15 15:17:12 by emaniez           #+#    #+#             */
/*   Updated: 2015/03/10 13:39:12 by emaniez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ft_strrev(char *s)
{
	int		i;
	char	*res;

	res = ft_strdup(s);
	i = -1;
	while (++i < (int)ft_strlen(s))
		res[i] = s[ft_strlen(s) - 1 - i];
	res[i] = '\0';
	return (res);
}
