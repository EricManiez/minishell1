/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   copy_env.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emaniez <emaniez@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/19 09:30:01 by emaniez           #+#    #+#             */
/*   Updated: 2015/03/20 10:08:42 by emaniez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_sh.h>

t_lst	*copy_env(char **envp)
{
	t_lst	*env;
	int		i;
	char	*tmp;

	if (!envp)
		return (0);
	tmp = get_env_name(envp, 0);
	env = ft_lst_init(tmp, 1, get_env_var(tmp, envp));
	i = 0;
	while (envp[++i])
	{
		tmp = get_env_name(envp, i);
		ft_lst_push(env, tmp, i + 1, get_env_var(tmp, envp));
	}
	return (env);
}
