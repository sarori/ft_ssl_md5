/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sapark <sapark@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/31 01:58:46 by sapark            #+#    #+#             */
/*   Updated: 2019/08/31 16:10:07 by sapark           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*ft_scjoin(char *s1, char c, int mfree)
{
	char			*res;
	unsigned int	len1;
	int				i;

	if (!c)
		return (s1);
	len1 = !s1 ? 0 : ft_strlen(s1);
	if (!(res = (char *)malloc(sizeof(char) * (len1 + 2))))
		return (NULL);
	res[len1 + 1] = '\0';
	i = 0;
	while (s1 && s1[i])
	{
		res[i] = s1[i];
		i++;
	}
	res[i] = c;
	if (s1 && mfree)
		free(s1);
	return (res);
}

char	*ft_strjoinfree(char *s1, char *s2, int mfree)
{
	char			*res;
	unsigned int	len1;
	unsigned int	len2;
	int				i;
	int				j;

	if (!s2)
		return (s1);
	len1 = ft_strlen(s1);
	len2 = ft_strlen(s2);
	if (!(res = (char *)malloc(sizeof(char) * (len1 + len2 + 1))))
		return (NULL);
	res[len1 + len2] = '\0';
	i = 0;
	j = 0;
	while (s1 && s1[i])
	{
		res[i] = s1[i];
		i++;
	}
	while (s2 && s2[j])
		res[i++] = s2[j++];
	if (s1 && mfree)
		free(s1);
	return (res);
}

int		ft_digit_base_u(unsigned long long n, unsigned long long base)
{
	unsigned int	cnt;

	cnt = 0;
	while (n >= base)
	{
		n = n / base;
		cnt++;
	}
	return (cnt + 1);
}

char	*ft_itoa_base_u(unsigned long long value, unsigned long long base)
{
	char			*res;
	char			*str;
	unsigned int	size;
	int				i;

	str = "0123456789abcdef";
	res = NULL;
	if (base >= 2 && base <= 16)
	{
		size = (unsigned int)ft_digit_base_u(value, base);
		if (!(res = (char *)malloc(sizeof(char) * (size + 1))))
			return (NULL);
		i = size - 1;
		while (value >= base)
		{
			res[i--] = str[value % base];
			value /= base;
		}
		res[i] = str[value % base];
		res[size] = '\0';
	}
	return (res);
}
