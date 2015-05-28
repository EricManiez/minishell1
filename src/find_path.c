/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_path.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emaniez <emaniez@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/13 18:04:02 by emaniez           #+#    #+#             */
/*   Updated: 2015/03/18 19:16:12 by emaniez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_sh.h>

char	**find_path(char **envp)
{
	if (get_env_var("PATH", envp))
		return (ft_strsplit(get_env_var("PATH", envp), ':'));
	return (envp);
}
