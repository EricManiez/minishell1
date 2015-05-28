/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   search_execs.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emaniez <emaniez@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/16 12:09:41 by emaniez           #+#    #+#             */
/*   Updated: 2015/03/16 19:01:10 by emaniez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_sh.h>

void	search_execs(char *dir, t_lst **hash_t)
{
	DIR				*stream;
	struct dirent	*dp;
	char			*path;

	if ((stream = opendir(dir)))
	{
		dp = (struct dirent*)malloc(sizeof(struct dirent));
		while ((dp = readdir(stream)))
		{
			path = ft_retprintf("%s/%s", dir, dp->d_name);
			if (!access(path, X_OK))
				populate_table(dir, dp->d_name, hash_t);
			ft_strdel(&path);
		}
		free(dp);
		closedir(stream);
	}
}
