/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   unsetenv.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emaniez <emaniez@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/18 16:12:40 by emaniez           #+#    #+#             */
/*   Updated: 2015/03/19 17:00:51 by emaniez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_sh.h>

void	adjust_size(t_node *tr, int i)
{
	while (tr)
	{
		tr->content_size = i++;
		tr = tr->next;
	}
}

void	inner_loop(char *cmd, t_node *tr, t_lst *env, int num)
{
	int	i;

	i = 0;
	while (tr)
	{
		i++;
		if (ft_strequ(cmd, tr->content) || num == (int)tr->content_size)
		{
			if (!tr->next)
				ft_lst_pop(env);
			else if (!tr->prev)
				ft_lst_toppop(env);
			else
				ft_lst_del_node(tr);
			adjust_size(tr->next, i);
			break ;
		}
		tr = tr->next;
	}
}

void	sh_unsetenv(char **cmd, t_lst *env)
{
	t_node	*tr;
	int		num;
	int		j;

	j = 0;
	while (cmd[++j])
	{
		num = ft_atoi(cmd[j]);
		tr = env->head;
		inner_loop(cmd[j], tr, env, num);
	}
}
