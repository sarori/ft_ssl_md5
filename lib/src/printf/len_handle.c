/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   len_handle.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sapark <sapark@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/31 01:58:31 by sapark            #+#    #+#             */
/*   Updated: 2019/08/31 15:23:04 by sapark           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int64_t		get_arg_di(va_list *ap, t_pf *pf)
{
	if (pf->set.length_ll)
		return ((long long)va_arg(*ap, long long));
	else if (pf->set.length_l)
		return ((long)va_arg(*ap, long));
	else if (pf->set.length_h)
		return ((short)va_arg(*ap, int));
	else if (pf->set.length_hh)
		return ((signed char)va_arg(*ap, int));
	else
		return ((int)va_arg(*ap, int));
}

u_int64_t	get_arg_uoxx(va_list *ap, t_pf *pf)
{
	if (pf->set.length_ll)
		return ((unsigned long long)va_arg(*ap, unsigned long long));
	else if (pf->set.length_l)
		return ((unsigned long)va_arg(*ap, unsigned long));
	else if (pf->set.length_h)
		return ((unsigned short)va_arg(*ap, unsigned int));
	else if (pf->set.length_hh)
		return ((unsigned char)va_arg(*ap, unsigned int));
	else
		return ((unsigned int)va_arg(*ap, unsigned int));
}

long double	get_arg_f(va_list *ap, t_pf *pf)
{
	if (pf->set.length_large)
		return ((long double)va_arg(*ap, long double));
	else
		return ((double)va_arg(*ap, double));
}
