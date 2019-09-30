/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin_by.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sapark <sapark@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/28 23:54:21 by sapark            #+#    #+#             */
/*   Updated: 2019/09/28 23:55:03 by sapark           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin_by(char const *s1, char const *s2, char *s3)
{
	char *res;

	if (s1 && s2 && s3)
	{
		if (!(res = ft_strnew(ft_strlen(s1) + ft_strlen(s2) + ft_strlen(s3))))
			return (NULL);
		res = ft_strcpy(res, s1);
		res = ft_strcat(res, s3);
		res = ft_strcat(res, s2);
		return (res);
	}
	return (NULL);
}
