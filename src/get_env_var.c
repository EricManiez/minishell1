/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_env_var.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emaniez <emaniez@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/18 17:57:12 by emaniez           #+#    #+#             */
/*   Updated: 2015/03/19 17:00:01 by emaniez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_sh.h>

char	*get_env_var_lst(char *var, t_lst *env)
{
	t_node	*tr;

	tr = env->head;
	while (tr)
	{
		if (ft_strequ(var, tr->content))
			return (ft_strdup(tr->key));
		tr = tr->next;
	}
	return (0);
}

char	*get_env_var(char *var, char **envp)
{
	char	*tmp;

	if (!var || !*var)
		return (NULL);
	while (*envp)
	{
		tmp = get_env_name(envp, 0);
		if (ft_strequ(tmp, var))
		{
			ft_strdel(&tmp);
			tmp = ft_strdup(*envp + ft_strlen(var) + 1);
			return (tmp);
		}
		ft_strdel(&tmp);
		envp++;
	}
	return (NULL);
}
