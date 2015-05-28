/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emaniez <emaniez@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/11 18:19:26 by emaniez           #+#    #+#             */
/*   Updated: 2015/03/23 10:45:31 by emaniez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_sh.h>

pid_t	g_killnet;

char	**empty_env(void)
{
	char	**envp;
	char	*dir;

	dir = (char*)malloc(MAXPATHLEN);
	dir = getcwd(dir, MAXPATHLEN);
	envp = (char**)malloc(sizeof(char*) * 3);
	envp[0] = ft_strdup("PATH=/usr/bin");
	envp[1] = ft_retprintf("PWD=%s", dir);
	envp[2] = 0;
	ft_strdel(&dir);
	return (envp);
}

int		main(int ac, char **av, char **envp)
{
	char	*line;
	t_lst	**hash_t;
	int		ret;

	sig_loop();
	(void)ac;
	hash_t = build_hash_table(envp);
	if (!envp[0])
		envp = empty_env();
	prompt(0);
	while ((ret = get_next_line(0, &line)) > 0)
	{
		if (!i_command_you(line, hash_t, av, &envp))
			break ;
		prompt(0);
	}
	if (ret == 0)
		ft_printf("exit\n");
	ft_hash_free(hash_t);
	return (1);
}
