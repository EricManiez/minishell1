/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cd.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emaniez <emaniez@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/18 16:10:39 by emaniez           #+#    #+#             */
/*   Updated: 2015/03/20 10:25:39 by emaniez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_sh.h>

void	set_redir(char *envar, char *dir, t_lst *env)
{
	char	**tmp;

	tmp = (char**)malloc(sizeof(char*) * 4);
	tmp[0] = ft_strdup("setenv");
	tmp[1] = ft_strdup(envar);
	tmp[2] = dir;
	tmp[3] = 0;
	sh_setenv(tmp, env);
	ft_free_str_arr(tmp, 4);
}

void	home(t_lst *env)
{
	char	**tmp;

	tmp = (char**)malloc(sizeof(char*) * 3);
	tmp[0] = ft_strdup("cd");
	tmp[1] = get_env_var_lst("HOME", env);
	tmp[2] = 0;
	sh_cd(tmp, env);
	ft_free_str_arr(tmp, 3);
}

void	backwards(t_lst *env)
{
	char	**tmp;

	tmp = (char**)malloc(sizeof(char*) * 3);
	tmp[0] = ft_strdup("cd");
	tmp[1] = get_env_var_lst("OLDPWD", env);
	tmp[2] = 0;
	sh_cd(tmp, env);
	ft_free_str_arr(tmp, 2);
}

void	sh_cd(char **cmd, t_lst *env)
{
	char	*dir;
	int		ac;

	ac = ft_arrlen(cmd);
	dir = (char*)malloc(MAXPATHLEN);
	dir = getcwd(dir, MAXPATHLEN);
	if (ac > 3)
		ft_printf("%s: too many arguments\n", cmd[0]);
	else if (ac > 2 && !ft_strequ(cmd[1], cmd[2]))
		ft_printf("%s: string not in pwd: %s\n", cmd[0], cmd[1]);
	else if (ac == 1 || ft_strequ(cmd[1], "~"))
		home(env);
	else if (ft_strequ(cmd[1], "-"))
		backwards(env);
	else if (chdir(cmd[1]))
		ft_printf("%s: no such file or directory: %s\n", cmd[0], cmd[1]);
	else
	{
		set_redir("OLDPWD", dir, env);
		dir = (char*)malloc(MAXPATHLEN);
		dir = getcwd(dir, MAXPATHLEN);
		set_redir("PWD", dir, env);
	}
}
