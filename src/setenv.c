/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   setenv.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emaniez <emaniez@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/18 16:12:59 by emaniez           #+#    #+#             */
/*   Updated: 2015/03/23 10:57:05 by emaniez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_sh.h>

int		check_4_var(char *cmd, t_lst *env)
{
	char	*name;
	int		num;
	t_node	*tr;

	num = ft_atoi(cmd);
	tr = env->head;
	while (tr)
	{
		name = tr->content;
		if (ft_strequ(name, cmd) || (int)tr->content_size == num)
			return (1);
		tr = tr->next;
	}
	return (0);
}

void	sh_setenv(char **cmd, t_lst *env)
{
	int		ac;

	ac = ft_arrlen(cmd);
	if (ac != 3)
	{
		if (ac > 3)
			ft_printf("%s: Too many arguments\n", cmd[0]);
		else if (ac < 3)
			ft_printf("%s: Too few arguments\n", cmd[0]);
		return ;
	}
	if (ac == 1)
		sh_env(cmd, env);
	else if (check_4_var(cmd[1], env))
		replace_env_var(cmd[1], cmd[2], env);
	else
		ft_lst_push(env, ft_strdup(cmd[1]),
				env->tail->content_size + 1, cmd[2]);
}
