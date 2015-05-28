/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sh.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emaniez <emaniez@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/11 16:35:22 by emaniez           #+#    #+#             */
/*   Updated: 2015/03/23 10:42:47 by emaniez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_SH_H
# define FT_SH_H

# include <dirent.h>
# include <sys/stat.h>
# include <fcntl.h>
# include <sys/wait.h>
# include <sys/param.h>
# include <signal.h>
# include <libft.h>
# include <ft_hash.h>

enum	e_builtins
{
	ENV,
	SETENV,
	UNSETENV,
	CD,
	PWD
};

void	sig_loop(void);

void	prompt(int sig);

char	*get_env_var(char *var, char **envp);

char	*get_env_var_lst(char *var, t_lst *env);

char	*get_env_name(char **envp, int i);

int		i_command_you(char *line, t_lst **hash_t, char **av, char ***envp);

int		command_treatment(char **cmd, t_lst **hash_t, char **av, char ***envp);

char	**find_path(char **envp);

t_lst	**build_hash_table(char **envp);

void	search_execs(char *dir, t_lst **hash_t);

void	populate_table(char *dir, char *key, t_lst **hash_t);

int		builtins(char **cmd, t_lst *env);

void	sh_cd(char **cmd, t_lst *env);

void	sh_pwd(char **cmd, t_lst *env);

void	sh_env(char **cmd, t_lst *env);

void	sh_setenv(char **cmd, t_lst *env);

void	sh_unsetenv(char **cmd, t_lst *env);

void	replace_env_var(char *var, char *new, t_lst *env);

t_lst	*copy_env(char **envp);

char	**conv_env_arr(t_lst *env);

#endif
