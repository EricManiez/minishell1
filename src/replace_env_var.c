/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   replace_env_var.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emaniez <emaniez@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/18 18:42:04 by emaniez           #+#    #+#             */
/*   Updated: 2015/03/19 16:31:50 by emaniez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_sh.h>

void	replace_env_var(char *var, char *new, t_lst *env)
{
	t_node	*tr;
	int		num;

	tr = env->head;
	num = ft_atoi(var);
	while (tr)
	{
		if (ft_strequ(var, tr->content) || (int)tr->content_size == num)
		{
			ft_strdel(&tr->key);
			tr->key = ft_strdup(new);
			return ;
		}
		tr = tr->next;
	}
}
