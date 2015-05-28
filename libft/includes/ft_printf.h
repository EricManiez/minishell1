/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emaniez <emaniez@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/06 10:48:10 by emaniez           #+#    #+#             */
/*   Updated: 2015/03/13 15:46:29 by emaniez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include <stdio.h>
# include <libft.h>
# include <unistd.h>
# include <stdarg.h>
# include <locale.h>

# define CONV_SPEC "sSpdDioOuUxXcC"
# define PRINTF_CHARS "sSpdDioOuUxXcC#0123456789-+. lzjh"

typedef	struct	s_pf
{
	int		lm;
	int		cs;
	int		caps;
	int		sharp;
	int		zero;
	int		minus;
	int		plus;
	int		sp;
	int		prec;
	int		width;
	int		extra_chars;
	int		len;
	char	*cscpy;
}				t_pf;

typedef enum	e_cs
{
	S,
	P,
	D,
	O,
	U,
	X,
	C
}				t_ls;

typedef enum	e_lm
{
	HH,
	H,
	LL,
	L,
	J,
	Z
}				t_lm;

int				ft_printf(const char *format, ...);

int				pf_read_loop(char **str, va_list ap, char *format);

int				pf_parser(const char *format, char **ret, char **cs, int prog);

int				pf_read_loop(char **str, va_list ap, char *format);

int				pf_typedef(char *cs, char **str, va_list ap);

void			pf_struct_fill(t_pf *arg, char *cs);

void			pf_redirection(char **s, t_pf *arg, va_list ap);

void			pf_css(char **s, t_pf *arg, va_list ap);

void			pf_csp(char **s, t_pf *arg, va_list ap);

/*
** "%d" related
*/

void			pf_csd(char **s, t_pf *arg, va_list ap);

void			pf_dhh(char **s, va_list ap, t_pf *arg);

void			pf_dh(char **s, va_list ap, t_pf *arg);

void			pf_dll(char **s, va_list ap, t_pf *arg);

void			pf_dl(char **s, va_list ap, t_pf *arg);

void			pf_dj(char **s, va_list ap, t_pf *arg);

void			pf_dz(char **s, va_list ap, t_pf *arg);

/*
** "%o" related
*/

void			pf_cso(char **s, t_pf *arg, va_list ap);

void			pf_ohh(char **s, t_pf *arg, va_list ap);

void			pf_oh(char **s, t_pf *arg, va_list ap);

void			pf_oll(char **s, t_pf *arg, va_list ap);

void			pf_ol(char **s, t_pf *arg, va_list ap);

void			pf_oj(char **s, t_pf *arg, va_list ap);

void			pf_oz(char **s, t_pf *arg, va_list ap);

/*
** "%u" related
*/

void			pf_csu(char **s, t_pf *arg, va_list ap);

void			pf_uhh(char **s, va_list ap, t_pf *arg);

void			pf_uh(char **s, va_list ap, t_pf *arg);

void			pf_ull(char **s, va_list ap, t_pf *arg);

void			pf_ul(char **s, va_list ap, t_pf *arg);

void			pf_uj(char **s, va_list ap, t_pf *arg);

void			pf_uz(char **s, va_list ap, t_pf *arg);

/*
** "%x" related
*/

void			pf_csx(char **s, t_pf *arg, va_list ap);

void			pf_xhh(char **s, t_pf *arg, va_list ap);

void			pf_xh(char **s, t_pf *arg, va_list ap);

void			pf_xll(char **s, t_pf *arg, va_list ap);

void			pf_xl(char **s, t_pf *arg, va_list ap);

void			pf_xj(char **s, t_pf *arg, va_list ap);

void			pf_xz(char **s, t_pf *arg, va_list ap);

void			pf_csc(char **s, t_pf *arg, va_list ap);

void			pf_width_mgmt(t_pf *arg, char **s, va_list cpy, int width);

int				pf_sign_print(t_pf *arg, char **s, va_list cpy);

void			pf_pre_print(t_pf *arg, char **s, va_list cpy);

void			pf_string_mgmt(char **s, va_list ap, char *cs);

size_t			pf_len_calc(va_list cpy, t_pf *arg);

size_t			pf_width_parse(char *cs);

int				pf_prec_parse(char *cs);

void			pf_post_print(t_pf *arg, char **s, va_list cpy);

char			*pf_itoa(long long n, int i);

char			*pf_wstrsub(wchar_t const *s, unsigned int start, size_t len);

#endif
