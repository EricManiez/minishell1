/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtins.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emaniez <emaniez@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/18 15:40:12 by emaniez           #+#    #+#             */
/*   Updated: 2015/03/19 18:21:36 by emaniez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_sh.h>

int		builtins(char **cmd, t_lst *env)
{
	void	(*bifunp[PWD + 1])(char **cmd, t_lst *env);
	char	*arr[PWD + 1];
	int		i;

	bifunp[ENV] = &sh_env;
	bifunp[SETENV] = &sh_setenv;
	bifunp[UNSETENV] = &sh_unsetenv;
	bifunp[CD] = &sh_cd;
	bifunp[PWD] = &sh_pwd;
	arr[ENV] = "env";
	arr[SETENV] = "setenv";
	arr[UNSETENV] = "unsetenv";
	arr[CD] = "cd";
	arr[PWD] = "pwd";
	i = -1;
	while (++i <= PWD)
	{
		if (ft_strequ(*cmd, arr[i]))
		{
			bifunp[i](cmd, env);
			return (1);
		}
	}
	return (0);
}
