/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   command_treatment.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emaniez <emaniez@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/13 17:40:29 by emaniez           #+#    #+#             */
/*   Updated: 2015/03/23 09:09:58 by emaniez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_sh.h>

extern pid_t g_killnet;

void	fork_sub(char **cmd, t_node *ret, char **envp)
{
	pid_t	mom;

	mom = fork();
	g_killnet = mom;
	if (mom > 0)
	{
		wait(&mom);
		return ;
	}
	if (mom == 0)
		execve(ret->content, cmd, envp);
}

int		direct_path(char **cmd, char **envp, char **av)
{
	pid_t		mom;
	struct stat	*info;

	info = (struct stat*)malloc(sizeof(struct stat));
	if (!stat(*cmd, info))
	{
		if (access(*cmd, X_OK))
		{
			ft_printf("%s: permission denied: %s\n", av[0], *cmd);
			free(info);
			return (1);
		}
		mom = fork();
		g_killnet = mom;
		if (mom > 0)
		{
			wait(&mom);
			free(info);
			return (1);
		}
		if (mom == 0)
			execve(*cmd, cmd, envp);
	}
	free(info);
	return (0);
}

int		hash_path(char **cmd, char ***envp, t_lst **hash_t)
{
	t_lst	*lst;
	t_node	*ret;

	lst = hash_t[ft_hash_char_cumul31(*cmd, TABLE_SIZE)];
	if (lst)
	{
		ret = lst->head;
		while (ret && !ft_strequ(ret->key, *cmd))
			ret = ret->next;
		if (!ret)
			return (0);
		fork_sub(cmd, ret, *envp);
		return (1);
	}
	return (0);
}

int		command_treatment(char **cmd, t_lst **hash_t, char **av, char ***envp)
{
	t_lst	*env;

	env = copy_env(*envp);
	if (builtins(cmd, env))
	{
		*envp = conv_env_arr(env);
		return (1);
	}
	if (ft_strequ(*cmd, "exit"))
		return (0);
	if (hash_path(cmd, envp, hash_t))
		;
	else if (direct_path(cmd, *envp, av))
		;
	else
		ft_printf("%s: command not found: %s\n", av[0] + 2, *cmd);
	return (1);
}
