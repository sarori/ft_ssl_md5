/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sapark <sapark@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/31 02:38:44 by sapark            #+#    #+#             */
/*   Updated: 2019/09/07 03:44:38 by sapark           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

t_typedt	g_set_dt[] =
{
	{'c', type_c},
	{'s', type_s},
	{'p', type_p},
	{'d', type_d},
	{'i', type_i},
	{'o', type_o},
	{'u', type_u},
	{'x', type_x},
	{'X', type_largex},
	{'f', type_f},
	{'%', type_per},
	{'b', type_b},
	{'n', type_len}
};

int			ft_printf(char *str, ...)
{
	int		i;
	int		cnt;
	va_list	ap;
	t_pf	*pf;
	int		ret;

	pf = ft_memalloc(sizeof(t_pf));
	i = 0;
	cnt = 0;
	va_start(ap, str);
	while (str[i])
	{
		if (str[i] == '%')
			setting(str, &i, &ap, pf);
		else
			pf->res = ft_scjoin(pf->res, str[i], 1);
		i++;
	}
	va_end(ap);
	ft_putstr(pf->res);
	ret = (int)ft_strlen(pf->res) - pf->minus;
	free(pf->res);
	free(pf);
	return (ret);
}

int			ft_dprintf(int fd, char *str, ...)
{
	int		i;
	int		cnt;
	va_list	ap;
	t_pf	*pf;
	int		ret;

	pf = ft_memalloc(sizeof(t_pf));
	i = 0;
	cnt = 0;
	va_start(ap, str);
	while (str[i])
	{
		if (str[i] == '%')
			setting(str, &i, &ap, pf);
		else
			pf->res = ft_scjoin(pf->res, str[i], 1);
		i++;
	}
	va_end(ap);
	ft_putstr_fd(pf->res, fd);
	ret = (int)ft_strlen(pf->res) - pf->minus;
	free(pf->res);
	free(pf);
	return (ret);
}

int			ft_sprintf(char *buffer, char *str, ...)
{
	int		i;
	int		cnt;
	va_list	ap;
	t_pf	*pf;
	int		ret;

	pf = ft_memalloc(sizeof(t_pf));
	i = 0;
	cnt = 0;
	va_start(ap, str);
	while (str[i])
	{
		if (str[i] == '%')
			setting(str, &i, &ap, pf);
		else
			pf->res = ft_scjoin(pf->res, str[i], 1);
		i++;
	}
	va_end(ap);
	buffer = ft_strdup(pf->res);
	ret = (int)ft_strlen(pf->res) - pf->minus;
	ft_putstr(pf->res);
	free(pf->res);
	free(pf);
	return (ret);
}

void		oper_func(int idx, va_list *ap, t_pf *pf)
{
	if (idx >= 0)
		g_set_dt[idx].f(ap, pf);
}

int			setting(char *input, int *i, va_list *ap, t_pf *pf)
{
	int	idx;

	idx = -1;
	pf->set = (t_flag_lst){0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
	while (input[*i] && input[*i + 1])
	{
		*i += 1;
		if ((input[*i] == '-' || input[*i] == '+' || input[*i] == ' ' ||
		input[*i] == '#' || input[*i] == '0') && !pf->set.width && !pf->set.dot)
			flag_setting(input, i, pf);
		else if (input[*i] >= '0' && input[*i] <= '9')
			widprec_setting(input, i, pf);
		else if (input[*i] == '.')
			pf->set.dot = 1;
		else if (input[*i] == '*')
			star_setting(ap, pf);
		else if (input[*i] == 'l' || input[*i] == 'h' || input[*i] == 'L')
			length_setting(input, i, pf);
		else if ((idx = ft_strchr_idx(SPECIFIER, input[*i])) >= 0)
			break ;
		else
			return (0);
	}
	oper_func(idx, ap, pf);
	return (0);
}
