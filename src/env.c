/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cd.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emaniez <emaniez@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/18 16:10:39 by emaniez           #+#    #+#             */
/*   Updated: 2015/03/19 15:30:51 by emaniez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_sh.h>

void	fetch_env_var(char *cmd, t_lst *env)
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
		{
			ft_printf("\033[33m%s = \033[36m%s \033[33m[%d]\033[0m\n",
					name, tr->key, tr->content_size);
			return ;
		}
		tr = tr->next;
	}
}

void	print_env(t_lst *env)
{
	t_node	*tr;
	char	*name;

	tr = env->head;
	while (tr)
	{
		name = tr->content;
		ft_printf("\033[33m%s = \033[36m%s \033[33m[%d]\033[0m\n",
				name, tr->key, tr->content_size);
		tr = tr->next;
	}
}

void	sh_env(char **cmd, t_lst *env)
{
	int	ac;

	ac = ft_arrlen(cmd);
	if (ac == 1)
		print_env(env);
	else if (ac == 2)
		fetch_env_var(cmd[1], env);
}
