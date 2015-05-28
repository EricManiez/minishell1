/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isnumerical.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emaniez <emaniez@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/04 09:34:48 by emaniez           #+#    #+#             */
/*   Updated: 2015/03/04 09:39:10 by emaniez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

int		ft_isnumerical(char c)
{
	if (ft_isdigit(c) || c == '-' || c == '+')
		return (1);
	return (0);
}