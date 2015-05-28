/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   con_env_arr.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emaniez <emaniez@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/19 10:27:32 by emaniez           #+#    #+#             */
/*   Updated: 2015/03/19 14:50:28 by emaniez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_sh.h>

char	**conv_env_arr(t_lst *env)
{
	char	**arr;
	t_node	*tr;
	int		i;
	char	*tmp;

	arr = (char**)malloc(sizeof(char*) * env->tail->content_size);
	tr = env->head;
	i = -1;
	while (++i < (int)env->tail->content_size)
	{
		tmp = tr->content;
		arr[i] = ft_retprintf("%s=%s", tmp, tr->key);
		tr = tr->next;
	}
	arr[i] = 0;
	return (arr);
}
