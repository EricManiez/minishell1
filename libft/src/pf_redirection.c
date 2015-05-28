/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pf_redirection.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emaniez <emaniez@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/06 11:23:07 by emaniez           #+#    #+#             */
/*   Updated: 2015/03/10 18:52:03 by emaniez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_printf.h>

void	pf_redirection(char **s, t_pf *arg, va_list ap)
{
	void	(*pfun[7])(char **s, t_pf *arg, va_list ap);

	pfun[S] = &pf_css;
	pfun[P] = &pf_csp;
	pfun[D] = &pf_csd;
	pfun[O] = &pf_cso;
	pfun[U] = &pf_csu;
	pfun[X] = &pf_csx;
	pfun[C] = &pf_csc;
	if (arg->cs >= 0)
		pfun[arg->cs](s, arg, ap);
	else
		*s = ft_charjoin_f(s, arg->cscpy[ft_strlen(arg->cscpy) - 1]);
}
