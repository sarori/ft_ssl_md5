/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   type_per.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sapark <sapark@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/31 02:13:00 by sapark            #+#    #+#             */
/*   Updated: 2019/09/04 00:24:00 by sapark           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	type_per(va_list *ap, t_pf *pf)
{
	char	per;
	char	*res;
	int		len;
	int		i;

	per = (char)va_arg(*ap, int);
	len = pf->set.width > 1 ? pf->set.width : 1;
	res = ft_memalloc_chr(len, ' ');
	i = 0;
	res[len] = '\0';
	if (pf->set.minus)
		res[i] = '%';
	else
	{
		if (pf->set.zero)
		{
			while (len - 1 > i)
				res[i++] = '0';
		}
		res[len - 1] = '%';
	}
	insertnode(pf, res);
	pf->res = ft_strjoinfree(pf->res, res, 1);
	free(res);
}
