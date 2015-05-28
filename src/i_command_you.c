/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   i_command_you.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emaniez <emaniez@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/13 15:31:49 by emaniez           #+#    #+#             */
/*   Updated: 2015/03/20 10:02:48 by emaniez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_sh.h>

int		i_command_you(char *line, t_lst **hash_t, char **av, char ***envp)
{
	char	**cmds;
	char	**single;

	cmds = ft_strsplit(line, ';');
	while (*cmds)
	{
		single = ft_spaces_split(*(cmds++));
		if (!single[0])
			return (1);
		if (!command_treatment(single, hash_t, av, envp))
			return (0);
	}
	return (1);
}
