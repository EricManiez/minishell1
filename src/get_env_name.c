/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_env_name.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emaniez <emaniez@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/19 09:33:26 by emaniez           #+#    #+#             */
/*   Updated: 2015/03/19 10:15:55 by emaniez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_sh.h>

char	*get_env_name(char **envp, int i)
{
	char	*var;
	int		j;

	var = ft_memalloc(1);
	j = -1;
	while (envp[i][++j] != '=')
		var = ft_charjoin_f(&var, envp[i][j]);
	return (var);
}
