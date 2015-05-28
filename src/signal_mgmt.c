/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   signal_mgmt.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emaniez <emaniez@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/23 09:06:07 by emaniez           #+#    #+#             */
/*   Updated: 2015/03/23 10:45:30 by emaniez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_sh.h>

extern pid_t	g_killnet;

void	prompt(int sig)
{
	char	*dir;

	(void)sig;
	dir = (char*)malloc(MAXPATHLEN);
	dir = getcwd(dir, MAXPATHLEN);
	if (sig > 0)
		write(1, "\n", 1);
	ft_printf("\033[31;1m[megaprompt]\033[0m %s> ", ft_strrchr(dir, '/'));
	ft_strdel(&dir);
}

void	nothing(int sig)
{
	(void)sig;
}

void	murder(int sig)
{
	kill(g_killnet, sig);
	signal(sig, SIG_DFL);
}

void	seg(int sig)
{
	(void)sig;
	ft_printf("That's a segfault, my friend!\n");
	exit(-1);
}

void	sig_loop(void)
{
	int	i;

	i = 0;
	while (++i < 32)
		signal(i, nothing);
	signal(SIGTERM, murder);
	signal(SIGINT, prompt);
	signal(SIGQUIT, prompt);
	signal(SIGSEGV, seg);
}
