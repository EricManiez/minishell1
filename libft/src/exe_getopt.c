/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exe_getopt.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emaniez <emaniez@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/03 13:58:11 by emaniez           #+#    #+#             */
/*   Updated: 2015/03/03 15:36:44 by emaniez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** A practical tool to implement you can use to intagrate simple option
** management in your programs.
*/
/*
** Arguments are the main argument string ("av"), a pointer towards an
** incrementer ("i") used to keep track of the first post-option argument, and a
** string containing authorized options ("authorized");
*/
/*
** Function returns a string containing all option characters found in input.
*/

void	puterr(char err, char *exe, char *authorized)
{
	ft_printf("%s: illegal option -- %c\n", exe, err);
	ft_printf("usage: %s [-%s] [...]\n", exe, authorized);
	exit (1);
}

char	*exe_getopt(char **av, int *i, char *authorized)
{
	char	c;
	char	*optopt;
	char	*opt;

	optopt = NULL;
	opt = ft_memalloc(1);
	while ((c = ft_simple_getopt((const char **)av,
					authorized, &optopt, i)) != -1)
	{
		if (c == '?')
			puterr(*optopt, av[0], authorized);
		opt = ft_charjoin_f(&opt, c);
	}
	return (opt);
}
