/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   setting.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sapark <sapark@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/31 02:12:32 by sapark            #+#    #+#             */
/*   Updated: 2019/09/06 23:23:29 by sapark           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	flag_setting(char *input, int *i, t_pf *pf)
{
	if (input[*i] == '-')
		pf->set.minus = 1;
	else if (input[*i] == '+')
		pf->set.plus = 1;
	else if (input[*i] == ' ')
		pf->set.space = 1;
	else if (input[*i] == '#')
		pf->set.hash = 1;
	else if (input[*i] == '0')
		pf->set.zero = 1;
}

void	widprec_setting(char *input, int *i, t_pf *pf)
{
	if (pf->set.dot)
	{
		if (pf->set.precision == 0)
			pf->set.precision = (input[*i] - '0');
		else
			pf->set.precision = pf->set.precision * 10 + (input[*i] - '0');
	}
	else
	{
		if (pf->set.width == 0)
			pf->set.width = (input[*i] - '0');
		else
			pf->set.width = pf->set.width * 10 + (input[*i] - '0');
	}
}

void	length_setting(char *input, int *i, t_pf *pf)
{
	if (input[*i] == 'l')
	{
		if (pf->set.length_l == 1)
		{
			pf->set.length_ll = 1;
			pf->set.length_l = 0;
		}
		else
			pf->set.length_l = 1;
	}
	else if (input[*i] == 'h')
	{
		if (pf->set.length_h == 1)
		{
			pf->set.length_hh = 1;
			pf->set.length_h = 0;
		}
		else
			pf->set.length_h = 1;
	}
	else if (input[*i] == 'L')
		pf->set.length_large = 1;
}

void	star_setting(va_list *ap, t_pf *pf)
{
	if (pf->set.dot)
		pf->set.precision = (int)va_arg(*ap, int);
	else
		pf->set.width = (int)va_arg(*ap, int);
}
