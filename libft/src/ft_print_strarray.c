/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_strarray.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emaniez <emaniez@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/04 13:59:17 by emaniez           #+#    #+#             */
/*   Updated: 2015/03/06 10:52:59 by emaniez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** Pretty straightforward : prints a string array, each string being separated
** by either a space (0) or new line (1);
*/

#include "libft.h"

void	ft_print_strarray(char **a, int newline)
{
	int	i;

	i = -1;
	if (!a || !a[0])
	{
		ft_putchar('\n');
		return ;
	}
	while (a[++i])
	{
		if (!newline)
		{
			ft_putstr(a[i]);
			ft_putchar(' ');
		}
		else
			ft_putendl(a[i]);
	}
	if (!newline)
		ft_putchar('\n');
}
