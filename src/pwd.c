/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pwd.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emaniez <emaniez@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/18 16:12:53 by emaniez           #+#    #+#             */
/*   Updated: 2015/03/19 16:14:04 by emaniez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_sh.h>

void	sh_pwd(char **cmd, t_lst *env)
{
	char	*dir;

	(void)cmd;
	(void)env;
	dir = (char*)malloc(MAXPATHLEN);
	dir = getcwd(dir, MAXPATHLEN);
	ft_printf("%s\n", dir);
	ft_strdel(&dir);
}
