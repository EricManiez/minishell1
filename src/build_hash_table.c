/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   build_hash_table.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emaniez <emaniez@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/16 10:41:47 by emaniez           #+#    #+#             */
/*   Updated: 2015/03/23 09:28:45 by emaniez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_sh.h>

t_lst	**build_hash_table(char **envp)
{
	t_lst	**hash_t;
	char	**path;

	path = find_path(envp);
	hash_t = (t_lst**)malloc(sizeof(t_lst*) * TABLE_SIZE);
	while (*path)
		search_execs(*path++, hash_t);
	return (hash_t);
}
